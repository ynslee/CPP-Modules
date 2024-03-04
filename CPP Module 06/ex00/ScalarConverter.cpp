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
	char c = 0;
	int i = 0;
	float f = 0.0;
	double d = 0.0;
	int type = -1;

	bool integer_overflow = false;

	if (str.length() == 1 && std::isprint(str[0]) && std::isalpha(str[0]))
		type = CHAR;
	else if (str.compare("+inf") == 0 || str.compare("+inff") == 0)
		type = PSEUDOINFPOS;
	else if (str.compare("-inf") == 0 || str.compare("-inff") == 0)
		type = PSEUDOINFNEG;
	else if (str.compare("nan") == 0 || str.compare("nanf") == 0)
		type = PSEUDONAN;
	else if (str.back() == 'f' && type == -1 && str.find('.') != std::string::npos)
	{
		size_t j = 0;
		int dot = 0;

		if (str.find( '.' ) == 0 || str.find( '.' ) == str.length() - 2 )
			type = INVALID;
		if (str[j] == '+' || str[i] == '-')
			j++;
		while (j < str.length() - 1)
		{
			if (str[j] == '.')
				dot++;
			if (!std::isdigit(str[j]) && str[j] != '.')
				type = INVALID;
			j++;
		}
		if (dot == 1)
			type = FLOAT;
		else
			type = INVALID;
	}
	else if (type == -1 && str.find('.') != std::string::npos)
	{
		size_t j = 0;
		int dot = 0;

		if ( str.find( '.' ) == std::string::npos || str.find( '.' ) == 0 || str.find( '.' ) == str.length() - 1 )
			type = INVALID;
		if (str[j] == '+' || str[j] == '-')
			j++;
		while (j < str.length())
		{
			if (str[j] == '.')
				dot++;
			if (!std::isdigit(str[j]) && str[j] != '.')
				type = INVALID;
			j++;
		}
		if (dot == 1)
			type = DOUBLE;
		else
			type = INVALID;
	}
	else if (type == -1 && str.find('.') == std::string::npos)
	{
		size_t j = 0;

		if (str[j] == '+' || str[i] == '-')
			j++;
		while (str[j] != '\0')
		{
			if (!std::isdigit(str[j]))
				type = INVALID;
			j++;
		}
		type = INT;
	}
	if (type == -1)
		type = INVALID;                  

	// Conver to char
	if (type == CHAR){	
		c = static_cast<char>(str[0]);
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
	}else if (type == INT){
		// try {
		// 	f = std::stoi(str);
			// if (f > INT_MAX || f < INT_MIN)
			// 	throw std::out_of_range("Invalid input. Can't convert to others");
			// else
				i = std::stoi(str);
		// } catch(...) {
		// 	std::cout << "Invalid input. Can't convert to others" << std::endl;
		// 	return ;
		// }
		f = static_cast<float>(i);
		d = static_cast<double>(i);
		c = static_cast<char>(i);
	}else if (type == FLOAT){
		f = std::stof(str);
		if (f > std::numeric_limits<float>::max() || f < std::numeric_limits<float>::lowest())
			throw OverflowException();
		if (f > INT_MAX || f < INT_MIN)
			integer_overflow = true;
		i = static_cast<int>(f);
		d = static_cast<double>(f);
		c = static_cast<char>(f);
	}else if (type == DOUBLE){
		d = std::stod(str);
		if (d > std::numeric_limits<double>::max() || d < std::numeric_limits<double>::lowest())
			throw OverflowException();
		if (d > INT_MAX || d < INT_MIN)
			integer_overflow = true;
		i = static_cast<int>(d);
		f = static_cast<float>(d);
		c = static_cast<char>(d);
	}else if (type == PSEUDOINFPOS){
		f = std::numeric_limits<float>::infinity();
		d = std::numeric_limits<double>::infinity();
		std::cout << "char: Impossible"	<< std::endl;
		std::cout << "int: Impossible"	<< std::endl;
		std::cout << "float: " << f		<< "f" << std::endl;
		std::cout << "double: " << d		<< std::endl;
		return ;
	}else if (type == PSEUDOINFNEG){
		f = -std::numeric_limits<float>::infinity();
		d = -std::numeric_limits<double>::infinity();
		std::cout << "char: Impossible"	<< std::endl;
		std::cout << "int: Impossible"	<< std::endl;
		std::cout << "float: " << f		<< "f" << std::endl;
		std::cout << "double: " << d		<< std::endl;
		return ;
	}else if (type == PSEUDONAN){
		f = std::numeric_limits<float>::quiet_NaN();
		d = std::numeric_limits<double>::quiet_NaN();
		std::cout << "char: Impossible"	<< std::endl;
		std::cout << "int: Impossible"	<< std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: "	<< d << std::endl;
		return ;
	}
	if (!std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	if (integer_overflow == true)
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
