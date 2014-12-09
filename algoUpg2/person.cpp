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

	friends.push(person);

}

void Person::addToUnfriend(Person* person)
{
	// No goddamn fjortispoesi about
	// I'm my own worst enemy....
	if(person == this)
		return;

	bool found =  false;
	std::queue<Person*> tempQueue;

	// We can't add the same enemies twice.
	for (int i = 0; i < enemies.size(); i++)
	{
		Person* tempPerson = enemies.front();
		enemies.pop();
		if(!found)
		{
			if(tempPerson == person)
			{
				found = true;
				continue;
			}
		}
		tempQueue.push(tempPerson);
	}
	enemies = tempQueue;
	
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