
#include <iostream>
#include "Sample3.Class.hpp"

int main(){
	Sample3 instance1(43);
	Sample3 instance2(42);

	if (instance1.compare(&instance2) == 1)
		std::cout << "instance1 is bigger than instance 2" << std::endl;
	else
		std::cout << "instance 1 is same or smaller than instance 2" << std::endl;

	return 0;
}