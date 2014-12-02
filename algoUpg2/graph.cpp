#include "person.h"
#include <iostream>
using namespace std;

//Dokumentation är för de veka.
void Graph::drawGraph(Person* person)
{
	while(mPerson != NULL)
	{
		mPerson = person;
		std::queue<Person*> tempQ = mPerson->enemies;
 		for(int i = 0; i < mPerson->enemies.size())
 		{
 			mEnemy = mPerson->tempQ.front();
 			nextLevelUnfriends.push(mEnemy);

 			cout << mEnemy->mName << "(" << mPerson->mName<< ")" << endl;
 			tempQ.pop();	
 		}
 		moveToNextLevel();
	}

}

void Graph::moveToNextLevel()
{
	// Allows us to use the BFS correctly.
	currentLevelUnfriends = nextLevelUnfriends;
	mPerson = currentLevelUnfriends.front();
	currentLevelUnfriends.pop();
}