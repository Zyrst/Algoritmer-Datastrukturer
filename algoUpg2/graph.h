#include <queue>
#include <set>

class Person;

class Graph{
public:
	void drawGraph(Person* person);
private:
	void draw(std::set<Person*, std::set<int,bool>> _s);
	void moveToNextLevel();
	void moveToNextElement();
	bool enemyAlreadyAdded(Person* person);
	bool isNotEnemy(Person* person);
	Person* mPerson;
	Person* mEnemy;
	Person* mDefault;

	std::queue<Person*> currentLevelUnfriends;
	std::queue<Person*> nextLevelUnfriends;
};