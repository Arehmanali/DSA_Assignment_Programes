#pragma once
#include"cNode.h"

class cDoublyList
{
	int count;
	cNode* leftHead;
	cNode* rightHead;

public:
	cDoublyList();
	cDoublyList(cNode*& ptr);
	void print(bool leftToRight = true)const;
	cNode* removeFromLeft();
	cNode* removeFromRight();
	cNode* removeAt(int index);
	cDoublyList& insertToLeft(cNode*& ptr);
	cDoublyList& insertToRight(cNode*& ptr);
	cDoublyList& insertAt(int index, cNode*& ptr);
	~cDoublyList();
};

