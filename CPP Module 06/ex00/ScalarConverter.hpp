#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <exception>

/*static member function can be called even if no objects of the class exist*/
class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &src);
		~ScalarConverter();
		
	public:
	static void	convert(std::string const &str);
};

#endif