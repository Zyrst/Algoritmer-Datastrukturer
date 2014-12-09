#include "person.h"
#include "graph.h"
#include <iostream>
using namespace std;

int 	currentLevelPointer = 0;
int 	currentPaths 		= 0;
bool 	doneWithEnemies 	= false;
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
		if(!doneWithEnemies)
		{
			//Temorary queue contains Persons enemies
			std::queue<Person*> tempQ = mPerson->enemies;
 			for(int i = 0; i < mPerson->enemies.size(); i++)
 			{
 				mEnemy = tempQ.front();
 				nextLevelUnfriends.push(mEnemy);

 				//Adds the first enemy found.
	 			if(!isNotFriend(mEnemy) && isNotEnemy(mEnemy))
 				{
 					mDefault->addFriend(mEnemy);
 					std::pair<int, bool> _set(currentPaths, true);
 					std::pair<Person*, std::pair<int, bool>> EnemyPair(mEnemy, _set);
 					vec.push_back(EnemyPair);
 					return;
 				}
 				cout << mEnemy->mName << " is enemy of: " << mPerson->mName<<endl;
 				tempQ.pop();	
 			}
		}
		else if(doneWithEnemies)
		{
			std::queue<Person*> tempF = mPerson->friends;
 			for(int i = 0; i < mPerson->friends.size(); i++)
 			{
 				for(int i = 0; i < mPerson->enemies.size(); i++)
 				{
 					Person* mFriend = tempF.front();
 					nextLevelUnfriends.push(mFriend);

 					//Adds the first enemy found.	
 					if(!isNotEnemy(mFriend) && isNotFriend(mFriend))
 					{
 						mDefault->addFriend(mFriend);
 						std::pair<int, bool> _set(currentPaths, false);
 						std::pair<Person*, std::pair<int, bool>> EnemyPair(mFriend, _set);
 						vec.push_back(EnemyPair);
 						return;
 					}
 					cout << mFriend->mName << " is friend with: " << mPerson->mName<<endl;
 					tempF.pop();	
 				}
 			}
 			doneWithEnemies = false;
		}
 		moveToNextElement();
	}
	draw(vec);
}

// recives a package in form of a vector containing pairs with person and a pair with relevant data.
void Graph::draw(std::vector<pair<Person*, pair<int, bool>>> _s) 
{
	//INSERT SUPER ALGORITM HERE.
	for(int i = 0; i < _s.size(); i++)
	{
		std::pair<Person*, pair<int, bool>> _p0 = _s[i];
		std::pair<int, bool> _v0 = _p0.second;
		for(int k = 1; _s.size(); k++)
		{
			std::pair<Person*, pair<int, bool>> _p1 = _s[i];
			if(_p0.first == _p1.first)
			{
				std::pair<int, bool> _v1 = _s[k].second;
				if(_v0.first < _v1.first) _s.erase(_s.begin() + k);
				if(_v0.first > _v1.first) _s.erase(_s.begin() + i);
			}
		}
	}
	for(int i =	0; i < _s.size(); i++)
	{
		Person* 				p = _s[i].first;
		std::pair<int, bool> 	v = _s[i].second;

		if(v.second == true)
			mDefault->addToUnfriend(p);
		else if(v.second == false)
			mDefault->addFriend(p);
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
	if(doneWithEnemies){
		if(currentLevelUnfriends.empty())
			moveToNextLevel();

		else{
			mPerson = currentLevelUnfriends.front();
			currentLevelUnfriends.pop();
			currentLevelPointer++;
			drawGraph(mPerson);		
		}
	}
	else if(!doneWithEnemies){
		doneWithEnemies = true;
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