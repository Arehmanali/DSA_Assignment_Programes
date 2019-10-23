#include<iostream>
#include<fstream>
#include"cStack.h"
using namespace std;
int main()
{
	/***************************************************************
		Driver Program For cNode Class
	 ***************************************************************/
	cNode* c1, c2, * c3, * c4, * c5;			//Decleration of pointers objects of cNode class except c2
	c1 = new cNode(1);							// Object C1 set to new Node
	c2.setData(2);								// Setter function of cNode class to set data of C2 object
	c3 = new cNode(3);
	c4 = new cNode(4);
	c5 = new cNode(5);

	/***************************************************************
		Driver Program For cStack Class
	 ***************************************************************/
	cStack s1;					// S1 as object of stack
	ifstream input;				// Standard input for taking input from file
	ofstream output;			// Standard output for taking output to file
	input.open("D:/Visual Studio Codes/cStack/cStack/inFile.txt");				// Opening of file directory
	output.open("D:/Visual Studio Codes/cStack/cStack/inFile.txt");				

	if (!input)
	{
		cerr << "\n In cStack::inFile is Not open!\n";
	}
	else {
		s1.readFromFile(input);										// Reads the data from file and push to stack
		cout << "\n Data get successfully from file\n";
	}
	s1.printStack();
	
	s1.push(c1);				// Add new node C1 in S1 object of stack
	s1.push(c3);				// Add new node C3 in S1 object of stack
	s1.push(c4);				// Add new node C4 in S1 object of stack
	s1.push(c5);				// Add new node C5 in S1 object of stack
	cout << "\nStack after pushing Nodes\n";
	s1.printStack();			//Print the all the nodes of S1 object
	s1.pop();					//Remove the very first node i.e C5 from S1 
	cout << "\nStack after poping first Node\n";
	s1.printStack();			
	cStack s2(s1);		// copy Constructor to copy s1 in s2
	cout << "\nStack after copying Nodes\n";
	s2.printStack();
	cStack s3 = s2;		// Assignment Operator to assign s2 to s3
	cout << "\nStack after assignment of Nodes\n";
	s3.printStack();
	if (!output)
	{
		cerr << "\n In cStack::inFile is Not open!\n";
	}
	else
	{
		s1.writeToFile(output); cout << "\n Data get successfully to file\n";			// write the data to file
	}
	cout << "\nStack after outputing Nodes\n";
	s1.printStack();

	input.close();				// Closing of input file
	output.close();				// Closing of output file
}