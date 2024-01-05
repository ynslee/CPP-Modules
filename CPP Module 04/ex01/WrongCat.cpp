#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
  this->_type = "WrongCat";
  std::cout << "Constructor for WrongCat is called" << std::endl;
}

WrongCat::~WrongCat(void) {
  std::cout << "Destructor for WrongCat is called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
  std::cout << "WrongCat has been constructed. (copy)" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << "WrongCat has been assigned." << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

void WrongCat::makeSound(void) const {
  std::cout << "Wrong cat goes I am a car not a cat broom broom 🚙" << std::endl;
}

