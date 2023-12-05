#include "Zombie.hpp"

/**
 * @brief when deleting the array of memory space, you just need to delete[], no numbers are needed
 * to put inside the bracket.
 * 
 */
int main()
{
	int crew = 5;

	Zombie *Brain_Brians = zombieHorde(crew, "Brain_Brians");
	for(int i = 0; i < crew; i++)
	{
		Brain_Brians[i].announce();
	}
	delete[] Brain_Brians;
	return(0);
}