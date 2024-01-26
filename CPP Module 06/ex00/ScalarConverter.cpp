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
	int i =0;
	float f = 0;
	double d = 0;
	char c = 0;
}