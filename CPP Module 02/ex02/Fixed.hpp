#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <tgmath.h>

/**
 * Copy Constructor: Creates a new object as a copy of an exisiting object(deep copy)
 * Copy assignment operator: Assigns the content of one object to another.
 *  Similar to the copy constructor, it must ensure proper resource management.
 * ex) when an object is returned by value from a function
 * 		when object is passed by value as an argument to a function
 * private: field or member variables
 * public: method or member functions
 */
class Fixed{
	private:
		int	_number;
		static const int bits = 8;
	
	public:
		Fixed();
		Fixed(const int _integer);
		Fixed(const float _float);
		Fixed(const Fixed& other);
		~Fixed();
		Fixed& operator=(const Fixed& other);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream &os, const Fixed &Fixed);

#endif
