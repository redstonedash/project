// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016

// Marines are trying to "de-bug" an area (haha . . . haha)
// However something's up with this code . . . figure out what's going wrong
// When you're finished, there should be no compiler errors or warnings
// The encounter should also run and finish correctly as per the rules in the comments

// In many cases there are differences between what's in otherwise identical sections
// for Marines and Zerglings. It's good to be able to tell what the differences are
// and why they might be important.

// What's efficient and inefficient? Why?
// What uses more memory and what doesn't? Why?

// Last modified by Terry Nguyen (terryn@aie.edu.au)
// 10/09/2018

#include <iostream>

using std::cout;
using std::endl;

int firstLivingMarine = 0;
int firstLivingZerg = 0;

class Marine {
private:
	int health = 20;
	int damage = 5;
public:
	int attack() {
		return damage;
	}
	void takeDamage(int damage) {
		health -= damage;
		if (health < 0) {
			firstLivingMarine++;
			health = 0;
		}
	}
	bool isAlive() {
		if (health <= 0) {
			return false;
		}
		return true;
	}
};
class Zergling {
private:
	int health = 10;
	int damage = 4;
public:
	int attack() {
		return damage;
	}
	void takeDamage(int damage) {
		health -= damage;
		if (health < 0) {
			firstLivingZerg++;
			health = 0;
		}
	}
	bool isAlive() {
		if (health <= 0) {
			return false;
		}
		return true;
	}
};


// Is there a Marine Alive?
bool marineAlive(Marine * swarmArr, size_t arrSize){
	for (int i = 0; i < arrSize; i++) {
		if (swarmArr[i].isAlive()) {
			return true;
		}
	}
	return false;
}

// Is there a zergling Alive
bool zerglingAlive(Zergling * swarmArr, size_t arrSize){
	for (int i = 0; i < arrSize; i++) {
		if (swarmArr[i].isAlive()) {
			return true;
		}
	}
	return false;
}
const size_t squadSize = 10;
const size_t swarmSize = 10;
int main()
{
	Marine squad[squadSize];
	Zergling swarm[swarmSize];

	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!" << "\n";
	// Attack each other until only one team is left alive
	while (marineAlive(squad, squadSize) && zerglingAlive(swarm, swarmSize))
	{
		if (marineAlive(squad, squadSize)) // if there's at least one marine alive
		{
			for (size_t i = firstLivingMarine; i < squadSize; i++) // go through the squad
			{
				// each marine will attack the first zergling in the swarm
				cout << i << "A marine fires for " << squad[i].attack() << " damage. " << endl;
				int damage = squad[i].attack();
				swarm[firstLivingZerg].takeDamage(damage);
				if (!swarm[firstLivingZerg].isAlive()) // if the zergling dies, it is marked as such
				{
					cout << "The zergling target dies" << endl;
				}
			}
		}
		if (zerglingAlive(swarm, swarmSize)) // if there's at least one zergling alive
		{
			for (size_t i = firstLivingZerg; i < swarmSize; i++) // go through the swarm
			{
				// each zerg will attack the first marine in the squad
				cout << i << "A zerg fires for " << swarm[i].attack() << " damage. " << endl;
				int damage = swarm[i].attack();
				squad[firstLivingMarine].takeDamage(damage);
				if (!squad[firstLivingMarine].isAlive()) // if the zergling dies, it is marked as such
				{
					cout << "The marine target dies" << endl;
				}
			}
		}
	}

	// Once one team is completely eliminated, the fight ends and one team wins
	cout << "The fight is over. ";
	if (marineAlive(squad, squadSize))
	{
		cout << "The Marines win." << endl;
	} else {
		cout << "The Zerg win." << endl;
	}
	return 0;
}
