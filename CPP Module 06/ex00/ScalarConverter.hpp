#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <exception>
# include <limits>
# include <iomanip>

	enum TYPE
	{
		CHAR,
		PSEUDOINFNEG,
		PSEUDOINFPOS,
		PSEUDONAN,
		FLOAT,
		DOUBLE,
		INT,
		INVALID
	};
		
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

class OverflowException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "OverflowException: the value is too big to be stored in a variable";
		}
};

#endif