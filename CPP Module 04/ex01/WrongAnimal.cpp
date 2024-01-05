#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	std::cout << "Constructor for WrongAnimal is called" << std::endl;
	this->_type = "random WrongAnimal";
	return;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "Destructor for WrongAnimal is called" << std::endl; 
}

WrongAnimal::WrongAnimal(const WrongAnimal &other){
	std::cout << "Copy constructor for : ["<< other._type << "] WrongAnimal is called" << std::endl;
	*this = other;
	return ;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other){
    std::cout << "WrongAnimal copy assignment constructor called. " << this->_type << " is replaced by " << other._type << std::endl;
    if (this != &other){
        this->_type = other._type;
    }
    return (*this);
}

std::string	WrongAnimal::getType() const {
	return (this->_type);
}

void	WrongAnimal::setType(std::string type){
	_type = type;
}

void	WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal goes 'EEEEHAAAW I'm not an animal🤖'" << std::endl;
}
