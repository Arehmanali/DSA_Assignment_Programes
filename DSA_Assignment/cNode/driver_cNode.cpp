#include"cNode.h"
#include<iostream>
using namespace std;
int main()
{
	cNode* c1, c2, * c3, * c4, * c5;    //Decleration of pointers objects of cNode class except c2
	c1 = new cNode(1);					// Object C1 set to new Node 
	c2.setData(2);						// Setter function of cNode class to set data of C2 object
	c2.getData();						// Getter Function of cNode class to get data of C2 object
	c3 = new cNode(3);
	c4 = new cNode(4);
	c5 = new cNode(5);
	c1->print();						// Print the data of C1 object
	c2.print();							// Print the data of C2 object
	c3->print();						// Print the data of C3 object
	c4->print();						// Print the data of C4 object
	c5->print();						// Print the data of C5 object
	return 0;
}