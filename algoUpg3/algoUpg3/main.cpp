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
}



int main()
{
	std::priority_queue<TreeWrapper> q;
	std::string input = "aaaabbbc";
	std::getline(std::cin, input);

	createTree(input, q);


	return 0;
}