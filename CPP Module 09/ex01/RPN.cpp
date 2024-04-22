#include "RPN.hpp"
#include <sstream>
#include <iostream>

RPN::RPN(std::string arg){

	std::istringstream iss(arg);
	std::string token;

	while (iss >> token){
		if (token == "+" || token == "*" || token == "-" || token == "/"){
			if (numbers.size() < 2){
				std::cerr << "Error : no numbers left to use operator" << std::endl;
				return ;
			}
			int num2 = numbers.top();
			numbers.pop();
			int num = numbers.top();
			numbers.pop();
			switch(token[0]){
				case '+':
					numbers.push(num + num2);
					break;
				case '-':
					numbers.push(num - num2);
					break;
				case '*':
					numbers.push(num * num2);
					break;
				case '/':
					if (num2 == 0)
					{
						std::cerr << "Error: can't divide number by zero" << std::endl;
						return;
					}
					numbers.push(num / num2);
					break;
			}
		}
		else{
			int number = 0;
			try {
				number = std::stoi(token);
			} catch (std::exception &e) {
				(void)e;
				std::cerr << "Error: Invalid character" << std::endl;
				return ;
			}
			if (number >= 0 && number < 10)
				numbers.push(number);
			else
			{
				std::cerr << "Error: number used in this operation needs to be between 0 to 9" << std::endl;
				return ;
			}
		}
	}
    if (numbers.size() != 1) {
        std::cerr << "Error: no operators left to calculate" << std::endl;
        return;
    }
    std::cout << numbers.top() << std::endl;
    return;
}