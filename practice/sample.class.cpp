
#include <iostream>
#include "Sample.class.hpp"

/**
 * @brief Construct a new Sample:: with 'this' function, you are able
 * to access that is in your class.(just like struct)
 * to refer to your current class, you would like to use 'this' to make it easier
 * 
 */
// Sample::Sample( void ){
// 	std::cout << "Constructor called" << std::endl;

// 	this->foo = 42;
// 	std::cout << "this->foo: " << this->foo << std::endl;

// 	this->foo = 24;
// 	std::cout << "this->foo: " << this->foo << std::endl;

// 	this->bar();

// 	return ;
// }

// Sample::~Sample( void ){
// 	std::cout << "Destructor called" << std::endl;
// 	return ;
// }

// void	Sample::bar( void ){
// 	std::cout << "Member function bar called" << std::endl;
// 	return ;
// }


Sample::Sample( float const f ) : const_value( f), qd(42) {
	std::cout << "Constructor called" << std::endl;
	return ;
}

Sample::~Sample( void ){
	std::cout << "Destructor called" << std::endl;
	return ;
}

void	Sample::bar( void ) const {

	std::cout << "this->const_value: " << this->const_value << std::endl;
	std::cout << "this->qd: " << this->qd << std::endl;

	this->qd = 0;
	
	return ;
}