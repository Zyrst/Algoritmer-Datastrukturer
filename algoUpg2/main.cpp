#include "person.h"
#include "graph.h"
#include <queue>

using namespace std;

int main()
{
	Graph* graph 	= new Graph();
	// Persons to use as testing. 
	// ****NOT ALL ARE USED*****
	Person* j = new Person("J");
	Person* a = new Person("A");
	Person* s = new Person("S");
	Person* k = new Person("K");
	Person* i = new Person("I");

	// Making the graph.
	j->addToUnfriend(a);
	a->addToUnfriend(s);
	s->addToUnfriend(k);
	s->addToUnfriend(i);
	k->addToUnfriend(i);
	i->addToUnfriend(j);
	
	// j is the root here.
	graph->drawGraph(j);

	cout << "freinds:";
	j->printFriends();
	cout << endl << "enemies:";
	j->printEnemies();
}
