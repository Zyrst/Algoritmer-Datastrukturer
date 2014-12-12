#include "Tree.h"
#include <iostream>


Tree::Tree(int w, char c_)
{
	mWeight = w;
	mChar = c_;
}

Tree::Tree(int w, Tree* t1, Tree* t2)
{
	right	= t1;
	left	= t2;
	mWeight = w;
	mChar = 0;
}

Tree::~Tree(){}

int Tree::getWeight() const
{
	return mWeight;
}

void Tree::printTree(std::vector<char> &bitString) const
{

	char zero = 0;
	char one = '1';
	int z = 0;

	Tree* mTree = NULL;

	if (bitString[z] == one)
	{
		mTree = this->left; 
		std::cout << "1";
	}
	else 
	{ 
		mTree = this->right;
		std::cout << "0";
	}

	z++;

	while (z < bitString.size())
	{
		if(mTree->mChar == zero)
		{
			if (bitString[z] == one)
			{
				mTree = mTree->left; 
				std::cout << "1";
			}
			else
			{
				mTree = mTree->right; 
				std::cout << "0";
			}
		}
		if (mTree->mChar != zero)
		{
			std::cout << mTree->mChar << std::endl;
			z++;

			if(bitString[z] == one)
			{ 
				mTree = this->left; std::cout << "1";
			}
			else
			{
				mTree = this->right; std::cout << "0";
			}
		}
		z++;
	}		
}