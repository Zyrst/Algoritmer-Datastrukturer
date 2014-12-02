#include "person.h"
#include <queue>

class Graph{
public:
	static void drawGraph(Person* person);
private:
	Graph();
	~Graph();
	static void moveToNextLevel();

	Person* mPerson;
	Person* mEnemy;

	std::queue<Person*> currentLevelUnfriends;
	std::queue<Person*> nextLevelUnfriends;
};