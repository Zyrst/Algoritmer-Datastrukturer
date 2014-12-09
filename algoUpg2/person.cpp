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

	std::queue<Person*> tempQueue = friends;

	// We can't add the same friends twice.
	while(!tempQueue.empty())
	{		
		if(tempQueue.front() == person)
		{
			return;
		}
		tempQueue.pop();
	}
	friends.push(person);
	std::cout << "Added " << person->mName << " to " << mName << std::endl;
}

void Person::addToUnfriend(Person* person)
{
	// No goddamn fjortispoesi about
	// I'm my own worst enemy....
	if(person == this)
		return;


	std::queue<Person*> tempQueue = enemies;

	// We can't add the same enemies twice.
	while(!tempQueue.empty())
	{
		if(tempQueue.front() == person)
		{
			return;
		}
		tempQueue.pop();		
	}
	enemies.push(person);
	
}

void Person::printFriends()
{
	std::queue<Person*> backup = friends;
	for (int i = 0; i < friends.size(); i++)
	{
		std::cout << friends.front()->mName << std::endl;	
		friends.pop();
	}
	friends = backup;
}

void Person::printEnemies()
{
	std::queue<Person*> backup = enemies;
	for (int i = 0; i < enemies.size(); i++)
	{
		std::cout << enemies.front()->mName << std::endl;
		enemies.pop();
	}
	enemies = backup;
}