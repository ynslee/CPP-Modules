#include "Fixed.hpp"

Fixed::Fixed() : _number(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int _integer) {
	std::cout << "Int constructor called" << std::endl;
	this->_number  = _integer << this->bits;
};

Fixed::Fixed(const float _float) {
	std::cout << "Float constructor called" << std::endl;
	this->_number = std::roundf(_float * (1 << this->bits));
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
	std::cout << "setRawBits member function called" << std::endl;
	this->_number = raw;
}

int	Fixed::toInt(void)const{
	return (this->_number >> this->bits);
}

float	Fixed::toFloat(void) const{
	float	floats = (float)this->_number / (float)(1 << this->bits);
	return(floats);
}

std::ostream& operator<<(std::ostream &os, const Fixed &other) {
	os << other.toFloat();
	return os;
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