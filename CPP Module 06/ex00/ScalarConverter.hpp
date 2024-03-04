#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <exception>
# include <limits>


/*static member function can be called even if no objects of the class exist*/
class ScalarConverter {

	private:
		enum TYPE
		{
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			PSEUDOINFNEG,
			PSEUDOINFPOS,
			PSEUDONAN,
			INVALID
		};
		
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &src);
		~ScalarConverter();
		int getType(std::string const str);
		
	public:
	static void	convert(std::string const &str);
};

#endif