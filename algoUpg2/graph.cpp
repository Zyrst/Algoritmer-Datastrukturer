#include "person.h"

//Dokumentation är för de veka.
void Graph::drawGraph(std::vector<Person*> v){
	for(auto i : v)
	{
		mPerson = i;
		
	}
}

void Graph::killAll()
{
	delete this;
}

void Graph::getNextUnfriend()
{
	mEnemy = mPerson->enemies(currentEnemyPosition++);
}

void Graph::getNextFriend()
{
	mFriend = mPerson->friends(currentFriendPosition++);
}