#pragma once
#include <vector>
#include <string>
#include <iostream>

class Person
{
public:
	Person(std::string name);
	~Person();

	void addFriend(Person *person);
	void removeFriend(Person *person);
	void addToUnfriend(Person *person);
	void removeUnfriend(Person *person);

	void enemyOfMyEnemy();
	void enemyOfMyFriend();

	std::vector<Person*> getFriends();
	std::vector<Person*> getEnemies();
	//String methods
	void printFriends();
	void printEnemies();
	std::string getName();

private:
	std::string mName;
	std::vector<Person*> friends;
	std::vector<Person*> enemies; 
};