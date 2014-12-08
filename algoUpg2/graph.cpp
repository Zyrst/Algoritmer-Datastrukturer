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
	std::set<Person*, std::set<int, bool>> EnemySet;
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
	 			if(!enemyAlreadyAdded(mEnemy) && isNotEnemy(mEnemy))
 				{
 					mDefault->addFriend(mEnemy);
 					bool tempB = true;
 					std::set<int, bool> _set(currentPaths, tempB);
 					EnemySet.insert(mEnemy, _set);
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
 					mFriend = tempF.front();
 					nextLevelUnfriends.push(mFriend);

 					//Adds the first enemy found.	
 					if(!enemyAlreadyAdded(mFriend) && isNotFriend(mFriend))
 					{
 						mDefault->addFriend(mFriend);
 						bool tempB = false;
 						std::set<int, bool> _set;
 						_set(currentPaths, tempB);
 						EnemySet.insert(mFriend, _set);
 						return;
 					}
 					cout << mEnemy->mName << " is enemy of: " << mPerson->mName<<endl;
 					tempF.pop();	
 				}
 			}
		}
 		moveToNextElement();
	}
	draw(EnemySet);
}


void draw(set<Person* , set<int, bool>> _s)
{
	//INSERT SUPER ALGORITM HERE.
	for(int i = 0; i < _s.size(); i++)
	{
		Person* _person = _s[i];
		std::set<int, bool> _value = _s[i]->value_comp; 
		for(int k = 1; _s.size(); k++)
		{
			Person* _p1 = _s[k];
			if(_person == _p1)
			{
				std::set<int, bool> _v1 = _s[k]->value_comp;
				if(_value < _v1) _s.erase(k);
				if(_value > _v1) _s.erase(i);
			}


		}

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
		currentPaths++;
		mPerson = currentLevelUnfriends.front();
		currentLevelUnfriends.pop();	
	}

	else if(!doneWithEnemies){
		currentPaths = 0;
		mPerson = mDefault;
		doneWithEnemies = true;
	}

	else
	{
		mPerson = NULL;
	}
	drawGraph(mPerson);
}