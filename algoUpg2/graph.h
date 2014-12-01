#include "person.h"

class Graph{
public:
	static void drawGraph(Person* person);
private:
	Graph();
	~Graph();
	static void killAll();
	static void getNextUnfriend();
	static void moveToNextElement();

	Person* mPerson;
	Person* mFriend;
	Person* mEnemy;

	int currentFriendPosition = 0;
	int currentEnemyPosition = 0;
};