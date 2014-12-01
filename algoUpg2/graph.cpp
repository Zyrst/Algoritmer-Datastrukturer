#include "person.h"

//Dokumentation är för de veka.
void Graph::drawGraph(Person* person)
{
	mPerson = person;
 	
}

void Graph::killAll()
{
	delete this;
}

void Graph::getNextUnfriend()
{
	mEnemy = mPerson->enemies(currentEnemyPosition++);
}

void Graph::moveToNextLevel()
{
	
}