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

		Tree* mTree = NULL;

		if (bitString[z] == one)
		{
			mTree = this->right;
			std::cout << '1';
		}
		else 
		{
			mTree = this->right;
			std::cout << '0';
		}
		z++;
	

		while (z < bitString.size())
		{
			if(mTree->mChar == zero)
			{
				if(bitString[z] == one)
					{
						mTree = this->right;
						std::cout << '1';
						z++;
					}
				else 
				{
					mTree = this->left;
					std::cout << '0';
					z++;
				}
			}
			if (mTree->mChar != zero)
			{
				std::cout << ": " << mTree->mChar << std::endl;
				z++;
				if(z >= bitString.size())
				{
					break;
				}
				if(bitString[z] == one)
				{
					mTree = this->right;
					std::cout << '1';
					z++;
				}
				else
				{
					mTree = this->right;
					std::cout << '0';
					z++;
				}
			}
		}		
}

void Tree::printTrees(std::string &bitString) const
{

		char zero = 0;
		char one = '1';
		int z = 0;

		Tree* mTree = NULL;

		if (bitString[z] == one)
			mTree = this->right;
		else 
			mTree = this->left;

		z++;

		while (z < bitString.size())
		{
			if(mTree->mChar == zero)
			{
				if(bitString[z] == one)
					mTree = mTree->right;
				else 
					mTree = mTree->left;
			}
			if (mTree->mChar != zero)
			{
				std::cout << mTree->mChar;
				z++;

				if(bitString[z] == one)
					mTree = this->right;
				else
					mTree = this->left;
			}
			z++;
		}		
}	