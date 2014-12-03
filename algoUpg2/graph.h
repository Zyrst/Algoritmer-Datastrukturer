#include <queue>
#include "person.h"

class Graph{
public:
	void drawGraph(Person* person);
private:
	void moveToNextLevel();
	void moveToNextElement();

	Person* mPerson;
	Person* mEnemy;
	std::queue<Person*> currentLevelUnfriends;
	std::queue<Person*> nextLevelUnfriends;

};