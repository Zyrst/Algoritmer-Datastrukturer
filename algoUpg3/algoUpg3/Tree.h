#include <vector>

class Tree
{
public:
	Tree(int w, char c_);
	Tree(int w, Tree* t1, Tree* t2);
	~Tree();
	int getWeight() const;
	void printTree(std::vector<char>& bitString) const;
	char mChar;
	
private: 
	Tree* left;
	Tree* right;
	int mWeight;
};