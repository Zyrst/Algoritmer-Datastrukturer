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
	// Print out content bitStrings
		//0 : a
		//1 0 : c
		//1 1 : b <- exempel från pdfen

		char zero = 0;
		char one = '1';
		int z = 0;

		Tree* mTree = nullptr;

		if (bitString[z] == one)
			mTree = this->left;
		else 
			mTree = this->right;
		z++;
		// Inte tagit från Mattias nej då
		while (z < bitString.size())
		{
			if(mTree->mChar == zero)
			{
				if(bitString[z] == one)
					{
						mTree = mTree->left;
					}
				else 
					mTree = mTree->right;
			}
			if (mTree->mChar != zero)
			{
				std::cout << mTree->mChar << std::endl;
				z++;
				if(bitString[z] == one)
				{
					mTree = this->left;
				}
				else
					mTree = this->right;
			}
			z++;
		}		
}

void Tree::printTrees(std::string &bitString) const
{

		char zero = 0;
		char one = '1';
		int z = 0;

		Tree* mTree = nullptr;

		if (bitString[z] == one)
			mTree = this->left;
		else 
			mTree = this->right;
		z++;
		// Inte tagit från Mattias nej då
		while (z < bitString.size())
		{
			if(mTree->mChar == zero)
			{
				if(bitString[z] == one)
					{
						mTree = mTree->left;
					}
				else 
					mTree = mTree->right;
			}
			if (mTree->mChar != zero)
			{
				std::cout << mTree->mChar << std::endl;
				z++;
				if(bitString[z] == one)
				{
					mTree = this->left;
				}
				else
					mTree = this->right;
			}
			z++;
		}		
}