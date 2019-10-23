#pragma once
#include"cStack.h"
#include "cNode.h"
#include<fstream>
using namespace std;

class cQue :protected cStack {        // Inherit cStack to cQue class as protected 
	int count;
public:
	cNode* tail;						// To set at address of last Node in cQue
	cQue();								// Default Constructor
	cQue(cNode*& ptr);					// Patametric Constructor 
	bool isNotEmpty()const;				// To check the Non-Emptyness of cQue
	bool isEmpty()const;				// To check the Emptyness of cQue
	cQue& Add(cNode*& ptr);				// Add the new node at the end of cQue
	void print()const;					// Print the nodes in cQue
	cQue(const cQue& src);						// Copy Constructor for copying cQue
	cQue& operator =(const cQue& robj);			// Assignment operator for cQue
	cNode* remove();							// Remove the node from the end of cQue
	cQue(ifstream& inFile);						//Constructor for creating node from file
	void writeToFile(ofstream& oFile);			//fUNCTION for creating node from file
	void readFromFile(ifstream& inFile);		//Function for creating node to file
	~cQue();
};

