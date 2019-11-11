#include "cCircularList.h"
#include<fstream>
using namespace std;

/* default constructor */
cCircularList::cCircularList():head(NULL),count(0){}

/*parametric constructor*/
cCircularList::cCircularList(cNode*& ptr)
{
	head = ptr;
	count = 1;
	head->next = head;
	ptr = NULL;
}

/* copy consructor*/
cCircularList::cCircularList(const cCircularList& src)
{
	this->head = src.head;
	this->count = src.count;
	if (count > 0)
	{
		cNode* sptr, * dptr;
		dptr = head = new cNode(*src.head);
		sptr = src.head->next;
		while (sptr)
		{
			dptr->next = new cNode(*sptr);
			dptr = dptr->next;
			sptr = sptr->next;
		}
		dptr->next = NULL;
	}
}

/* operator for assignment of lists*/
cCircularList& cCircularList::operator=(const cCircularList& robj)
{
	if (this == &robj) return *this;
	if (true)
	{
		cCircularList temp;
		temp.head = head;
		temp.count = count;
	}
	if (true)
	{
		cCircularList temp = robj;
		head = temp.head;
		count = temp.count;
		temp.head = NULL;
	}
	return *this;
}

/*remove function for removing the nodes from list*/
cNode* cCircularList::remove()
{
	cNode* ptr;
	ptr = head->next;
	if (count > 1)
	{
		head->next = ptr->next;
	}
	else
	{
		head = NULL;
	}
	ptr->next = NULL;
	--count;
	return ptr;
}


cCircularList::cCircularList(ifstream& inFile)
{
	if (!inFile.is_open())cerr << "\ncCircularList input file is Not ioen!\n";
	head = NULL;
	count = 0;
	inFile.read((char*)& count, sizeof(count));
	if (count > 0) {
		cNode* ptr;
		ptr = head = new cNode(inFile);
		for (int i = 1; i < count; ++i) {
			ptr->next = new cNode(inFile);
			ptr = ptr->next;
		}
		ptr->next = NULL;
	}
}

cCircularList::cCircularList(ofstream& outFile)
{
	outFile.write((char*)& count, sizeof(count));
	if (count > 0) {
		cNode* ptr;
		ptr = head = new cNode(outFile);
		for (int i = 1; i < count; ++i) {
			ptr->next = new cNode(outFile);
			ptr = ptr->next;
		}
	}
}

void cCircularList::writeToFile(ofstream& oFile)
{
	if (!oFile.is_open())cerr << "\n cCircularList outPut file is Not Open!\n";
	else
	{
		oFile.write((char*)& count, sizeof(count));
		if (count > 0) {
			cNode* ptr = head;
			for (int i = 0; i < count; i++) {
				ptr->writeToFile(oFile);
				ptr = ptr->next;
			}
		}
	}
}

void cCircularList::readFromFile(ifstream& inFile)
{
	if (true) { cCircularList temp; temp.head = this->head; }

	if (!(inFile.is_open())) {
		cout << "File is not opened for writing !" << endl;
	}
	else {
		inFile.read((char*)& count, sizeof(count));
		if (count > 0) {
			cNode* rptr = head = new cNode(inFile);
			for (int i = 1; i < count; ++i) {
				rptr->next = new cNode(inFile);
				rptr = rptr->next;
			}
			rptr->next = NULL;
		}
	}
}

int cCircularList::getCount()
{
	return count;
}

/* removeAt function for emoving of nodes at specific index in the list*/
cNode* cCircularList::removeAt(int index)
{
	if (index <= 0) return remove();
	if (index >= count)index = count - 1;
	cNode* ptr, * rptr;
	rptr = head->next;
	if (index == count - 1)head = rptr;
	for (int i = 1; i < index; ++i) rptr = rptr->next;
	ptr = rptr->next;
	rptr->next=ptr->next;
	ptr->next = NULL;
	--count;
	return ptr;
}

/*insert function for inserting the nodes*/
cCircularList& cCircularList::insert(cNode*& ptr)
{
	if (head)
	{
		ptr->next = head->next;
		head->next = ptr;
	}
	else
	{
		head = ptr;
		head->next = head;
	}
	ptr = NULL;
	++count;
	return *this;
}

/* insert function for inserting the new nodes at particular index in the list*/
cCircularList& cCircularList::insertAt(int index,cNode*& ptr)
{
	if (index < 0)index = 0;
	if (!head || index == 0)	return insert(ptr);
	if (index >= count)index = count;
	cNode* rptr = head->next;
	for (int i = 1; i < index; ++i)rptr = rptr->next;
	ptr->next = rptr->next;
	rptr->next = ptr;
	if (index == count)head = ptr;
	ptr = NULL;
	++count;
	return *this;
}

/* function for checking the emptyness of list*/
bool cCircularList::isEmpty() const
{
	if (head==NULL) return true;
	else return false;
}

bool cCircularList::isNotEmpty() const
{
	if (head!=NULL) return true;
	else return false;
}

void cCircularList::print() const
{
	if (!head)cerr << "\ncCircularList is Empty!\n";
	else
	{
		cNode* ptr = head->next;
		for (int i = 0; i < count; ++i)
		{
			ptr->print();
			ptr = ptr->next;
		}
	}
}

void cCircularList::deleteNode(cNode*& ptr)
{
	if (ptr) {
		deleteNode(ptr->next);
		delete ptr;
	}
}

cCircularList& cCircularList::swapNodesAt(int index1, int index2)
{
	if (index1 < 0) index1 = 0;
	if (index2 < 0) index2 = 0;
	if (index1 >= count) index1 = count - 1;
	if (index2 >= count) index2 = count - 1;
	if (index1 == index2) return *this;
	if (index1 < index2) { //when index1 is less then index2
		cNode* ptr = removeAt(index1);
		insertAt((index2 - 1), ptr);			//removig the node from index1 and iserting at index2-1 
		cNode * ptr1 = removeAt(index2);
		insertAt(index1, ptr1);		 			//removing node from index2 and inserting it at index1	
	}
	else {									//when index 1 is greater then index2
		cNode* ptr = removeAt(index2);
		insertAt((index1 - 1), ptr);			//removig the node from index2 and iserting at index1-1 
		cNode * ptr1 = removeAt(index1);
		insertAt(index2, ptr1);	//removig the node from index1 and iserting at index2 
	}
	return *this;
}

cCircularList& cCircularList::reverse()
{
	if (count < 2)return *this;
	cNode** ARR = new cNode * [count];
	cNode* rptr = head;
	for (int i = 0; i < count; ++i)
	{
		ARR[i] = rptr;
		rptr = rptr->next;
	}
	for (int i = 1; i < count; ++i)
	{
		ARR[i]->next = ARR[i - 1];
	}
	ARR[0]->next= NULL;
	head = ARR[count - 1];
	delete[]ARR;
	return *this;
}

cCircularList& cCircularList::operator+(const cCircularList& robj)
{
	if (robj.count == 0)return *this;
	cCircularList rCopy = robj;
	if (!head)
	{
		head = rCopy.head;
		count = rCopy.count;
	}
	else
	{
		cNode* rptr = head;
		for (int i = 1; i < count; ++i)
		{
			rptr = rptr->next;
		}
		rptr->next = rCopy.head;
		count += rCopy.count;
	}
	rCopy.head = NULL;
	return *this;
}
cCircularList::~cCircularList()
{
	deleteNode(head);
	{
		void deleteNode(cNode * ptr);
	}
}
