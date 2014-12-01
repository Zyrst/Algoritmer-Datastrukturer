#include "person.h"

Person::Person(std::string name) :
	mName(name)
{}

Person::~Person()
{
	delete this;
}

void Person::addFriend(Person* person)
{
	// We can't add ourselves to friends.
	if(person == this)
		return;

	bool found =  false;
	std::queue<Person*> tempQueue;

	// We can't add the same friends twice.
	for (int i = 0; i < friends.size(); i++)
	{
		Person* tempPerson = friends.front();
		friends.pop();
		if(!found)
			if(tempPerson == person)
			{
				found = true;
				continue;
			}
		tempQueue.push(tempPerson);
		/* code */
	}
	friends = tempQueue;
}

void Person::addToUnfriend(Person* person)
{
	// No goddamn fjortispoesi about
	// I'm my own worst enemy....
	if(person == this)
		return;

	// We can't add the same enemy twice.
		bool found =  false;
	std::queue<Person*> tempQueue;

	// We can't add the same enemies twice.
	for (int i = 0; i < enemies.size(); i++)
	{
		Person* tempPerson = enemies.front();
		enemies.pop();
		if(!found)
			if(tempPerson == person)
			{
				found = true;
				continue;
			}
		tempQueue.push(tempPerson);
		/* code */
	}
	enemies = tempQueue;

	
	enemies.push(person);
	person->addToUnfriend(this);
}


void Person::enemyOfMyEnemy()
{
	std::queue<Person*> tempEnemies = enemies;
	std::queue<Person*> tempNewFriends;


	for (int i = 0; i < enemies.size(); i++)
	{
		Person* tempPerson = enemies.front();
		enemies.pop();
		std::queue<Person*> tempFriends = tempPerson->enemies;

		for (int k = 0; k < tempPerson->enemies.size(); k++)
		{
			Person* tempFriend = tempPerson->enemies.front();
			tempPerson->enemies.pop();
			tempNewFriends.push(tempFriend);
		}
		tempPerson->enemies = tempFriends;
	}
	enemies = tempEnemies;
	for (int i = 0; i < tempNewFriends.size(); i++)
	{
		Person* newFriend = tempNewFriends.front();
		tempNewFriends.pop();
		friends.push(newFriend);	
	}	 
}

void Person::enemyOfMyFriend()
{
	std::queue<Person*> tempFriends = friends;
	std::queue<Person*> tempNewEnemies;

	for (int i = 0; i < friends.size(); i++)
	{
		Person* tempPerson = friends.front();
		friends.pop();

		std::queue<Person*> tempEnemies = tempPerson->enemies;
		for (int k = 0; k < tempPerson->enemies.size(); k++)
		{
			Person* tempEnemy = tempPerson->enemies.front();
			enemies.pop();
			tempNewEnemies.push(tempEnemy);
		}
		tempPerson->enemies = tempEnemies;
	}

	friends = tempFriends;
	for (int i = 0; i < tempNewEnemies.size(); ++i)
	{
		Person* newEnemy = tempNewEnemies.front();
		tempNewEnemies.pop();
		enemies.push(newEnemy);
	}
}

void Person::printFriends()
{
	std::queue<Person*> backup = friends;
	for (int i = 0; i < friends.size(); i++)
	{
		Person* tempPerson = friends.front();
		friends.pop();
		std::cout << tempPerson->mName << std::endl;	
	}
	friends = backup;
}

void Person::printEnemies()
{
	std::queue<Person*> backup = enemies;
	for (int i = 0; i < enemies.size(); i++)
	{
		Person* tempPerson = enemies.front();
		enemies.pop();	
		std::cout << tempPerson->mName << std::endl;
	}
	enemies = backup;
}

