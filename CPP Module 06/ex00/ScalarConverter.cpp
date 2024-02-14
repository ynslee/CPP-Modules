#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
	if (this != &src)
		*this = src;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string const &str){
	char c;
	int i;
	float f;
	double d;
	int type = -1;

	if (str.compare("inf") == 0 || str.compare("inff") == 0)
		type = PSEUDOINFPOS;
	else if (str.compare("-inf") == 0 || str.compare("-inff") == 0)
		type = PSEUDOINFNEG;
	else if (str.compare("nan") == 0 || str.compare("nanf") == 0)
		type = PSEUDONAN;

	// Conver to char
	try {
		c = std::stoi(str);
		if (str.length() != 1 && type == -1 && !isprint(c))
		{
			throw std::invalid_argument("Invalid input");
		}
		if (!isprint(c) || (type >= PSEUDOINFPOS && type <= PSEUDONAN)){
			throw std::exception();
		}
		std::cout << "char: " << c << std::endl;
	} catch (...) {
		if (type >= PSEUDOINFPOS && type <= PSEUDONAN)
			std::cout << "char: impossible" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}

	try {
		i = std::stoi(str);
		std::cout << "int: " << i << std::endl;
	} catch (...) {
		std::cout << "int: impossible" << std::endl;
	}
	
	// Convert to float
	try {
		f = std::stof(str);
		if (f > std::numeric_limits<float>::max() || f < std::numeric_limits<float>::lowest())
			throw std::exception();
		std::cout << "float: " << f << "f" << std::endl;
	} catch (...) {
		std::cout << "float: impossible" << std::endl;
	}
	
	// Convert to double
	try {
		d = std::stod(str);
		if (d > std::numeric_limits<double>::max() || d < std::numeric_limits<double>::lowest())
			throw std::exception();
		std::cout << "double: " << d << std::endl;
	} catch (...) {
		std::cout << "double: impossible" << std::endl;
	}


}