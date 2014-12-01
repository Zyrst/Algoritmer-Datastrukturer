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

	// We can't add the same friends twice.
	for(auto p : friends)
		if(person == p)
			return;

	// We can't add a person that is on our unfriend list.
	for(auto persons : enemies)
		if(persons == person)
			return;

	friends.push_back(person);
}

void Person::removeFriend(Person* person)
{
	// Finds all the friends to keep.
	// Adds them to a temp vector 
	std::vector<Person*> temp;
	for(auto persons : friends)
		if(persons != person)
			temp.push_back(persons);

	friends = temp;
}

void Person::addToUnfriend(Person* person)
{
	// No goddamn fjortispoesi about
	// I'm my own worst enemy....
	if(person == this)
		return;

	// We can't add the same enemy twice.
	for(auto p : enemies)
		if(person == p)
			return;

	// Removes from friends. (Seems obvious)
	for(auto persons : friends)
		if(persons == person)
			removeFriend(person);	

	enemies.push_back(person);
	person->addToUnfriend(this);
}

void Person::removeUnfriend(Person* person)
{
	std::vector<Person*> temp;
	for(auto persons : enemies)
		if(persons != person)
			temp.push_back(persons);

	enemies = temp;
}

void Person::enemyOfMyEnemy()
{
	for(auto i : enemies)
	{
		for(auto k : i->getEnemies())
			addFriend(k);
	}
}

void Person::enemyOfMyFriend()
{
	for(auto i : friends)
		for(auto k : i->getEnemies())
			addToUnfriend(k);
	}

std::vector<Person*> Person::getEnemies()
{
	return enemies;
}

std::vector<Person*> Person::getFriends()
{
	return friends;
}

void Person::printFriends()
{
	for(auto i : friends)
		std::cout << i->getName() << std::endl;
}

void Person::printEnemies()
{
	for(auto k : enemies)
		std::cout << k->getName() << std::endl;
}

std::string Person::getName()
{
	return mName;
}