#include "cDoublyList.h"
#include<iostream>
using namespace std;

cDoublyList::cDoublyList()
{
	count = 0;
	leftHead = NULL;
	rightHead = NULL;
}

cDoublyList::cDoublyList(cNode*& ptr)
{
	leftHead = ptr;
	rightHead = ptr;
	count = 1;
	leftHead->right = rightHead->left = ptr = NULL;
}

void cDoublyList::print(bool leftToRight) const
{
	int i; cNode* ptr;
	if (leftToRight)
	{
		for (ptr = leftHead, i = 0; i < count; ++i, ptr = ptr->right)ptr->print();
	}
	else
	{
		for (ptr = rightHead, i = 0; i < count; ++i, ptr = ptr->left)ptr->print();
	}
}

cNode* cDoublyList::removeFromLeft()
{
	cNode* ptr;
	if (leftHead)
	{
		ptr = leftHead;
		leftHead = leftHead->right;
		leftHead->left = NULL;
		ptr->right = NULL;
		--count;
		return ptr;
	}
	else return NULL;
}

cNode* cDoublyList::removeFromRight()
{
	cNode* ptr;
	if (rightHead)
	{
		ptr = rightHead;
		rightHead = rightHead->left;
		rightHead->right = NULL;
		ptr->left = NULL;
		--count;
		return ptr;
	}
	else return NULL;
}

cNode* cDoublyList::removeAt(int index)
{
	cNode* ptr, * rptr;
	if (index <= 0)return removeFromLeft();
	else if (index >= count - 1)return removeFromRight();
	else
	{
		rptr = leftHead;
		for (int i = 1; i < index; ++i) rptr = rptr->right;
		ptr = rptr->left;
		rptr->left->right = rptr->right;
		rptr->right->left = rptr->left;
		rptr->left = rptr->right = NULL;
		
	}
	--count;
	return ptr;
}

cDoublyList& cDoublyList::insertToLeft(cNode*& ptr)
{
	ptr->right = leftHead;
	if (leftHead) leftHead->left = ptr;
	else rightHead->right = ptr;
	leftHead = ptr;
	ptr=leftHead->left = NULL;
	count++;
	return *this;
}

cDoublyList& cDoublyList::insertToRight(cNode*& ptr)
{
	ptr->left = rightHead;
	if (rightHead) rightHead->right = ptr;
	else leftHead->left = ptr;
	rightHead = ptr;
	ptr = rightHead->right = NULL;
	count++;
	return *this;
}

cDoublyList& cDoublyList::insertAt(int index, cNode*& ptr)
{
	if (index <= 0)return insertToLeft(ptr);
	if (index >= count)return insertToRight(ptr);
	cNode* rptr; int i;
	if (index <= count / 2)
	{
		for (i = 1, rptr = leftHead; i < index; ++i, rptr = rptr->right);
	}
	else
	{
		for (i = count, rptr = rightHead; i > index; --i, rptr = rptr->left);
	}
	ptr->right = rptr->right;
	ptr -> left = rptr;
	rptr->right->left = ptr;
	rptr->right = ptr;
	++count;
	return *this;
}

cDoublyList::cDoublyList(const cDoublyList& src)
{
	this->leftHead = leftHead;
	this->rightHead = rightHead;
	this->count = count;
	if (count > 0)
	{
		cNode* sptr, *dptr;
		dptr = leftHead = new cNode(*src.leftHead);
		sptr = src.leftHead->right;
		for (int i = 1; i < count; ++i)
		{
			dptr->right = new cNode(*sptr);
			dptr->right->left = dptr;
			dptr=dptr->right;
			sptr = sptr->right;
		}
		rightHead = dptr;
		rightHead->right = NULL;
	}
}

cDoublyList::~cDoublyList()
{
	for(int i=0;i<count;++i)
	{
		rightHead=leftHead;
		leftHead=leftHead->right;
		delete rightHead;
	}
}
