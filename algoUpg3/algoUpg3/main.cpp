#include "TreeWrapper.h"
#include <queue>
#include <string>
#include <iostream>
#include <vector>
	

void createTree(std::string s, std::priority_queue<TreeWrapper> q)
{
	std::vector<Tree*> v;
	bool dontAdd = false;
	// Yttre loop d�r vi skapar grunden f�r v�r tr�dgrej.
	for (int i = 0; i < s.size(); i++)
	{
		char	c = s[i];
		int		w = 0;
		// Inre loopen d�r vi letar upp kopior.
		for (int j = i + 1; j < s.size(); j++)
		{
			if (s[i] == s[j])
			{
				w++;				
			}			
		}
		std::cout << c << ": " << w << " times" << std::endl;
		//Kollar om den redan finns i k�n.
		for (auto k : v)
		{
			if (k->mChar == s[i])
			{
				dontAdd = true;
			}								
		}
		// L�gger till den om den inte hittas i k�n.
		// L�gger ocks� till i vectorn f�r enklare koll om det redan finns.
		if (!dontAdd){
			Tree* t = new Tree(w, s[i]);
			v.push_back(t);
			q.push(t);
		}			
	}
	for (auto i : v)
	{
		q.push(i);
	}
}



int main()
{
	std::priority_queue<TreeWrapper> q;
	std::string input = "You shall not pass and my axe";
	//std::getline(std::cin, input);

	createTree(input, q);

	//Skapa det gemensamma tr�det
	while(q.size() > 1)
	{
		TreeWrapper t1(q.top().tree);
		q.pop();
		TreeWrapper t2(q.top().tree);
		q.pop();

		TreeWrapper tempT(new Tree((t1.tree->getWeight() + t2.tree->getWeight()), t1.tree, t2.tree));

	}

	TreeWrapper mainTree = q.top();
	q.pop();
	//Kanske inte f�r ha en string , grej som mattias anv�nder
	//Annars en vector med chars
	std::string zeros = "001100100100101110";
	mainTree.tree->printTrees(zeros);


	return 0;
}