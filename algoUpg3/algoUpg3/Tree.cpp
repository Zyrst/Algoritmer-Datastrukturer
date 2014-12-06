#include "Tree.h"

Tree::Tree(int w, char c_)
{
	mWeight = w;
	mChar = c_;
}

Tree::Tree(int w, Tree* t1, Tree* t2)
{
	right	= t1;
	left	= t2;
}

Tree::~Tree()
{
	//Bye tree
}

int Tree::getWeight() const
{
	return mWeight;
}

void Tree::printTree(std::vector<char> &bitString) const
{
	// Brint out content bitStrings
		//0 : a
		//1 0 : c
		//1 1 : b <- exempel från pdfen
}