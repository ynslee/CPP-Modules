
#include "Zombie.hpp"

Zombie::Zombie() {};
Zombie::~Zombie() {
	std::cout << this->_Name << ": Pew! Pew! I have been destroyed" << std::endl;
};

void	Zombie::announce()
{
	std::cout << this->_Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_Name = name;
}

std::string	Zombie::getName() const
{
	return(this->_Name);
}
