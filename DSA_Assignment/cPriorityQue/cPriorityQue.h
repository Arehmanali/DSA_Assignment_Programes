#pragma once
#include"cNode.h"
#include"cQue.h"
#include"cStack.h"
#include<fstream>
using namespace std;

class cPriorityQue :public cQue
{
	int count;
public:
	cPriorityQue(cNode*& ptr);								// Parametric Constructor
	cPriorityQue();											// Default Constructor
	bool isNotEmpty()const;									// To check Non-Emptyness of cPriorityQue
	bool isEmpty()const;									// To check Emptyness of cPriorityQue
	cPriorityQue& add(cNode*& ptr);							// To add new node at the prioritized position
	cPriorityQue(const cPriorityQue& src);					// Copy Constructor of cPriorityQue
	cPriorityQue& operator =(const cPriorityQue& robj);		// Assignment operator of cPriorityQue
	void print()const;										// Print the nodes	
	cNode* remove();										// Remove the nodes from the end of cPriorityQue
	cPriorityQue(ifstream& inFile);							//Constructor for creating node from file
	void writeToFile(ofstream& oFile);						//fUNCTION for creating node from file
	void readFromFile(ifstream& inFile);					//Function for creating node to file
	~cPriorityQue();

};

