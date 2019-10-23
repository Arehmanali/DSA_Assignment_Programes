#include "cQue.h"
#include<iostream>
#include<fstream>
using namespace std;

/* Defalut constructor for default values*/
cQue::cQue()
{
	tail = NULL;
	count = 0;
}

/*Parametric Constructor for adding node*/
cQue::cQue(cNode*& ptr) :cStack(ptr)
{
	tail = top;
	count = 1;
}

/*Check the empty cQue and return true*/
bool cQue::isEmpty()const
{
	return cStack::isEmpty();
}

/*Check the Non-Empty cQue and return true*/
bool cQue::isNotEmpty()const
{
	return cStack::isNotEmpty();
}

/*Add the new node end of cQue class*/
cQue& cQue::Add(cNode*& ptr)
{
	if (tail)
	{
		tail->next = ptr;
		tail = tail->next;
	}
	else
	{
		tail = top = ptr;
	}
	tail->next = NULL;
	ptr = NULL;
	count++;
	return *this;
}

/*Print the all the nodes from cQue*/
void cQue::print()const {
	cStack::printStack();
}

/*Destructor to set the memory free*/
cQue::~cQue() {
	cStack::~cStack();
}

/*Copy Consrutor for copying one cQue to another*/
cQue::cQue(const cQue& src)
{
	this->top = src.top;
	this->tail = src.tail;
	if (src.top)
	{
		cNode* sptr, * dptr;
		dptr = top = new cNode(*src.top);
		sptr = src.top->next;
		count++;
		while (sptr) {
			dptr->next = new cNode(*sptr);
			sptr = sptr->next; dptr = dptr->next;
			count++;
		}
		tail = dptr;
	}
}

/*Assign the cQue to another cQue*/
cQue& cQue::operator =(const cQue& robj)
{
	if (this == &robj) { return *this; }
	if (true)
	{
		cQue temp;
		temp.top = top;
		temp.tail = tail;
		temp.count = count;
	}
	if (true)
	{
		cQue temp = robj;
		top = temp.top;
		tail = temp.tail;
		count = temp.count;
		temp.top = temp.tail = NULL;
	}
	return *this;
}

/*Remove the nodes from the end of cQue*/
cNode* cQue::remove()
{
	if (!top->next)
	{
		tail = NULL;
	}
	count--;
	return cStack::pop();
}

/*Constructor for creating node from file*/
cQue::cQue(ifstream& inFile)
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
		tail = ptr->next;
		ptr->next = NULL;
	}
}

/*Function for creating node from file*/
void cQue::writeToFile(ofstream& oFile)
{
	cStack::writeToFile(oFile);
}

/*Function for creating node to file*/
void cQue::readFromFile(ifstream& inFile)
{
	cStack::readFromFile(inFile);
}

