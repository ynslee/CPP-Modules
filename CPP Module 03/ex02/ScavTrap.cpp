#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap constructor with default name: " << this->_name << "🦅 is called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;	
}

ScavTrap::ScavTrap(std::string _player) : ClapTrap(_player) {
	std::cout << "ScavTrap constructor with input: " << this->_name << "🦅 is called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other){
	std::cout << "ScavTrap Copy constructor for " << this->_name << "🦅 is called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "Destructor for ScavTrap: " << this->_name << "🦅 is called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other){
	std::cout << "ScavTrap: " << this->_name << "🦅 is taken over by: " << other._name << "🦅 using copy assignment constructor!" << std::endl;
	if (this != &other){
		ClapTrap::operator=(other);
	}
	return *this;
}

void	ScavTrap::attack(const std::string &target){
	if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap: " << this->_name << "🦅 does not have enough hitPoints!" << std::endl;
		return ;
	}
	else if (this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap: " << this->_name << "🦅 does not have enough energyPoints!" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ScavTrap: " << this->_name << "🦅 attacks " << target << ", causing " << this->_attackDamage << " points of damage!(" << this->_energyPoints << " energy points)" << std::endl;
}

void	ScavTrap::guardGate(){
	if (this->_hitPoints == 0){
		std::cout << "ScavTrap: " << this->_name << "🦅 is already dead and can no longer function 💀" << std::endl;
		return ;
	}
	else if (this->_energyPoints == 0) {
		std::cout << "ScavTrap: " << this->_name << "🦅 is out of energy and can't do gate keeping 💂‍♂️" << std::endl;
		return ;
	}
	std::cout << "Hold The Door! ScavTrap: " << this->_name << "🦅 is now in a gate keeper mode " << std::endl;
}