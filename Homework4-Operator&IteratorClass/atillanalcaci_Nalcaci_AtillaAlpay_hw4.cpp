#include <iostream>
#include "linkedlist.h"

using namespace std;

void Options()
{
	cout << "*************************** "<< endl;
	cout <<"* 1. union(+) *"<< endl;
	cout <<"* 2. difference(-) *"<< endl;
	cout <<"* 3. Intersection (&) *"<< endl;
	cout <<"* 4. [] operator *"<< endl;
	cout <<"* 5. Exit *"<< endl;
	cout <<"***************************"<< endl;
}

int main()
{
	linkedlist a;
	linkedlist b;
	string x;
	
	cout << "Enter lesson name: ";
	cin >> x;
	
	string sID;
	string add;
	
	cout << "Enter student ID: " ;
	cin >> sID;
	
	while(sID!="^Z") {
		if(add.find(sID) == string::npos) {
			a.addSorted(sID);
			add += ".." + sID;
		}
		
		else {
			cout << "Already in the list." << endl;
		}
		
		cout << "Enter student ID: " ;
		cin >> sID;
	}
	
	cout << "__LIST1__" << endl;
	a.printList();
	
	string x2;
	cout << "Enter lesson name: ";
	cin >> x2;
	
	string sID2;
	string added = "";
	
	cout << "Enter student ID: " ;
	cin >> sID2;
	
	while(sID2 != "^Z") {
		if(added.find(sID2)==string::npos) {
			b.addSorted(sID2);
			added += ".." + sID2;
		}
		
		else { cout << "already in the list." << endl; }
		
		cout << "Enter student ID: " ;
		cin >> sID2;
	}
	
	cout <<"__LIST2__" << endl;
	b.printList();
	cin.clear();
	Options();
	
	int select;
	cin >> select;
	cout << "**" << endl;
	
	while(select!=5) {
		if(select==1) {
			linkedlist result1;
		    	result1 = a + b;
			result1.printList();
		}
		
		if(select==2) {
			int list;
			cout << "Enter lefthandside list: " << endl;
			cin >> list;
			cout << "selected." << endl;
			
			if(list==1) {
				linkedlist result2_1;
				result2_1 = a - b;
				result2_1.printList();
			}
			
			else
			{
				if (list==2)
				{
					linkedlist result2_2;
					result2_2 = b - a;
					result2_2.printList();
				}
				
				else { cout << "This is not an option." << endl; }
			}
		}
		
		if(select == 3) {
			linkedlist result3;
		    	result3 = a & b;
			result3.printList();
		}
		
		if(select == 4) {
			int ll;
			cout << "Select list: ";
			cin >> ll;
			cout << "selected." << endl;
			
			if(ll == 1) {
				int index;
				cout << "Enter index:" ;
				cin >> index;
				cout << "Index " << index <<" of the list: " << a[index] << endl;
			}
			
			else {
				if(ll == 2) {
					int index2;
					cout << "Enter index:" ;
					cin >> index2;
					cout << "Index " << index2 <<" of the list: " << b[index2] << endl;
				}
				
				else {
					cout <<"Not an option." << endl;
				}
			}
		}
		
		if(select != 1 && select != 3 && select != 4 && select !=2 ) { cout << "Invalid option selected"<<endl; }
		Options();
		cin >> select;
		cout << "**" << endl;
	}
	
	return 0;
}
