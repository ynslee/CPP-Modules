#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap num1;
	ScavTrap num2("Elmo");
	ClapTrap clap("random");

	std::cout << "\n****HODOR! GUARD THE GATE!****\n" << std::endl;

	num1.guardGate();
	num2.guardGate();
	
	std::cout << "\n*******************\n" << std::endl;

	clap.attack("itself");
	clap.takeDamage(20);
	clap.beRepaired(10);

	std::cout << "\n*******************\n" << std::endl;
	
	num1.attack("Elmo");
	num2.takeDamage(20);
	num2.attack("Chuchi");
	num1.takeDamage(20);
	num2.attack("Chuchi");
	num1.takeDamage(20);
	num2.attack("Chuchi");
	num1.takeDamage(20);
	num2.attack("Chuchi");
	num1.takeDamage(20);
	num1.beRepaired(50);
	num1.attack("Elmo");
	num2.takeDamage(20);
	num1.attack("Elmo");
	num2.takeDamage(20);
	num1.attack("Elmo");
	num2.takeDamage(20);
	num1.attack("Elmo");
	num2.takeDamage(20);
	
	std::cout << "\n****HODOR! GUARD THE GATE!****\n" << std::endl;

	num1.guardGate();
	num2.guardGate();

	std::cout << "\n*******************\n" << std::endl;
	return (0);
}