
#include <iostream>
#include "Sample.class.hpp"

/**
 * @brief Construct a new Sample:: with 'this' function, you are able
 * to access that is in your class.(just like struct)
 * to refer to your current class, you would like to use 'this' to make it easier
 * 
 */
Sample::Sample( void ){
	std::cout << "Constructor called" << std::endl;

	this->foo = 42;
	std::cout << "this->foo: " << this->foo << std::endl;

	this->foo = 24;
	std::cout << "this->foo: " << this->foo << std::endl;

	this->bar();

	return ;
}

Sample::~Sample( void ){
	std::cout << "Destructor called" << std::endl;
	return ;
}

void	Sample::bar( void ){
	std::cout << "Member function bar called" << std::endl;
	return ;
}