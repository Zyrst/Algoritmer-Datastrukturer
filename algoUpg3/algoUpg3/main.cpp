#include "TreeWrapper.h"
#include <queue>
#include <string>
#include <iostream>
#include <vector>

void createTree(std::string s, std::priority_queue<TreeWrapper> q)
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
			Tree* t = new Tree(w, s[i]);
			v.push_back(t);
			q.push(t);
		}
			
	}
}



int main()
{
	std::priority_queue<TreeWrapper> q;
	std::string input = "aaaabbbc";
	std::getline(std::cin, input);

	createTree(input, q);


	return 0;
}