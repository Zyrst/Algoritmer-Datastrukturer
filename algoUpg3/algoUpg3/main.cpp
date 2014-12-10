#include "TreeWrapper.h"
#include <queue>
#include <string>
#include <iostream>
#include <vector>
	

std::priority_queue<TreeWrapper> createTree(std::string s, std::priority_queue<TreeWrapper> q)
{
	std::vector<Tree*> v;
	bool dontAdd = false;
	// Yttre loop där vi skapar grunden för vår trädgrej.
	for (int i = 0; i < s.size(); i++)
	{
		char	c = s[i];
		int		w = 0;
		// Inre loopen där vi letar upp kopior.
		for (int j = i + 1; j < s.size(); j++)
		{
			if (s[i] == s[j])
			{
				w++;				
			}			
		}
		
		//Kollar om den redan finns i kön.
		for (auto k : v)
		{
			if (k->mChar == s[i])
			{
				dontAdd = true;
			}								
		}
		// Lägger till den om den inte hittas i kön.
		// Lägger också till i vectorn för enklare koll om det redan finns.
		if (!dontAdd){
			q.push(TreeWrapper(new Tree(w, s[i])));
			v.push_back(new Tree(w, s[i]));
			//q.push(t);
			
		}			
	}
	/*for (auto i : v)
	{
		q.push(i);
		
	}*/
	//Skapa det gemensamma trädet
	while (q.size() > 1)
	{
		TreeWrapper t1(q.top().tree);
		q.pop();
		TreeWrapper t2(q.top().tree);
		q.pop();

		TreeWrapper tempT(new Tree((t1.tree->getWeight() + t2.tree->getWeight()), t1.tree, t2.tree));
		q.push(tempT);

	}

	return q;
}



int main()
{
	std::priority_queue<TreeWrapper> q;
	std::string input = "Theyshallnevercomprhenedthegloryofourfallenbrothersfortheyarethousaviours";
	//std::getline(std::cin, input);
	q = createTree(input, q);

	
	

	TreeWrapper mainTree = q.top();
	q.pop();
	//Kanske inte får ha en string , grej som mattias använder
	//Annars en vector med chars
	std::string zeros = "0001110101101010101110100011101111001010111000101000010110";
	mainTree.tree->printTrees(zeros);

	getchar();
	return 0;
}