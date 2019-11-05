#include<iostream>
#include"cNode.h"
#include"cDoublyList.h"
using namespace std;
int main()
{
	
	cNode* node1, * node2, * node3, * node4, * node5, * node6;
	node1 = new cNode(1);
	node2 = new cNode(2);
	node3 = new cNode(3);
	node4 = new cNode(4);
	node5 = new cNode();
	node5->setData(5);
	node6 = new cNode();
	node5->setData(6);
	cDoublyList dList(node1);
	dList.insertToLeft(node2);
	dList.insertToRight(node3);
	dList.insertToLeft(node4);
	dList.insertToLeft(node5);
	dList.insertAt(3, node6);
	dList.print();
	cout << endl << endl;
	dList.removeAt(3);
	dList.print();
	cout << endl << endl;
	dList.removeFromLeft();
	dList.print();
	cout << endl << endl;
	dList.removeFromRight();
	dList.print();
	return 0;
}