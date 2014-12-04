#include "Tree.h"
struct TreeWrapper
{
	Tree* tree;

	TreeWrapper()
	{
		tree = NULL;
	}

	TreeWrapper(Tree* t)
	{
		tree = t;
	}

	bool operator < (const TreeWrapper &tw) const
	{
		return tree->getWeight() > tw.tree->getWeight();
	}
};