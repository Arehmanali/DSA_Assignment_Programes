#pragma once
#include<iostream>
#include"cNode.h"
#include <fstream>
using namespace std;
class cCircularList
{
	cNode* head;
	int count;
public:
	cCircularList();
	cCircularList(cNode*& ptr);
	cCircularList(const cCircularList& src);
	cCircularList& operator=(const cCircularList& robj);
	cNode* remove();
	cCircularList(ifstream& inFile);							// Standard Input from file
	cCircularList(ofstream& outFile);
	void writeToFile(ofstream& oFile);					//fUNCTION for creating node from file
	void readFromFile(ifstream& inFile);				//Function for creating node to file
	int getCount();
	cNode* removeAt(int index);
	cCircularList& insert(cNode*& ptr);
	cCircularList& insertAt(int index,cNode*& ptr);
	bool isEmpty()const;
	bool isNotEmpty()const;
	void print()const;
	void deleteNode(cNode*& ptr);
	cCircularList& swapNodesAt(int index1, int index2);			// Swap the two Nodes in linkList
	cCircularList& reverse();									// Reverse the all the Nodes in LinkList
	cCircularList& operator +(const cCircularList& robj);				// Operator for Add the two LinkList classes
	~cCircularList();
};
