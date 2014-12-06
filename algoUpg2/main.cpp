#include "person.h"
#include "graph.h"
#include <queue>

using namespace std;

int main()
{
	Graph* graph 	= new Graph();
	Person* eva 	= new Person("Eva");
	Person* adolf 	= new Person("Adolf");
	Person* Josef 	= new Person("Josef");
	Person* Jews	= new Person("Jews");
	
	// Get it? ;D
	Jews->addToUnfriend(adolf);
	adolf->addToUnfriend(Josef);
	Josef->addToUnfriend(eva);
	adolf->addFriend(eva);

	std::cout << "Adolfs friends: " << std::endl;
	adolf->printFriends();
	std::cout << "Josef enemies: " << std::endl;
	Josef->printEnemies();

	std::cout << "Jew graph: " << std::endl;
	graph->drawGraph(Jews);

	std::cout << "Jews friends: " << std::endl;
	Jews->printFriends();
	getchar();
}