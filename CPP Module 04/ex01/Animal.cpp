#include "Animal.hpp"

Animal::Animal(){
	std::cout << "Constructor for Animal is called" << std::endl;
	this->_type = "random animal";
	return;
}

Animal::~Animal(){
	std::cout << "Destructor for Animal is called" << std::endl; 
}

Animal::Animal(const Animal &other){
	std::cout << "Copy constructor for : ["<< other._type << "] animal is called" << std::endl;
	*this = other;
	return ;
}

Animal& Animal::operator=(const Animal &other){
    std::cout << "Animal copy assignment constructor called. " << this->_type << " is replaced by " << other._type << std::endl;
    if (this != &other){
        this->_type = other._type;
    }
    return (*this);
}


std::string	Animal::getType() const {
	return (this->_type);
}

void	Animal::setType(std::string type){
	_type = type;
}

void	Animal::makeSound() const {
	std::cout << "Animal goes Ribbitweet Meowowlf" << std::endl;
}