#include "cStack.h"
#include<iostream>
#include<fstream>
using namespace std;

/* Definition of cStack default Constructor*/
cStack::cStack() :top(NULL), count(0) {}

/* Definition of cStack Parametric Constructor*/
cStack::cStack(cNode* ptr)
{
	top->next = NULL;
	ptr = NULL;
	count = 1;
}

/* Confirm the Non-Emptyness of cStack*/
bool cStack::isNotEmpty()const
{
	if (top)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* Confirm the Emptyness of cStack*/
bool cStack::isEmpty()const
{
	if (top) { return false; }
	else { return true; }
}

/*Definition of push function to add new node in stack*/
cStack& cStack::push(cNode* ptr)
{
	ptr->next = top;
	top = ptr;
	ptr = NULL;
	count++;
	return*this;
}

/*Definition of pop function to remove new node from stack*/
cNode* cStack::pop()
{
	cNode* ptr = top;
	top = top->next;
	ptr->next = NULL;
	--count;
	return ptr;
}

/*Print function for printing nodes from cStack*/
void cStack::printStack()const
{
	if (!top) { cout << "Stack Empty" << endl; }
	else {
		cNode* ptr = top;
		while (ptr) {
			ptr->print();
			ptr = ptr->next;
		}
	}
}

/*Definition of Destructor */
cStack::~cStack()
{
	cNode* ptr = top;
	while (ptr) {
		ptr = ptr->next;
		delete top;
		top = ptr;
		count--;
	}
}

/*Definition of copy constructor of cStack to copy stack */
cStack::cStack(const cStack& src)
{
	this->top = src.top;
	if (src.top)
	{
		cNode* sptr, * dptr;
		dptr = top = new cNode(*src.top);
		sptr = src.top->next;
		while (sptr) {
			dptr->next = new cNode(*sptr);
			sptr = sptr->next; dptr = dptr->next;
		}
	}
}

/*Definition of assignment operator to set one stack to another*/
cStack& cStack::operator=(const cStack& robj)
{
	if (this == &robj) {
		return*this;
	}
	if (true) {
		cStack temp; temp.top = top;
	}
	if (true) {
		cStack temp = robj; top = temp.top; 
		temp.top = NULL;
	}return *this;
}

/*Constructor for creating node from file*/
cStack::cStack(ifstream& inFile)
{
	top = NULL;
	count = 0;
	int size;
	inFile.read((char*)& size, sizeof(size));
	if (size > 0)
	{
		cNode* ptr;
		ptr = top = new cNode(inFile);
		count = size;
		for (int i = 1; i < size; ++i)
		{
			ptr->next = new cNode(inFile);
			ptr = ptr->next;
		}
		ptr->next = NULL;
	}
}

/*Function for creating node from file*/
void cStack::writeToFile(ofstream& oFile)
{
	oFile.write((char*)& this->count, sizeof(count));
	if (count > 0)
	{
		cNode* ptr = top;
		for (int i = 0; i < count; ++i)
		{
			ptr->writeToFile(oFile);
			ptr = ptr->next;
		}
	}
}

/*Function for creating node from file*/
void cStack::readFromFile(ifstream& inFile)
{
	if (true)
	{
		cStack temp;
		temp.top = this->top;
	}
	inFile.read((char*)& this->count, sizeof(count));
	if (count > 0)
	{
		cNode* ptr = top = new cNode(inFile);
		for (int i = 1; i < count; ++i)
		{
			ptr->next = new cNode(inFile);
			ptr = ptr->next;
		}
		ptr->next = NULL;
	}
}
