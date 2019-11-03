#include<iostream>
#include<fstream>
#include"cNode.h"
#include"cCircularList.h"
using namespace std;
int main() {

	cCircularList list;
	cNode node;

	cNode* ptr = new cNode(1);				//Declaring a node and setting the data
	list.insert(ptr);						//Pushing the new node whose address is stored in ptr into the stack
	cNode* node1 = new cNode();				//Now declaring a node and setting data using setData fuction
	node1->setData(2);
	list.insert(node1);
	//Now declaring few more nodes and setting data using set Data function and pushing them to list
	cNode* node2 = new cNode();
	node2->setData(3);

	cNode* node3 = new cNode();
	node3->setData(4);

	cNode* node4 = new cNode();
	node4->setData(5);

	cNode* node5 = new cNode();
	node5->setData(6);

	list.insert(node2).insert(node3).insert(node4).insert(node5);
	//Now printing LINKED LIST after pushing 7 new nodes is isNotEmpty function returns true
	cout << "\LinkList after inserting New Nodes\n";
	if (list.isNotEmpty())list.print();

	cNode* node8 = new cNode(8);
	list.insertAt(4, node8);				//inserting new node at 4th index

	cout << "\LinkList after inserting new Node at index 4\n";
	if (list.isNotEmpty()) list.print();

	list.remove();							//Now deleting top of LINKED LIST  when more then one nodes is present
	cout << "\LinkList after removing first Node \n";
	if (list.isNotEmpty()) list.print();

	list.removeAt(3);						//Now deleting 3rd node from the LINKED LIST
	cout << "\nLinkList after removing the Node at index 3\n";
	if (list.isNotEmpty()) list.print();


	list.swapNodesAt(1, 3);					//Swapping the nodes present at  index 1 and 3
	cout << "\nLinkList after swaping the Node at index 1 & 3\n";
	if (list.isNotEmpty()) list.print();

	list.reverse();							//reversing the list
	cout << "\nLinkList after reversing the Node \n";
	if (list.isNotEmpty()) list.print();

	cCircularList list1(list);					//Checking copy constructor 
	cout << "\nLinkList after copying the Node into new list \n";
	list1.print();

	cCircularList list2 = list1;				//Copying contents of one list to another using assignment operator
	cout << "\nLinkList after assigning the Nodes to new list \n";
	if (list2.isNotEmpty())
		list2.print();

	ofstream outFile;			//Opeing file for write operation
	outFile.open("D:/Visual Studio Codes/cLinkList/cLinkList/inFile.txt");

	if (outFile.is_open()) {
		list.writeToFile(outFile);
		cout << "Data get successfully from file !" << endl;
	}
	else {
		cout << "File not opened for writing !" << endl;
	}

	outFile.close();
	ifstream inFile;
	inFile.open("D:/Visual Studio Codes/cLinkList/cLinkList/inFile.txt");
	cCircularList linkList;

	if (inFile.is_open()) {
		linkList.readFromFile(inFile);
		cout << "Data get successfully from file !\n";
	}
	else {
		cout << "The file is not opened for the Read operation !" << endl;
	}

	cout << "\nLinkList after reading from file\n" << endl;
	linkList.print();

	inFile.close();
	system("pause");

	return 0;

}