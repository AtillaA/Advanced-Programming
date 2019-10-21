#include <iostream>
#include "linkedlist.h"
using namespace std;

linkedlist:: linkedlist()
{
	head=nullptr;
}
node* linkedlist:: getTail()
{
	node* ptr=head;
	node *tail=head;
	//cout << "ptr" << endl;
	while(ptr!=nullptr)
	{
		//cout <<"intail"<< endl;
		tail=ptr;
		ptr=ptr->next;
	}
	//cout << "tail" << endl;
	return tail;
}
void linkedlist:: printhelper(node* ptr)
{
	cout << ptr->data << endl;
	ptr=ptr->next;
}
void linkedlist:: printList()
{
	if(head==nullptr)
	{
		cout<< "Empty list!" << endl;
		return ;
	}
	node *temp=head;
	while(temp!=nullptr)
	{
		printhelper(temp);
		temp=temp->next;
	}
}
void linkedlist:: add(string n)
{
	if(head==nullptr)
	{
		node* temp=new node(n,nullptr);
		head=temp;
	}
	else
	{
	node* temp=new node(n,nullptr);
	temp->next=head;
	head=temp;
	}
}
void linkedlist:: sort()
{
	
    node *temp=head ;
	node* minIndex;
	node* minIndexstore;
    while(temp!=nullptr)
    {   minIndex = temp;
		minIndexstore=temp;
		node* temp2=temp->next;  
        while(temp2!=nullptr)
        {   if (temp2->data <minIndex->data)
            {   minIndex = temp2;      // new min, store index
            }
		temp2=temp2->next;
        }
		string n;
		n=minIndexstore->data;
		minIndexstore->data=minIndex->data;
		minIndex->data=n;
       temp=temp->next;
	}
}
bool linkedlist:: isEmpty()
{
	if(head==nullptr)
		return true;
	return false;
}
void linkedlist:: addSorted(string n)
{
	add(n);
	sort();
}
bool linkedlist:: found(string n)
{
	if(isEmpty())
		return false;
	node* ptr=head;
	while(ptr!=getTail())
	{
		if(ptr->data==n)
			return true;
		ptr=ptr->next;
	}
	if(getTail()->data==n)
		return true;
	return false;
}

const linkedlist linkedlist:: operator+(linkedlist & rhs)
{
	linkedlist result;
	if(isEmpty()&&rhs.isEmpty())
	{
		return result;
	}
	else if(isEmpty()&&!rhs.isEmpty())
	{
		result=rhs;
		result.sort();
		return result;
	}
	else
	{
		node *ptr1=head;
		while(ptr1!=nullptr)
		{
			result.add(ptr1->data);
			ptr1=ptr1->next;
		}
		if(!rhs.isEmpty())
		{
			node* ptr2=rhs.head;
			while(ptr2!=nullptr)
			{
				if(!result.found(ptr2->data))
				{
					result.add(ptr2->data);
				}
				ptr2=ptr2->next;
			}
			
		}
		result.sort();
		return result;
	}
}
const linkedlist linkedlist::operator-(linkedlist & rhs)
{
	linkedlist result;
	linkedlist rhscr=rhs;
	if(isEmpty() && rhs.isEmpty())
	{
		return result;
	}
	else if(isEmpty() && !rhs.isEmpty())
	{
		return result;
	}
	else 
	{
		node*ptr= head;
		while(ptr!=nullptr)
		{
			if(!rhs.found(ptr->data))
			{
				result.add(ptr->data);
			}
			ptr=ptr->next;
		}
		result.sort();
		return result;
	}

}
node* linkedlist::gethead()
{
	return head;
}
linkedlist operator& ( linkedlist & lhs, linkedlist & rhs)
{
	linkedlist result;
	linkedlist rhscr=rhs;
	if(lhs.isEmpty() && rhs.isEmpty())
	{
		return result;
	}
	else if(lhs.isEmpty() && !rhs.isEmpty())
	{
		return result;
	}
	else 
	{
		node*ptr= lhs.gethead();
		while(ptr!=nullptr)
		{
			if(rhs.found(ptr->data))
			{
				result.add(ptr->data);
			}
			ptr=ptr->next;
		}
		result.sort();
		return result;
	}
}
iteratorll:: iteratorll(linkedlist &list1)
	:list(list1),pointer(list1.head)
{
}
void iteratorll::nextptr()
{
	pointer=pointer->next;
}
bool iteratorll::isEnd()
{
	if(pointer!=nullptr)
		return false;
	return true;
}
string iteratorll::currentptr()
{
	return pointer->data;
}
string linkedlist:: operator[](int k)
{
	if(isEmpty())
	{
		return "Error! this list is empty!";
	}
	if(k<0)
		return "What kind of index is this! Get yourself straight!" ;
	iteratorll itr(*this);
	int t=0;
	while(!itr.isEnd())
	{
		t++;
		itr.nextptr();
	}
	if(k>t)
	{
		cout << "NaN! This integer is beyond the limits" << endl;
		return "error" ;
	}
	iteratorll itr2(*this);
	int c=0;
	while(!itr2.isEnd())
	{
		if(c==k)
			return itr2.currentptr();
		c++;
		itr2.nextptr();
	}
	
}

