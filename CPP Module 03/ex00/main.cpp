#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap Name("Chuck 🐕");
	ClapTrap yesName("Sunny");
	ClapTrap copy;
	copy = Name;

	copy.attack("Sunny");
	Name.attack("Sunny");
	yesName.takeDamage(2);
	yesName.takeDamage(6);
	yesName.beRepaired(10);
	yesName.takeDamage(7);
	yesName.beRepaired(1000);
	yesName.beRepaired(INT_MAX);
	yesName.takeDamage(9);
	yesName.beRepaired(1);
	yesName.beRepaired(1);
	yesName.beRepaired(1);
	yesName.beRepaired(1);
	yesName.beRepaired(1);
	yesName.beRepaired(1);
	yesName.beRepaired(1);
	yesName.beRepaired(1);
	Name.beRepaired(10);
	Name.takeDamage(INT_MAX);
	Name.beRepaired(10);

	return (0);
}