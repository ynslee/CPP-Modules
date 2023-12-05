#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
	_weapon = NULL;
};
HumanB::~HumanB() {};

void	HumanB::attack() const{
	if (this->_weapon == NULL)
		std::cout << this->_name << "went crazy with barehands" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << _weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon){
	this->_weapon = &weapon;
}