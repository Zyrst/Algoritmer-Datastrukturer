#include <queue>
#include "person.h"

class Graph{
public:
	void drawGraph(Person* person);
private:
	void moveToNextLevel();
	void moveToNextElement();
	bool enemyAlreadyAdded(Person* person);
	
	Person* mPerson;
	Person* mEnemy;
	Person* mDefault;

	std::queue<Person*> currentLevelUnfriends;
	std::queue<Person*> nextLevelUnfriends;

};