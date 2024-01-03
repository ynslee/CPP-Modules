#include "Animal.hpp"

Animal::Animal(){
	std::cout << "Constructor for Animal is called" << std::endl;
}

Animal::~Animal(){
	std::cout << "Destructor for Animal is called" << std::endl; 
}

Animal::Animal(const Animal &other){
	
}

std::string	Animal::getType() const {
	return (this->_type);
}

void	Animal::setType(std::string type){
	_type = type;
}

void	Animal::makeSound(){
	std::cout << "Animal goes Ribbitweet Meowowlf" << std::endl;
}