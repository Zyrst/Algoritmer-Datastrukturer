#include "TreeWrapper.h"
#include <queue>

int main()
{
	std::priority_queue<TreeWrapper> q;
	q.push(TreeWrapper(new Tree(4, 'a')));
	q.push(TreeWrapper(new Tree(3, 'b')));
	q.push(TreeWrapper(new Tree(1, 'c')));

	return 0;
}