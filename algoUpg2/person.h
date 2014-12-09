#pragma once
#include <queue>
#include <string>
#include <iostream>

class Person
{
public:
	Person(std::string name);
	~Person();

	void addFriend(Person *person);
	void addToUnfriend(Person *person);

	bool marked = false;
	//String methods
	void printFriends();
	void printEnemies();

	std::string mName;
	std::queue<Person*> friends;
	std::queue<Person*> enemies; 
};