#include "person.h"

class Graph{
public:
	static void drawGraph(Person* person);
private:
	Graph();
	~Graph();
	static void killAll();
	static void getNextUnfriend();
	static void moveToNextLevel();

	Person* mPerson;
	Person* mEnemy;

	int currentFriendPosition = 0;
	int currentEnemyPosition = 0;
};