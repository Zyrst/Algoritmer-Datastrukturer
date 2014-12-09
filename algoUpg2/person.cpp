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
	if (person == this)
	{
		return;
	}
	// Creates a copy of the persons friends.
	// We will empty it in the search for a copy.
	std::queue<Person*> tempQueue = friends;

	// We can't add the same friends twice.
	while(!tempQueue.empty())
	{		
		// Takes the front item and checks if
		// it's the same as the one we try to add.
		if(tempQueue.front() == person)
		{
			return;
		}
		tempQueue.pop();
	}
	//Friends for ever.
	friends.push(person);
}

void Person::addToUnfriend(Person* person)
{
	// No goddamn fjortispoesi about
	// I'm my own worst enemy....
	if(person == this)
		return;

	// Creates a copy of the persons enemies.
	// We will empty it in the search for a copy.
	std::queue<Person*> tempQueue = enemies;

	// We can't add the same enemies twice.
	while(!tempQueue.empty())
	{
		// Takes the front item and checks if
		// it's the same as the one we try to add.
		if(tempQueue.front() == person)
		{
			return;
		}
		tempQueue.pop();		
	}
	// Apperently sir, we made an enemy.
	enemies.push(person);
	
}

void Person::printFriends()
{
	std::queue<Person*> backup = friends;
	while(!backup.empty())
	{
		std::cout << backup.front()->mName << " ";	
		backup.pop();
	}
}

void Person::printEnemies()
{
	std::queue<Person*> backup = enemies;
	while(!backup.empty()) 
	{
		std::cout << backup.front()->mName << " ";
		backup.pop();
	}
}