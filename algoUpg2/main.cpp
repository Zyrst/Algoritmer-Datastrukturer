#include "person.h"
#include <queue>

using namespace std;

queue<Person*> q; 
int main()
{
	Person* eva = new Person("Eva");
	Person* adolf = new Person("Adolf");
	Person* Josef = new Person("Josef");

	// Get it? ;D
	adolf->addToUnfriend(Josef);
	eva->addFriend(adolf);

	Josef->printEnemies();
	eva->printFriends();
}