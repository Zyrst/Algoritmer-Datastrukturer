#include "person.h"
#include <vector>

using namespace std;

vector<Person*> v;
int main()
{
	// Försök komma på ett smart sätt att rita upp en algoritm..
	// Vet inte ens vad uppgiften är bara lagt en grund med personer.
	Person* eva = new Person("Eva");
	Person* adolf = new Person("Adolf");
	Person* Josef = new Person("Josef");

	// Get it? ;D
	adolf->addToUnfriend(Josef);
	eva->addFriend(adolf);

	Josef->printEnemies();
	eva->printFriends();
}