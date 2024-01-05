#include "Cat.hpp"

Cat::Cat() : Animal(){
	std::cout << "Constructor for Cat is called 🐈" << std::endl;
	this->_type = "Cat";
	this->inUse = new Brain(); 
}

Cat::~Cat(){
	std::cout << "Destructor for Cat is called 🐈" << std::endl;
	delete this->inUse;
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Copy constructor for Cat is called 🐈" << std::endl;
	this->inUse = new Brain(*other.inUse);
}

Cat&	Cat::operator=(const Cat &other){
	std::cout << "Cat copy assignment constructor called 🐈" << std::endl;
	if (this != &other)
		this->_type = other._type;
	*this->inUse = *other.inUse;
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << "🐈Purr Purr MEOW🐈" << std::endl;
}

/*
if it is this->inUse, it refers to Brain pointer of the Cat objects
but if it is *this -> inUse, * operates to dereference a pointer, therefore
*this->inUse will give the Brain object that inUse points to.*/
Brain &Cat::getBrain() {
	return *this->inUse;
}

void	Cat::objectAddress( void ) const {
	std::cout << "My Brain is located at : " << this->inUse << std::endl;
}