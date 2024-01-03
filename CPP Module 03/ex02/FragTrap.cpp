#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap constructor with default name: " << this->_name << "🐸 is called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;	
}

FragTrap::FragTrap(std::string _player) : ClapTrap(_player) {
	std::cout << "FragTrap constructor with input: " << this->_name << "🐸 is called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other){
	std::cout << "FragTrap Copy constructor for " << this->_name << "🐸 is called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "Destructor for FragTrap: " << this->_name << "🐸 is called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other){
	std::cout << "FragTrap: " << this->_name << "🐸 is taken over by: " << other._name << "🐸 using copy assignment constructor!" << std::endl;
	if (this != &other){
		ClapTrap::operator=(other);
	}
	return *this;
}

void	FragTrap::attack(const std::string &target){
	if (this->_hitPoints <= 0)
	{
		std::cout << "FragTrap: " << this->_name << "🐸 does not have enough hitPoints to attack!" << std::endl;
		return ;
	}
	else if (this->_energyPoints <= 0)
	{
		std::cout << "FragTrap: " << this->_name << "🐸 does not have enough energyPoints to attack!" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "FragTrap: " << this->_name << "🐸 attacks " << target << ", causing " << this->_attackDamage << " points of damage!(" << this->_energyPoints << " energy points)" << std::endl;
}

void	FragTrap::highFivesGuys(){
	if (this->_hitPoints == 0){
		std::cout << "FragTrap: " << this->_name << "🐸 is already dead and can't hold up its' hands 🧟‍♂️" << std::endl;
		return ;
	}
	else if (this->_energyPoints == 0) {
		std::cout << "FragTrap: " << this->_name << "🐸 is out of energy and can't do high five 💀 " << std::endl;
		return ;
	}
	std::cout << "The great power comes with hands- FragTrap: " << this->_name << "🐸 is now high fiving guys 🙌 " << std::endl;
}