#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	std::string	content;

	std::cout << "******************************" << std::endl;
	std::cout << "**Scalar Converter initiated**" << std::endl;
	std::cout << "******************************" << std::endl;
	if (argc != 2){
		std::cout << "Error: please type a parameter" << std::endl;
		std::cout << "parameter type: char, int, float, double" << std::endl;
		std::cout << "Example: ./convert 42" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);


	// std::cout << "------------------------------" << std::endl;
	// std::cout << "---Integer overflow happened--" << std::endl;
	// std::cout << "------------------------------" << std::endl;	
	// int i = std::numeric_limits<int>::max();
	// i = i + 1;
	// ScalarConverter::convert(std::to_string(i));
	// std::cout << "------------------------------" << std::endl;
	// std::cout << "---Float overflow happened----" << std::endl;
	// std::cout << "------------------------------" << std::endl;	
	// float f = std::numeric_limits<float>::max();
	// f = f * 2;
	// ScalarConverter::convert(std::to_string(f));
	// return 0;

}