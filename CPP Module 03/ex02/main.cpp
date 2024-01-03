#include "FragTrap.hpp"

int main(void)
{
	FragTrap num1;
	FragTrap num2("Elmo");
	ClapTrap clap("random");

	std::cout << "\n****HIGH FIVE GUYS****\n" << std::endl;

	num1.highFivesGuys();
	num2.highFivesGuys();
	
	std::cout << "\n*******************\n" << std::endl;

	clap.attack("itself");
	clap.takeDamage(20);
	clap.beRepaired(10);

	std::cout << "\n*******************\n" << std::endl;
	
	num1.attack("Elmo");
	num2.takeDamage(30);
	num2.attack("Chuchi");
	num1.takeDamage(30);
	num2.attack("Chuchi");
	num1.takeDamage(30);
	num2.attack("Chuchi");
	num1.takeDamage(30);
	num1.beRepaired(50);
	num1.attack("Elmo");
	num2.takeDamage(30);
	num1.attack("Elmo");
	num2.takeDamage(30);
	num1.attack("Elmo");
	num2.takeDamage(30);
	
	std::cout << "\n****HIGH FIVE GUYS****\n" << std::endl;

	num1.highFivesGuys();
	num2.highFivesGuys();

	std::cout << "\n*******************\n" << std::endl;
	return (0);
}