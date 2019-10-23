#include "cPriorityQue.h"
#include <iostream>
#include<fstream>
using namespace std;

/* Parametric Constructor*/
cPriorityQue::cPriorityQue(cNode*& ptr) :cQue(ptr) {}

/* Default Constructor*/
cPriorityQue::cPriorityQue() :count(0) {}

/*To add new node at the prioritized position*/
cPriorityQue& cPriorityQue::add(cNode*& ptr)
{
	if (!top)
	{
		top = tail = ptr;
		count++;
		top->next = ptr = NULL;
	}
	else if (top->priority < ptr->priority)
	{
		count++;
		cStack::push(ptr);
	}
	else if (tail->priority >= ptr->priority)
	{
		cQue::Add(ptr);
		count++;
	}
	else
	{
		cNode* rptr = top;
		while (rptr->priority >= ptr->priority)
		{
			rptr = rptr->next;
		}
		ptr->next = rptr->next;
		rptr->next = ptr;
		count++;
		ptr = NULL;
	}
	return *this;

}

/*Copy Constructor of cPriorityQue*/
cPriorityQue::cPriorityQue(const cPriorityQue& src)
{
	this->top = src.top;
	this->tail = src.tail;
	if (src.top)
	{
		cNode* sptr, * dptr;
		dptr = top = new cNode(*src.top);
		sptr = top->next;
		count++;
		while (sptr) {
			dptr->next = new cNode(*sptr);
			sptr = sptr->next; dptr = dptr->next;
			count++;
		}
		tail = dptr;
	}
}

/*Assignment operator of cPriorityQue*/
cPriorityQue& cPriorityQue::operator =(const cPriorityQue& robj)
{
	if (this == &robj)
	{
		return *this;
	}
	if (true)
	{
		cPriorityQue temp;
		temp.top = top;
		temp.tail = tail;
		temp.count = count;
	}
	if (true)
	{
		cPriorityQue temp = robj;
		top = temp.top;
		tail = temp.tail;
		count = temp.count;
		temp.tail = temp.top = NULL;
	}
	return *this;
}

/*Print the nodes	*/
void cPriorityQue::print()const
{
	if (!top) { cout << "Stack Empty" << endl; }
	else {
		cNode* ptr = top;
		while (ptr) {
			ptr->print();
			cout <<"Priority:"<< ptr->getPriority() << endl;
			ptr = ptr->next;
		}
	}
}

/*To check Non-Emptyness of cPriorityQue*/
bool cPriorityQue::isNotEmpty()const
{
	return cQue::isNotEmpty();
}

/*To check Emptyness of cPriorityQue*/
bool cPriorityQue::isEmpty()const
{
	return cQue::isEmpty();
}

/*Remove the nodes from the end of cPriorityQue*/
cNode* cPriorityQue::remove()
{
	count--;
	return cQue::remove();
}

/*Constructor for creating node from file*/
cPriorityQue::cPriorityQue(ifstream& inFile)
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
void cPriorityQue::writeToFile(ofstream& oFile)
{
	cQue::writeToFile(oFile);
}

/*Function for creating node to file*/
void cPriorityQue::readFromFile(ifstream& inFile)
{
	cQue::readFromFile(inFile);
}


cPriorityQue::~cPriorityQue()
{
	cQue::~cQue();
}

