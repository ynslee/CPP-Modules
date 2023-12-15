#include "Fixed.hpp"

Fixed::Fixed() : _number(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&Fixed::operator=(const Fixed &other){
	std::cout << "Copy assignment operator called" << std::endl;
	this->_number = other.getRawBits();
	return(*this);
}

int	Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_number);
}

void Fixed::setRawBits(int const raw){
	this->_number = raw;
}

// void function(Fixed *obj)
// {
// 	*obj
// }

// {
// 	Fixed a;
// 	function(&a);
// }

// void function(Fixed &obj)
// {
// 	obj
// }

// {
// 	Fixed a;
// 	function(a);
// }