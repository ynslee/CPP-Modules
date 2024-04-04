#pragma once

#include <iostream>
#include <sstream>

class PmergeMe{
	private:
		PmergeMe() {};
		PmergeMe(PmergeMe const &other) {*this = other;};

	public:
		PmergeMe(std::stringstream &ss);
		~PmergeMe() {};
};