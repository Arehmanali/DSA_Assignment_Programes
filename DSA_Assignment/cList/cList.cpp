#include "cList.h"
#include <iostream>
#include <fstream>
using namespace std;

//Default constructor of cList
cList::cList() :head(NULL), count(0) {}

//Parameterized constructor of cList
cList::cList(cNode*& ptr)
{
	head = ptr;
	head->next = NULL;
	count = 1;
}

//Constructors for FILE HANDLING 'INPUT DATA FROM FILE'
cList::cList(ifstream& inFile) :head(NULL), count(0) {
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

//Constructors for FILE HANDLING 'OUTPUT DATA TO FILE'
cList::cList(ofstream& outFile) {
	outFile.write((char*)& count, sizeof(count));
	if (count > 0) {
		cNode* ptr = head;
		ptr = new cNode(outFile);
		for (int i = 1; i < count; i++) {
			ptr->next = new cNode(outFile);
			ptr = ptr->next;
		}
	}
}

//Function for writing LIST data to file
void cList::writeToFile(ofstream& oFile) {
	if (!(oFile.is_open())) {
		cout << "File is not opened for writing !" << endl;
	}
	else {
		oFile.write((char*)& count, sizeof(count));

		if (count > 0) {
			cNode* rptr = head;
			for (int i = 0; i < count; ++i) {
				rptr->writeToFile(oFile);
				rptr = rptr->next;
			}
		}
	}
}

//Function for reading LIST data from file
void cList::readFromFile(ifstream& inFile) {
	if (true) { cList temp; temp.head = this->head; }

	if (!(inFile.is_open())) {
		cout << "File is not opened for writing !" << endl;
	}
	else {
		inFile.read((char*)& count, sizeof(count));
		cout << "The count read is " << count << endl;
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

//Functions to check if the link list is empty or not
bool cList::isEmpty()const { if (head == NULL) return true; else return false; }
bool cList::isNotEmpty()const { if (head != NULL) return true; else return false; }

int cList::getCount() const
{
	return count;
}

//Function to insert at the start of the Link List
cList& cList::insert(cNode * &ptr)
{
	ptr->next = head; //Next node of ptr becomes head node
	head = ptr; //Ptr becomes head node
	ptr = NULL; //Making ptr pointer NULL
	++count; //incrementing number of nodes on the list
	return *this;
}

//Function to insert at a specific node
cList& cList::insertAt(int index, cNode * &ptr)
{
	if (index < 0) return insert(ptr); //If index is less then 0, the node is inserted at the start of the list

	if (index >= count) index = count; //If index is greter then or equal to count

	cNode * rPtr = head;				//runner pointer
	for (int i = 1; i <= index; ++i) rPtr = rPtr->next; //Moving through the List to find the desired index
	//Linking the new node at the found index
	ptr->next = rPtr->next;
	rPtr->next = ptr;
	ptr = NULL;
	++count; //incrementing the count
	return *this;
}

//Removing the first node from the list
cNode * cList::remove()
{
	if (isEmpty()) { //if the list is empty, the program will exit from this function
		cerr << "There is no node present in the List\n";
		exit(1);
	}
	else {
		cNode* temp;
		temp = head;
		head = head->next;
		temp->next = NULL;
		--count;
		return temp;
	}
}

//Function to delete a node from a specific index
cNode* cList::removeAt(int index)
{
	if (index <= 0) { //when index is less then or equal to zero, deleting the head node
		return remove();
	}
	if (index >= count) { //when index is greater the or equal to count, resetting the index equal to count 
		index = count;
	}
	cNode* rptr = head; //Runner pointer
	for (int i = 1; i < index - 1; ++i)	rptr = rptr->next; //Moving through the list to find the node to be deleted
	cNode * ptr = rptr->next;
	rptr->next = ptr->next;
	--count;
	return ptr;
}


//Function to swap two nodes
cList& cList::swapNodesAt(int index1, int index2)
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
		insertAt(index1 - 1, ptr1);		 //removing node from index2 and inserting it at index1	
	}
	else {									//when index 1 is greater then index2
		cNode* ptr = removeAt(index2);
		insertAt((index1 - 1), ptr);			//removig the node from index2 and iserting at index1-1 
		cNode * ptr1 = removeAt(index1);
		insertAt(index2, ptr1);	//removig the node from index1 and iserting at index2 
	}
	return *this;
}

//Function to reverse the list
cList& cList::reverse()
{
	if (count < 2) return *this; //When only one node is present in the list 

	cNode* ptr;
	cNode** ARR = new cNode * [count];
	ptr = head;
	for (int i = 0; i < count; ++i) {
		ARR[i] = ptr;
		ptr = ptr->next;
	}
	for (int i = 1; i < count; ++i) {
		ARR[i]->next = ARR[i - 1];
	}
	ARR[0]->next = NULL;
	head = ARR[count - 1];
	delete[] ARR;
	return *this;
}

//Cancatenating one list with another list
cList& cList::operator+(const cList & robj)
{
	if (robj.count == 0) return *this; //when second list is empty
	cList rCopy = robj;
	if (!head) head = rCopy.head; //Assigning head node of this by head node of rcopy
	else {
		cNode* ptr = head;		//runner pointer

		for (int i = 0; i < count; ++i) ptr = ptr->next; //Iterating through the list
		ptr->next = rCopy.head;  //Joining two list
		count += rCopy.count;  //adding count of both the lists
	}
	rCopy.head = NULL;
	return *this;
}



//Printing all the nodes in the cList
void cList::print() const {
	if (count == 0) {
		cout << "\nLinked List is empty\n";
	}
	else {
		cNode* temp = head;
		for (int i = 0; i < count; ++i) {
			temp->print();
			temp = temp->next;
		}
	}
}

//Function to delete nodes from list
void cList::deleteNode(cNode * &ptr)
{
	if (ptr) {
		deleteNode(ptr->next);
		delete ptr;
	}
}

//Copy constructor for cList to avoid shallow copy
cList::cList(const cList & src) :head(src.head), count(src.count) {
	if (count > 0) {
		cNode* sptr, * dptr;
		dptr = head = new cNode(*src.head);
		sptr = src.head->next;
		while (sptr) {
			dptr->next = new cNode(*sptr);
			sptr = sptr->next;
			dptr = dptr->next;
		}
		dptr->next = NULL;
	}

}

//Overloading ASSIGNMENT OPERATOR
cList& cList::operator = (const cList & src) {
	if (this == &src) return *this;

	if (true) { cList temp; temp.head = this->head; }
	if (true) { cList temp; temp = src; this->head = temp.head; temp.head = NULL; }
	return *this;
}

//Class Destructor
cList::~cList() {
	deleteNode(head);
	{
		void deleteNode(cNode * ptr);
	}
}