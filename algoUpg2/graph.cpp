#include "person.h"
#include "graph.h"
#include <iostream>
using namespace std;

int currentLevelPointer = 0;
Person* mEnd = new Person("End");
//Dokumentation är för de veka.
void Graph::drawGraph(Person* person)
{
	mPerson = person;
	while(mPerson != mEnd)
	{
		std::queue<Person*> tempQ = mPerson->enemies;
 		for(int i = 0; i < mPerson->enemies.size(); i++)
 		{
 			mEnemy = tempQ.front();
 			nextLevelUnfriends.push(mEnemy);

 			cout << mEnemy->mName << "(" << mPerson->mName<< ")" << endl;
 			tempQ.pop();	
 		}
 		moveToNextElement();
	}

}
void Graph::moveToNextElement()
{ 
	if(currentLevelPointer == currentLevelUnfriends.size())
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
		for(int i = 0; i < nextLevelUnfriends.size(); i++)
		{
			nextLevelUnfriends.pop();
		}
		mPerson = currentLevelUnfriends.front();
		currentLevelUnfriends.pop();	
	}
	else{
		std::cout << "mPerson is End" << std::endl;
		mPerson = mEnd;
	}
	drawGraph(mPerson);
}