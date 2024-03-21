#pragma once

#include <exception>
#include <limits.h>

template <typename T>
class	Array 
{
	private:
		T	*_array;
		unsigned int	_size;

	public:
		Array( void ) : _array(NULL), _size(0) {};

		Array(unsigned int n) { 
			this->_array = new T[n];
			_size = n;
		};

		Array(Array const& other) { 
			this->_array = NULL;
			*this = other;
		};

		Array&	operator=(Array const& other) {
			if (this  != &other) {
				if (this->_array != NULL)
					delete [] this->_array;
				this->_array = new T[other.size()];
				this->_size = other.size();
				for (int i = 0; i < other.size(); i++) {
					this->_array[i] = other._array[i];
				}
			}
			return (*this);
		};

		~Array( void ) {
			if (this->_array)
			delete [] this->_array;
		};

		class OutOfBounds : public std::exception {
			public:
				const char*	what( void ) const throw() override {
					return ("Index is out of bounds.");
				};
		};

		T&	operator[](int index ) {
			if (index < 0 || index >= static_cast<int>(this->_size) || static_cast<int>(this->_size) > INT_MAX) {
				throw(OutOfBounds());
			}
			return (this->_array[index]);
		};

		T const	&operator[]( int index ) const {
			if (index < 0 || index >= static_cast<int>(this->_size) || static_cast<int>(this->_size) > INT_MAX) {
				throw(OutOfBounds());
			}
			return (this->_array[index]);
		};

		int	size( void ) const {
			return (this->_size);
		};

};
