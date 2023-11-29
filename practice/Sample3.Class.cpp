
#include <iostream>
#include "Sample3.Class.hpp"

Sample3::Sample3(int v) : _foo( v ) {
	return ;
}

Sample3::~Sample3( void) {
	return ;
}

int	Sample3::getfoo( void ) const {
	return this->_foo;
}

int	Sample3::compare( Sample3 * other) const {
	if (this->_foo < other->getfoo())
		return -1;
	else if (this->_foo > other->getfoo())
		return 1;
	return 0;
}