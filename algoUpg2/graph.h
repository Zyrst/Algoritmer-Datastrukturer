#include <queue>
#include <utility>

class Person;

class Graph{
public:
	void drawGraph(Person* person);
private:
	void draw(std::vector<std::pair<Person*, std::pair<int, bool>>>);
	void moveToNextLevel();
	void moveToNextElement();
	bool isNotEnemy(Person* person);
	bool isNotFriend(Person* person);
	Person* mPerson;
	Person* mEnemy;
	Person* mDefault;

	std::queue<Person*> currentLevelUnfriends;
	std::queue<Person*> nextLevelUnfriends;
};