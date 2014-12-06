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
		//Temorary queue contains Persons enemies
		std::queue<Person*> tempQ = mPerson->enemies;
 		for(int i = 0; i < mPerson->enemies.size(); i++)
 		{
 			mEnemy = tempQ.front();
 			nextLevelUnfriends.push(mEnemy);

 			//Adds the first enemy found.
 			if(!enemyAlreadyAdded(mEnemy) && isNotEnemy(mEnemy))
 			{
 				mDefault->addFriend(mEnemy);
 				return;
 			}

 			cout << mEnemy->mName << " is enemy of: " << mPerson->mName<<endl;
 			tempQ.pop();	
 		}
 		moveToNextElement();
	}

}

//Returns false if it's an enemy
//else true
bool Graph::isNotEnemy(Person* person)
{
	std::queue<Person*> tempQ = mDefault->enemies;
	for (int i = 0; i < tempQ.size(); ++i)
	{
		/*Person* tempP = tempQ.front();
		tempQ.pop();
		if(tempP == person)
			return false;*/
		if (tempQ.front() == person)
		{
			tempQ.pop();
			return false;
		}
		else
			tempQ.pop();
	}
	return true;	
}

//Returns true if it's a friend
//Else false
bool Graph::enemyAlreadyAdded(Person* person)
{
	std::queue<Person*> tempQ = mDefault->friends;
	for (int i = 0; i < tempQ.size(); ++i)
	{
		/*Person* tempP = tempQ.front();
		tempQ.pop();
		if(tempP == person)
			return true;*/
		if (tempQ.front() == person)
		{
			tempQ.pop();
			return false;
		}
		else
			tempQ.pop();
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