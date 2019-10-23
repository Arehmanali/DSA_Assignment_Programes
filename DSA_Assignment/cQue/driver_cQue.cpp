#include<iostream>
#include<fstream>
#include"cNode.h"
#include"cStack.h"
#include"cQue.h"
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
		Driver Program For cQue Class
	 ***************************************************************/
	cQue q1;				// q1 object of cQue
	ifstream input;				// Standard input for taking input from file
	ofstream output;			// Standard output for taking output to file
	input.open("D:/Visual Studio Codes/cQue/cQue/inFile.txt");				// Opening of file directory
	output.open("D:/Visual Studio Codes/cQue/cQue/inFile.txt");

	if (!input)
	{
		cerr << "\n In cStack::inFile is Not open!\n";
	}
	else {
		q1.readFromFile(input);										// Reads the data from file and push to que
		cout << "\n Data get successfully from file\n";
	}
	q1.print();

	q1.Add(c1);				// add c1 to object q1
	q1.Add(c3);				// add c3 to object q1
	q1.Add(c4);				// add c4 to object q1
	q1.Add(c5);				// add c5 to object q1
	cout << "\nQue after pushing the Nodes\n";
	q1.print();				// print all the nodes of object q1
	q1.remove();			// remove the last node from q1 i.e c1
	cout << "\nQue after removing the first Nodes\n";
	q1.print();
	cQue q2(q1);			//Testing the copy Constructor
	cout << "\nQue after copying the Nodes\n";
	q2.print();
	cQue q3 = q2;			//Testing the Assignment Operator
	cout << "\nQue after Assignning the Nodes\n";
	q3.print();
	if (!output)
	{
		cerr << "\n In cStack::inFile is Not open!\n";
	}
	else
	{
		q1.writeToFile(output); cout << "\n Data get successfully to file\n";			// write the data to file
	}
	cout << "\nStack after outputing Nodes\n";
	q1.print();
	input.close();				//close the opened files
	output.close();
	return 0;
}