#pragma once

#include <algorithm>
#include <iostream>


class noOccurenceException : public std::exception {
	public:
		const char*	what( void ) const throw() override {
			return ("occurence not found in container");
		};
};

template <typename T>
void easyfind(T &container, int value){
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it != container.end())
	{
		std::cout << "Value: " << value << " is found in container" << std::endl;
		return ;
	}
	throw noOccurenceException();
}