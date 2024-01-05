#include "Dog.hpp"

Dog::Dog() : Animal(){
	std::cout << "Constructor for Dog is called 🐕" << std::endl;
	this->_type = "Dog";
	this->notInUse = new Brain(); 
}

Dog::~Dog(){
	std::cout << "Destructor for Dog is called 🐕" << std::endl;
	delete this->notInUse;
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Copy constructor for Dog is called 🐕" << std::endl;
	this->notInUse = new Brain(*other.notInUse);
}

Dog&	Dog::operator=(const Dog &other){
	std::cout << "Dog copy assignment constructor called 🐕" << std::endl;
	if (this != &other)
		this->_type = other._type;
	*this->notInUse = *other.notInUse;
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << "🐕Awoooo Woof ruff🐕" << std::endl;
}

Brain &Dog::getBrain() {
	return *this->notInUse;
}

void	Dog::objectAddress( void ) const {
	std::cout << "My Brain is located at : " << this->notInUse << std::endl;
}