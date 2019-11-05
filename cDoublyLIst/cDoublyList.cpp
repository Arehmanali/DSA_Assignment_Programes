#include "cDoublyList.h"
#include<iostream>
using namespace std;

cDoublyList::cDoublyList()
{
	count = 0;
	rightHead = NULL;
	leftHead = NULL;
}

cDoublyList::cDoublyList(cNode *& ptr)
{
	leftHead->right = ptr;
	rightHead->left = ptr;
	count = 1;
	leftHead->right = rightHead -> left = ptr = NULL;
}

void cDoublyList::print(bool leftToRight=true) const
{
	cNode* rptr; int i;
	if (count <= 0) cerr << "\n Your cDoublyList is Empty\n";
	else 
	{
		if (leftToRight)for (rptr = leftHead, i = 1; i < count; ++i, rptr = rptr->right) rptr->print();
		else for (rptr = rightHead, i = 1; i < count; ++i, rptr = rptr->left) rptr->print();
	}
}


