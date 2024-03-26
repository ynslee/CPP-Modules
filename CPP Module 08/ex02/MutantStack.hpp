#pragma once

#include <stack>
#include <deque>

template <class T, class Container = std::deque<T>>
class MutantStack : public std::stack<T, Container> {

	public :
		MutantStack(){};
		~MutantStack(){};

		MutantStack(MutantStack const &other){
			if (this != other)
				*this = other;
		};
		MutantStack &operator=(MutantStack const &other){
			if (this != other)
				std::stack<T, Container>::operator=(other);
			return *this;
		};

		typedef typename Container::iterator iterator;
		
		iterator	begin() {return this->c.begin();}
		iterator	end() {return this->c.end();}
};