#pragma once

#include <string>
#include <stack>

class RPN {
	private:
		std::stack<int> numbers;
		RPN() {};
		RPN(RPN const &other) {*this = other;};
		RPN &operator=(RPN const &other) { this->numbers = other.numbers; return(*this);};

	public:
		RPN(std::string arg);
		~RPN() {};
};