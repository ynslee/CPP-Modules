#include "Weapon.hpp"

Weapon::Weapon(std::string _weapon) : _type(_weapon) {};
Weapon::~Weapon(){};

std::string	const &Weapon::getType() const {
	return (this->_type);
}

void	Weapon::setType(std::string type){
	this->_type = type;
}