#include "Fixed.hpp"

Fixed::Fixed() : _number(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int _integer) {
	this->_number  = _integer << this->bits;
};

Fixed::Fixed(const float _float) {
	this->_number = std::roundf(_float * (1 << this->bits));
};

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other){
	*this = other;
}

Fixed&Fixed::operator=(const Fixed &other){
	this->_number = other.getRawBits();
	return(*this);
}

int	Fixed::getRawBits(void) const{
	return (this->_number);
}

void Fixed::setRawBits(int const raw){
	this->_number = raw;
}

int	Fixed::toInt(void)const{
	return (this->_number >> this->bits);
}

float	Fixed::toFloat(void) const{
	float	floats = (float)this->_number / (float)(1 << this->bits);
	return(floats);
}

/*comparison operators*/

bool Fixed::operator>(const Fixed &fixed) const
{
	return this->_number > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return this->_number < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return this->_number >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return this->_number <= fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return this->_number != fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return this->_number == fixed.getRawBits();
}

/*arithmetic operators*/

Fixed &Fixed::operator+(const Fixed &fixed)
{
	this->_number = this->getRawBits() + fixed.getRawBits();
	return *this;
}

Fixed &Fixed::operator-(const Fixed &fixed)
{
	this->_number = this->getRawBits() - fixed.getRawBits();
	return *this;
}

Fixed &Fixed::operator*(const Fixed &fixed)
{
	this->_number = this->getRawBits() * fixed.getRawBits() / (1 << bits);
	return *this;
}

Fixed &Fixed::operator/(const Fixed &fixed)
{
	this->_number = this->getRawBits() / fixed.getRawBits() * (1 << bits);
	return *this;
}

/*post & prefix incrementors and decrementors*/

Fixed &Fixed::operator++(void)
{
	this->_number++;
	return *this;
}

Fixed &Fixed::operator--(void)
{
	this->_number--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	temp._number = this->_number++;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	temp._number = this->_number--;
	return temp;
}

/*min max return methods*/

Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (Fixed &)a;
	return (Fixed &)b;
}

Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (Fixed &)a;
	return (Fixed &)b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

std::ostream& operator<<(std::ostream &os, const Fixed &other) {
	os << other.toFloat();
	return os;
}
