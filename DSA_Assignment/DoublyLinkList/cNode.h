#pragma once
#include<fstream>
using namespace std;

class cNode {
	int data;					// data member of cNode of integer type
public:
	cNode* right;				// pointer of cNode class for taking address of next Node
	cNode* left;
	cNode();					//Defalut Constructor of cNode class
	cNode(int d);							// Parametrized Constructor of cNode class
	int getData()const;						// for getting value of Node of return type integer
	void setData(int d);					// for setting value of Node of return type void
	void print()const;						// Print the value of Nodes
	cNode(ifstream& inFile);				// Constructor for creating node from file
	cNode(ofstream& oFile);					// Constructor for creating node to file
	void readFromFile(ifstream& inFile);	// Function for creating node from file
	void writeToFile(ofstream& oFile);		// Function for creating node to file
};
