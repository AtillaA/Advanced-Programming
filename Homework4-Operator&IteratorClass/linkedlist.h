/*************************************
*Modified by Leyli Javid
*Date: 20.10.2016
*************************************/

#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <string>
using namespace std;

struct node
{
	string data;  // studentID in string
	node *next;

	node::node()
	{}

	node::node(const string &s, node * link)
		: data(s), next(link)
	{}
};

class linkedlist
{
	friend class iteratorll;
private:
	node *head;		//Head node, start of LinkedList

public:
	linkedlist();//Constructor
	void printhelper(node*);
	node* getTail();
	node* gethead();
	bool isEmpty();
	void printList();		    //Prints the given LinkedList from head to end
	void add(string);
	void sort();
	void addSorted(string n);   //Insert a new node such that the list is sorted
	bool found(string);
	const linkedlist operator +(linkedlist & rhs);
	const linkedlist operator -(linkedlist & rhs);
	string operator[](int k);

	
	//overloading operators as member function 
	

};
linkedlist operator &(linkedlist & lhs, linkedlist & rhs);
class iteratorll
{
private:
	linkedlist & list;
	node* pointer;
public:
	iteratorll(linkedlist &);
	void nextptr();
	bool isEnd();
	string currentptr();
};
#endif