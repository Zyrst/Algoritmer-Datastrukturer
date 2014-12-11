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

			if (w == 0)
				w = 1;

		//Kollar om den redan finns i k�n.
		for (auto& k : v)
		{
			if (k->mChar == s[i])
			{
				dontAdd = true;
			}		
			else
				dontAdd = false;
		}
		// L�gger till den om den inte hittas i k�n.
		// L�gger ocks� till i vectorn f�r enklare koll om det redan finns.
		if (!dontAdd){
			v.push_back(new Tree(w, s[i]));
		}			
	}

	v = sortVector(v);

	for (int c = 0; c < v.size(); c++)
	{
		q.push(TreeWrapper(new Tree(v[c]->getWeight(), v[c]->mChar)));
	}
	//Skapa det gemensamma tr�det
	while (q.size() > 1)
	{
		TreeWrapper t1(q.top().tree);
		q.pop();
		TreeWrapper t2(q.top().tree);
		q.pop();
		TreeWrapper tempT(new Tree((t1.tree->getWeight() + t2.tree->getWeight()), t1.tree, t2.tree));
		q.push(tempT);

		std::cout <<"New tree weight" << tempT.tree->getWeight() << std::endl;

	}

	return q;
}



int main()
{
	std::priority_queue<TreeWrapper> q;
	std::string input = "aaaabbbc";
	//std::getline(std::cin, input);
	q = createTree(input, q);
	
	TreeWrapper mainTree = q.top();
	q.pop();
	//Kanske inte f�r ha en string , grej som mattias anv�nder
	//Annars en vector med chars
	/*std::string zeros = "000011111110"; //"00011101001 000011111110";
	mainTree.tree->printTrees(zeros);*/
	std::vector<char> letters;
	for(int i = 0; i < 30; i++)
	{
		int num = rand() % 50 + 1;
		if (num % 2 == 0) 
			letters.push_back('0');
		else 
			letters.push_back('1');

	}

	/*letters.push_back('0');
	letters.push_back('0');
	letters.push_back('0');
	letters.push_back('1');
	letters.push_back('1');
	letters.push_back('1');
	letters.push_back('0');
	letters.push_back('1');
	letters.push_back('0');
	letters.push_back('0');
	letters.push_back('1');*/

	mainTree.tree->printTree(letters);
	getchar();
	return 0;
}