#include<iostream>
#include<fstream>
#include"cNode.h"
#include"cStack.h"
#include"cQue.h"
#include"cPriorityQue.h"
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
		Driver Program For cPriorityQue Class
	 ***************************************************************/
	cPriorityQue pq1;						// pq1 object of cPriorityQue
	ifstream input;				// Standard input for taking input from file
	ofstream output;			// Standard output for taking output to file
	input.open("D:/Visual Studio Codes/cPriorityQue/cPriorityQue/inFile.txt");				// Opening of file directory
	output.open("D:/Visual Studio Codes/cPriorityQue/cPriorityQue/inFile.txt");

	if (!input)
	{
		cerr << "\n In cStack::inFile is Not open!\n";
	}
	else {
		pq1.readFromFile(input);										// Reads the data from file and push to que
		cout << "\n Data get successfully from file\n";
	}
	pq1.print();

	c1->setPriority(1);						// Set the priority of c1 as 3
	pq1.add(c1);							// add new node c1 at the end of object pq1
	c3->setPriority(2);						// Set the priority of c3 as 4
	pq1.add(c3);							// add new node c3 at the end of object pq1
	c4->setPriority(3);						// Set the priority of c4 as 2
	pq1.add(c4);							// add new node c4 at the end of object pq1
	c5->setPriority(4);						// Set the priority of c5 as 1
	pq1.add(c5);							// add new node c5 at the end of object pq1
	cout << "\ncPriorityQue after the adding Nodes along with priority\n";
	pq1.print();							// Print the all the nodes
	pq1.remove();							// remove the last node from pq1
	cout << "\ncPriorityQue after the removing Nodes along with priority\n";
	pq1.print();
	cPriorityQue pq2(pq1);					//Testing the copy Constructor
	cout << "\ncPriorityQue after the copying Nodes along with priority\n";
	pq2.print();
	cPriorityQue pq3 = pq2;					//Testing the Assignment Operator
	cout << "\ncPriorityQue after the Assigning Nodes along with priority\n";
	pq3.print();
	if (!output)
	{
		cerr << "\n In cStack::inFile is Not open!\n";
	}
	else
	{
		pq1.writeToFile(output); cout << "\n Data get successfully to file\n";			// write the data to file
	}
	cout << "\nStack after outputing Nodes\n";
	pq1.print();
	input.close();				//close the opened files
	output.close();
	return 0;
}