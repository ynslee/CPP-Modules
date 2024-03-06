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
		std::cout << "Example: ./ScalarConverter 42" << std::endl;
		return 1;
	}
	try {
		ScalarConverter::convert(argv[1]);
	} catch (...)
	{
		std::cout << "Error: invalid parameter" << std::endl;
		std::cout << "please check if your input is correct. Did you check if it overflows?" << std::endl;
	}
	// std::cout << "------------------------------" << std::endl;
	// std::cout << "---Integer overflow happened--" << std::endl;
	// std::cout << "------------------------------" << std::endl;	
	// float num = std::numeric_limits<int>::max();
	// num = num + 1;
	// ScalarConverter::convert(std::to_string(num));
	// std::cout << "------------------------------" << std::endl;
	// std::cout << "---Float overflow happened----" << std::endl;
	// std::cout << "------------------------------" << std::endl;	
	// float f = std::numeric_limits<float>::max();
	// f = f * 2;
	// try {
	// 	ScalarConverter::convert(std::to_string(f));
	// } catch (...)
	// {
	// 	std::cout << "Error: float overflow" << std::endl;
	// }
	return 0;
}