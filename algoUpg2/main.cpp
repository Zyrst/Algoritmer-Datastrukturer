#include "person.h"
#include "graph.h"
#include <queue>

using namespace std;

int main()
{
	Graph* graph 	= new Graph();
	
	Person* j = new Person("J");
	Person* a = new Person("A");
	Person* s = new Person("S");
	Person* e = new Person("E");
	Person* g = new Person("G");
	Person* k = new Person("K");
	Person* i = new Person("I");

	j->addToUnfriend(a);
	a->addToUnfriend(s);
	i->addToUnfriend(s);
	s->addToUnfriend(k);
	
	graph->drawGraph(j);
	cout << "freinds:";
	j->printFriends();
	cout << endl << "enemies:";
	j->printEnemies();
}
