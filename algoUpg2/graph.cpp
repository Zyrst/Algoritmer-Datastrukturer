#include "person.h"
#include "graph.h"
#include <iostream>
using namespace std;

int 	currentLevelPointer = 0;
int 	currentPaths 		= 0;
//Dokumentation är för de veka.
void Graph::drawGraph(Person* person)
{
	// To compare.
	if(mDefault == NULL)
	{
		mDefault = person;
	}

	mPerson = person;
	std::vector<pair<Person*, pair<int, bool>>> vec;
	while(mPerson != NULL)
	{
		if(!mPerson->enemies.empty())
		{
			//Temorary queue contains Persons enemies
			std::queue<Person*> tempQ = mPerson->enemies;
 			for(int i = 0; i < mPerson->enemies.size(); i++)
 			{
 				mEnemy = tempQ.front();
 				nextLevelUnfriends.push(mEnemy);

 				//Adds the first enemy found.
	 			if(!mEnemy->marked)
 				{
 					mEnemy->marked = true;
 					if(currentPaths % 2 == 0)
 						mDefault->addFriend(mEnemy);
 					else
 						mDefault->addToUnfriend(mEnemy);
 					return;
 				}
 				tempQ.pop();	
 			}
		}
 		moveToNextElement();
	}
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

		currentPaths++;
		mPerson = currentLevelUnfriends.front();
		currentLevelUnfriends.pop();	
	}

	else
	{
		mPerson = NULL;
	}
	drawGraph(mPerson);
}