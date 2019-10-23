#pragma once
#include"cNode.h"
#include<iostream>
#include<fstream>
using namespace std;
class cStack {
	int count;
public:
	cNode* top;
	cStack();										// Default Constructor of cStack
	cStack(cNode* ptr);								// Parametric Constructor of cStack
	bool isNotEmpty()const;							// For checking cStack as non-empty
	bool isEmpty()const;							// For checking cStack as empty
	cStack& push(cNode* ptr);						// To add the Node in cStack 
	cNode* pop();									// To remove the Node from cStack
	void printStack()const;							// Print the Nodes from cStack 
	cStack(const cStack& src);						// Copy Consructor of cStack class
	cStack& operator=(const cStack& robj);			// Assignment operator of cStack 
	~cStack();										// Destructor of cStack to return memory
	cStack(ifstream& inFile);						// Constructor for creating node from file
	void writeToFile(ofstream& oFile);				// Function for creating node from file
	void readFromFile(ifstream& inFile);			// Function for creating node to file
};

