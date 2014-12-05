#include "person.h"
#include "graph.h"
#include <iostream>
using namespace std;

int currentLevelPointer = 0;
//Dokumentation är för de veka.
void Graph::drawGraph(Person* person)
{
	// To compare.
	if(mDefault == NULL)
	{
		mDefault = person;
	}

	mPerson = person;
	
	while(mPerson != NULL)
	{
		std::queue<Person*> tempQ = mPerson->enemies;
 		for(int i = 0; i < mPerson->enemies.size(); i++)
 		{
 			mEnemy = tempQ.front();
 			nextLevelUnfriends.push(mEnemy);

 			//Adds the first enemy found.
 			if(!enemyAlreadyAdded(mEnemy))
 				mDefault->addToUnfriend(mEnemy);

 			cout << mEnemy->mName << "(" << mPerson->mName<< ")" << endl;
 			tempQ.pop();	
 		}
 		moveToNextElement();
	}

}

bool Graph::enemyAlreadyAdded(Person* person)
{
	std::queue<Person*> tempQ = mDefault->enemies;
	for (int i = 0; i < tempQ.size(); ++i)
	{
		Person* tempP = tempQ.front();
		tempQ.pop();
		if(tempP == person)
			return true;
	}
	return false;	
}


void Graph::moveToNextElement()
{ 
	if(currentLevelUnfriends.empty())
		moveToNextLevel();
	else{
		mPerson = currentLevelUnfriends.front();
		currentLevelUnfriends.pop();
		currentLevelPointer++;
		drawGraph(mPerson);		
	}
}

void Graph::moveToNextLevel()
{
	if(!nextLevelUnfriends.empty())
	{
		currentLevelPointer = 0;
		// Allows us to use the BFS correctly.
		currentLevelUnfriends = nextLevelUnfriends;
		while(!nextLevelUnfriends.empty())
		{
			nextLevelUnfriends.pop();
		}
		mPerson = currentLevelUnfriends.front();
		currentLevelUnfriends.pop();	
	}
	else{
		mPerson = NULL;
	}
	drawGraph(mPerson);
}