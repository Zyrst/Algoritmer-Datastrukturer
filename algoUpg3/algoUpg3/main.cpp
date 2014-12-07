#include "TreeWrapper.h"
#include <queue>

int main()
{
	std::priority_queue<TreeWrapper> q;

	Tree* a		= new Tree(4, 'a');
	Tree* b		= new Tree(3, 'b');
	Tree* c		= new Tree(1, 'c');
	Tree* node	= new Tree(0, ' ');
	
	Tree* node0 = new Tree((c->getWeight() + b->getWeight()), c, b);
	Tree* root	= new Tree((node0->getWeight() + a->getWeight()), node0, a);

	q.push(TreeWrapper(root));
	q.push(TreeWrapper(a));
	q.push(TreeWrapper(b));
	q.push(TreeWrapper(c));

	return 0;
}