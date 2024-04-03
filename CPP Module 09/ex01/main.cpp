#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv){
	if (argc != 2)
	{
		std::cerr << "your input must be only one argument" << std::endl;
		return (1);
	}
	RPN rpn(static_cast<std::string>(argv[1]));
}