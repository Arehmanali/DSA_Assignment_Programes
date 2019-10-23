#include "cNode.h"
#include<iostream>
#include<fstream>
using namespace std;
/*Definition of cNode default constructor for defaulting the data members*/
cNode::cNode()
{
	next = NULL;
	data = 0;
}
/*Definition of Parametrized Constructor */
cNode::cNode(int d)
{
	data = d;
	next = NULL;
}

/*Definition of getting Function for returning data */
int cNode::getData()const { return data; }

/* Definition of Setter Function for setting data */
void cNode::setData(int d) {
	this->data = d;
}

/*Definition of print function for output data on console*/
void cNode::print()const {
	cout << "Data is :" << data << endl;
}

/*Constructor for creating nodes from file*/
cNode::cNode(ifstream& inFile)
{
	inFile.read((char*)this, sizeof(*this) * 2);
}

/*Constructor for creating nodes to file*/
cNode::cNode(ofstream& oFile)
{
	oFile.write((char*)this, sizeof(*this) * 2);
}

/*Function for creating nodes from file*/
void cNode::readFromFile(ifstream& inFile)
{
	inFile.read((char*)this, sizeof(*this) * 2);
}

/*Function for creating nodes to file*/
void cNode::writeToFile(ofstream& oFile)
{
	oFile.write((char*)this, sizeof(*this) * 2);
}

