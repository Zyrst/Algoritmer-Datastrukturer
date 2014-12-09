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
 					mDefault->addFriend(mEnemy);
 					std::pair<int, bool> _set(currentPaths, true);
 					std::pair<Person*, std::pair<int, bool>> EnemyPair(mEnemy, _set);
 					vec.push_back(EnemyPair);
 					mEnemy->marked = true;
 					return;
 				}
 				cout << mEnemy->mName << " is enemy of: " << mPerson->mName<<endl;
 				tempQ.pop();	
 			}
		}
 		moveToNextElement();
	}
	draw(vec);
}

// recives a package in form of a vector containing pairs with person and a pair with relevant data.
void Graph::draw(std::vector<pair<Person*, pair<int, bool>>> _s) 
{
	for(int i =	0; i < _s.size(); i++)
	{
		Person* 				p = _s[i].first;
		std::pair<int, bool> 	v = _s[i].second;

		if(v.first % 2 == 0)
			mDefault->addFriend(p);
		else 
			mDefault->addToUnfriend(p);
	}
}




//Returns false if it's an enemy
//else true
bool Graph::isNotEnemy(Person* person)
{
	std::queue<Person*> tempQ = mDefault->enemies;
	for (int i = 0; i < tempQ.size(); i++)
	{
		if (tempQ.front() == person)
		{
			return false;
		}
		else
			tempQ.pop();
	}
	return true;	
}
// Returns false if person is found in friends.
bool Graph::isNotFriend(Person* person)
{
	std::queue<Person*> tempQ = mDefault->friends;
	for (int i = 0; i < tempQ.size(); i++)
	{
		if(tempQ.front() == person)
		{
			return false;
		}
		tempQ.pop();
	}
	return true;
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