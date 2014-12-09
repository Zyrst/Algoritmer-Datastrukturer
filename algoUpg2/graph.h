#include <queue>
#include <utility>

class Person;

class Graph{
public:
	void drawGraph(Person* person);
private:
	
	void moveToNextLevel();
	void moveToNextElement();

	Person* mPerson;
	Person* mEnemy;
	Person* mDefault;

	std::queue<Person*> currentLevelUnfriends;
	std::queue<Person*> nextLevelUnfriends;
};