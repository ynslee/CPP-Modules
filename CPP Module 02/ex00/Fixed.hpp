#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

/**
 * Copy Constructor: Creates a new object as a copy of an exisiting object(deep copy)
 * Copy assignment operator: Assigns the content of one object to another.
 *  Similar to the copy constructor, it must ensure proper resource management.
 */
class Fixed{
	private:
		int	_number;
		static const int bits = 8;
	
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& other);
		Fixed & operator =
};

#endif
