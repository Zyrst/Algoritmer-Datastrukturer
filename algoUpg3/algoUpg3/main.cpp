#include "TreeWrapper.h"
#include <queue>
#include <string>
#include <iostream>
#include <vector>
	

std::vector<Tree*> sortVector(std::vector<Tree*>v)
{
	for (int c = 0; c < v.size(); c++)
	{
		for (int d = c + 1; d < v.size(); d++)
		{
			if (v[c]->getWeight() > v[d]->getWeight())
			{
				auto temp = v[c];
				v[c] = v[d];
				v[d] = temp;
			}
			else
				continue;
		}
	}
	return v;
}

std::priority_queue<TreeWrapper> createTree(std::string s, std::priority_queue<TreeWrapper> q)
{
	std::vector<Tree*> v;
	bool dontAdd = false;
	// Yttre loop där vi skapar grunden för vår trädgrej.
	for (int i = 0; i < s.size(); i++)
	{
		int	freq = 0;
		// Inre loopen där vi letar upp kopior.
			for (int j = i + 1; j < s.size(); j++)
			{
				if (s[i] == s[j])
				{
					freq++;
				}
				
			}
			if (freq == 0)
				freq = 1;

		//Kollar om den redan finns i kön.
		for (auto& k : v)
		{
			if (k->mChar == s[i])
			{
				dontAdd = true;
			}		
			else
				dontAdd = false;
		}
		// Lägger till den om den inte hittas i kön.
		// Lägger också till i vectorn för enklare koll om det redan finns.
		if (!dontAdd){
			v.push_back(new Tree(freq, s[i]));
		}			
	}

	v = sortVector(v);

	for (int c = 0; c < v.size(); c++)
	{
		q.push(TreeWrapper(new Tree(v[c]->getWeight(), v[c]->mChar)));
	}
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
	std::string input = "aaaabbbc";

	q = createTree(input, q);
	
	TreeWrapper mainTree = q.top();
	q.pop();
	
	//Pseudo-Random vector med ettor och nollor
	std::vector<char> letters;
	for(int i = 0; i < 20; i++)
	{
		
		int num = rand() % 50 + 1;
		if (num % 2 == 0) 
			letters.push_back('0');
		else 
			letters.push_back('1');

	}
	mainTree.tree->printTree(letters);
	letters.clear();
	getchar();
	return 0;
}