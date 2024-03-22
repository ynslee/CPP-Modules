#include "Span.hpp"
#include <iostream>
#include <time.h>

Span::Span() {}

Span::Span(unsigned int N) : _N(N) {
	std::vector<int> _vec(N);
}

Span::Span(Span const &other) {
	if (this != &other)
	{
		this->_N = other._N;
		if (this->_vec.size() > 0)
		{
			this->_vec.clear();
			this->_vec = other._vec;
		}
	}
}

Span &Span::operator=(Span const &other) {
	if (this != &other)
	{
		this->_N = other._N;
		if (this->_vec.size() > 0)
		{
			this->_vec.clear();
			this->_vec = other._vec;
		}
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
	if (this->_vec.size() < this->_N)
		this->_vec.push_back(number);
	else
		throw CantAddNewException();
}

int Span::shortestSpan() {
	if (this->_vec.size() < 2)
		throw NoSpanFoundException();
	std::sort(this->_vec.begin(), this->_vec.end());
	int span = this->_vec[1] - this->_vec[0];
	std::vector<int>::iterator it;
	for (it = this->_vec.begin(); it != this->_vec.end() - 1; it++)
	{
		if (*(it + 1) - *it < span)
			span = *(it + 1) - *it;
	}
	return span;
}

int Span::longestSpan() {
	if (this->_vec.size() < 2)
		throw NoSpanFoundException();
	int min = *std::min_element(this->_vec.begin(), this->_vec.end());
	int max = *std::max_element(this->_vec.begin(), this->_vec.end());
	return max - min;
}

void Span::fillVector(unsigned int amount) {
	unsigned int currentSize = _vec.size();
	if (currentSize + amount > _N) {
		throw Span::CantAddNewException();
	}
	_vec.resize(_vec.size() + amount);
	srand(time(NULL));
	for (unsigned int i = currentSize; i < _vec.size(); i++) {
		_vec[i] = rand();
	}
	return ;
}