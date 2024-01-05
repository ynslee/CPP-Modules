#include "Dog.hpp"

Dog::Dog() : Animal(){
	std::cout << "Constructor for Dog is called 🐕" << std::endl;
	this->_type = "Dog";
	this->notInUse = new Brain(); 
}

Dog::~Dog(){
	std::cout << "Destructor for Dog is called 🐕" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Copy constructor for Dog is called 🐕" << std::endl;
}

Dog&	Dog::operator=(const Dog &other){
	std::cout << "Dog copy assignment constructor called 🐕" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << "🐕Awoooo Woof ruff🐕" << std::endl;
}

Brain &Dog::getBrain() {
	return *this->notInUse;
}