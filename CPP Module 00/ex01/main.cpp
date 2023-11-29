
#include "phonebook.hpp"
#include <iostream>

int main()
{
	PhoneBook	myPhoneBook;
	std::string	content;

	std::cout << PURPLE << "hello this is PURPLE\n" << RESET << std::endl;
	std::cout << PURPLE << "*******************************" << std::endl;

	while (54)
	{
		std::getline (std::cin, content, '\n');
		if (std::cin.eof() == 1)
			exit(0);
		if (content.empty())
			std::cout << "please type ADD, SEARCH, or EXIT as command!" << std::endl;
		
	}
}