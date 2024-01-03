#include "ClapTrap.hpp"
#include <string>

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	_name = "Chuchi";
	std::cout << "ClapTrap with default name: " << _name << "👏 has been called" << std::endl;
}

ClapTrap::ClapTrap(std::string _player) {
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	_name = _player;
	std::cout << "ClapTrap: " << _name << "👏 has been called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "Copy constructor ClapTrap👏 has been called" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor for: " << this->_name << "👏 is called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
	std::cout << "ClapTrap: " << this->_name << "👏 has taken over by: " << other._name << "👏 using copy assignment constructor!" << std::endl;
	if (this != &other){
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

void	ClapTrap::attack(const std::string &target){
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap: " << this->_name << "👏 does not have enough hitPoints!" << std::endl;
		return ;
	}
	else if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap: " << this->_name << "👏 does not have enough energyPoints!" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap: " << this->_name << "👏 attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
  if (this->_hitPoints <= 0)
  {
	std::cout << "ClapTrap: " << this->_name << "👏 is already dead!" << std::endl;
	return;
  }

  this->_hitPoints -= amount;
  if (this->_hitPoints <= 0)
  {
	this->_hitPoints = 0;
	std::cout << "ClapTrap: " << this->_name << "👏 has taken " << amount
              << " points of damage and now is dead with 0 hit points!"
              << std::endl;
    return;
  }
  std::cout << "ClapTrap: " << this->_name << "👏 has taken " << amount
            << " points of damage and now has " << this->_hitPoints
            << " hit points(health) left!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (this->_hitPoints == 0){
		std::cout << "ClapTrap: " << this->_name << "👏 is already dead and there's nothing you can do about it!" << std::endl;
		return ;
	}
	else if (this->_energyPoints == 0) {
		std::cout << "ClapTrap: " << this->_name << "👏 is out of energy and can't repair itself! :( " << std::endl;
		return ;
	} else if (amount > (unsigned int)(INT_MAX - this->_hitPoints))
		amount = INT_MAX - this->_hitPoints;
	this->_hitPoints += amount;
	this->_energyPoints--;
	if (this->_hitPoints > 10)
		this->_hitPoints = 10;
	std::cout << "ClapTrap: " << this->_name << "👏 has restored " << amount
			  << " of energy and now has " << this->_hitPoints << " hit points(health) left!" << std::endl; 
}
