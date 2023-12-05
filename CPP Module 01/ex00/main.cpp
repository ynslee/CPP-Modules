
#include "Zombie.hpp"

int main(void)
{
	Zombie *FirstOne = newZombie("Sunny");
	FirstOne->announce();
	
	delete FirstOne;
	Zombie *SecondOne = newZombie("Chuchi");
	SecondOne->announce();
	randomChump("Hive Zombies");

	delete SecondOne;

	return (0);
}