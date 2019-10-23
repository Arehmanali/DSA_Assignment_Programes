#pragma once
#include"cNode.h"
#include<fstream>
using namespace std;
class cList {
	cNode* head;										// Object of cNode point to first node in LinkList
	int count;											// Count for Counting the Nodes of LinkList
public:
	cList();
	cList(cNode*& ptr);									// Parametric Constructor for LinkList class
	cList(ifstream& inFile);							// Standard Input from file
	cList(ofstream& outFile);
	void writeToFile(ofstream& oFile);					//fUNCTION for creating node from file
	void readFromFile(ifstream& inFile);				//Function for creating node to file
	cList(const cList& src);							// Copy constructor for cList
	bool isEmpty()const;								// Check the Emptyness of linkList
	bool isNotEmpty()const;								// Check the Non-Emptyness of linkList
	int getCount()const;								// Return the count of integer type
	cList& insert(cNode*& ptr);							// Add the new Node in LinkList
	cList& insertAt(int index, cNode*& ptr);			// Add the new Node at particular index in LinkList
	cNode* remove();									// Remove the Node from linkList
	cNode* removeAt(int index);							// Remove the Node from linkList at particular index
	cList& operator = (const cList& src);				// Operator for array of linkList
	cList& swapNodesAt(int index1, int index2);			// Swap the two Nodes in linkList
	cList& reverse();									// Reverse the all the Nodes in LinkList
	cList& operator +(const cList& robj);				// Operator for Add the two LinkList classes
	void print()const;									// Print the Nodes of LinkList
	void deleteNode(cNode*& ptr);
	~cList();
};
