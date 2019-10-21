#define _VARIADIC_MAX 10
#include <iostream>
#include <string>
#include <thread>
#include <fstream>
#include <mutex>
#include <vector>

using namespace std;

typedef unsigned int uint;


struct transaction 
{
	uint current;
	uint prev;
	uint rand;
	std::thread::id threadID;
	transaction *next;
	transaction *previous;
	transaction()
		:current(0),prev(0),rand(0),threadID(this_thread::get_id()),next(nullptr),previous(nullptr)
	{

	}
	transaction(uint CUR,uint PRE,uint RAN, std::thread::id TID, transaction* PTR1, transaction* PTR2)
		:current(CUR),prev(PRE),rand(RAN),threadID(TID),next(PTR1),previous(PTR2)
	{

	}
};


struct transactionChain 
{
	transaction *head;
	transaction *tail;
	void AddToLast(transaction trans)
	{
		if(head==tail)
		{
			transaction *y=new transaction(trans);
			head->next=y;
			y->previous=head;
			tail=y;
			return;
		}
		transaction *ptr=new transaction(trans);
		transaction *temp=tail;
		temp->next=ptr;
		ptr->previous=temp;
		tail=ptr;
	}

};


uint hashTransaction(transaction tran)
{
	uint result = (tran.current << 16) ^ (tran.prev << 8) ^ (tran.rand << 1);
	std::hash<uint> uint_hash;
	return uint_hash(result);
}

bool transactionValidator(transactionChain &tChain, uint threshold)
{
	transaction *temp = tChain.head->next;
	bool valid = true;

	while (temp != nullptr)
	{
		if (hashTransaction(*temp) > threshold)
			valid = false;

		temp = temp->next;
	}
	return valid;
}

void mine(transactionChain & myTrChain, uint *readarray, uint & howmany, uint limit, mutex *m, uint* MAININTEGER, bool & sign)
{
	
	uint bitcoins = 0; // A private unsigned integer for keeping track of the bitcoins mined by this thread.
	
	srand((hash<thread::id>()(this_thread::get_id())) ^ 2 % 10000); // We should use different seeds for each thread to find different random numbers.
    while(!sign)
	{
		this_thread::yield();
	}
	
	try{
	int upper=howmany;
	while(0<howmany)
	{
		
		transaction t(readarray[upper-howmany],hashTransaction(*myTrChain.tail),rand(),this_thread::get_id(),nullptr,nullptr);
		uint hashing=hashTransaction(t);
		if(hashing<=limit)
		{
			m->lock();
			if(*MAININTEGER+howmany==upper)
			{
				bitcoins++;
				*MAININTEGER=*MAININTEGER + 1;
				myTrChain.AddToLast(t);
				howmany--;
			}
			m->unlock();

		}
	}
	m->lock();
	cout << "Thread " << this_thread::get_id() << " has " << bitcoins << " bitcoin(s)" << endl;
	m->unlock();
	}
	catch(exception e)
	{
		cout << e.what() << endl;
	}

}

void InputTaking(ifstream & ifstr,uint dif, uint & limit, string inputfile,uint & miners)
{
	cout << "Enter difficulty level(between 1-10): ";
	cin >> dif;
	limit=0x80000000>>dif;
	cout <<  limit << "is the threshold."<< endl ;
	cout <<"Enter the filename for input file: " ;
	cin >> inputfile ;
	ifstr.open(inputfile.c_str());
	while(ifstr.fail())
	{
		cout <<"Filename is not valid. Enter the filename for input file: " ;
		cin >> inputfile ;
		ifstr.open(inputfile.c_str());
	}
	cout << "Enter the number of miners: " ;
	cin >> miners;
}



int main()
{
	//variables
	uint dif=0, limit,miners,howmany;
	uint *readarray;
	ifstream ifstr;
	string inputfile;
	bool sign=0;
	vector<thread> jobs;
	mutex *m=new mutex;
	uint* MAININTEGER=new uint;
	*MAININTEGER=0;
	//inputs
	InputTaking(ifstr,dif,limit,inputfile,miners);
	ifstr>>howmany;
	readarray=new uint[howmany];
	int k=0;
	while(ifstr>>readarray[k])
	{
		
		
		k++;
	}
	//Chain creation and thread start
	transactionChain myTrChain;
	transaction* myHead=new transaction();
	myTrChain.head=myHead;
	myTrChain.tail=myTrChain.head;

	for(int j=0;j<miners;j++)
	{

		jobs.push_back(thread(mine,ref(myTrChain),readarray,ref(howmany),limit,m,MAININTEGER,ref(sign)));
	}
	sign=true;
	//thread joins
	for(int k=0;k<miners;k++)
	{
		jobs[k].join();
	}
	if(transactionValidator(myTrChain,limit))
	{
		cout << "Transaction is valid.." << endl;
	}
	else
		cout << "Transaction is not valid.." << endl;
	return 0;
}


