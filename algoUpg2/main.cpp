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
	Person* Gobbels = new Person("Gobbels");
	Person* Jews	= new Person("Jews");
	Person* God		= new Person("God");
	
	// Get it? ;D
	Jews->addToUnfriend(adolf);
	adolf->addToUnfriend(Josef);
	adolf->addToUnfriend(God);
	Josef->addToUnfriend(eva);
	
	Jews->printFriends();

	graph->drawGraph(Jews);

	Jews->printFriends();
}