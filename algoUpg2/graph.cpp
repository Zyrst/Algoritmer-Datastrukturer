#include "person.h"
#include "graph.h"
#include <iostream>
using namespace std;


int currentPaths = 1;

//Dokumentation är för de veka.
void Graph::drawGraph(Person* person)
{
	// So we have a person to add their new friends/enemies.
	if(mDefault == NULL)
	{
		mDefault = person;
	}

	mPerson = person;
	// If the last used person have no enemies. 
	// mPerson will be NULL and allow us to terminate.
	while(mPerson != NULL)
	{
		cout << "current person: " << person->mName << endl;
		// A person needs unfriends to continue.
		if(!mPerson->enemies.empty())
		{
			//Temorary queue contains Persons enemies
			std::queue<Person*> tempQ = mPerson->enemies;
 			for(int i = 0; i < mPerson->enemies.size(); i++)
 			{
 				mEnemy = tempQ.front();
 				// We don't want to add the same person multiple times.
	 			if(!mEnemy->marked)
 				{
 					mEnemy->marked = true;
 					nextLevelUnfriends.push(mEnemy);

 					if(currentPaths % 2 == 0 && mPerson != mDefault)
 						mDefault->addFriend(mEnemy);
 					else if(currentPaths % 2 == 1 && mPerson != mDefault)
 						mDefault->addToUnfriend(mEnemy);
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
		drawGraph(mPerson);		
	}
}
/*DIS SHIZZ IS MAGIC YO*/
void Graph::moveToNextLevel()
{
	if(!nextLevelUnfriends.empty())
	{
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
	// We reached the end. 
	// Time to end this.
	else
	{
		mPerson = NULL;
	}
	drawGraph(mPerson);
}