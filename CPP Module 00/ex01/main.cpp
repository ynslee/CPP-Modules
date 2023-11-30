
#include "PhoneBook.hpp"
#include <iostream>

int main()
{
	PhoneBook	myPhoneBook;
	std::string	content;

	std::cout << PURPLE << "******************************" << std::endl;
	std::cout << "*You have opened a phonebook!*" << std::endl;
	std::cout << "******************************" << RESET << std::endl;
	std::cout << "ADD, SEARCH, or EXIT to use phonebook" << std::endl;
	while (54)
	{
		std::getline (std::cin, content, '\n');
		if (std::cin.eof() == 1)
			exit(0);
		if (content.empty())
		{
			std::cout << "Empty command! please type ADD, SEARCH, or EXIT as command!" << std::endl;
			continue ;
		}
		myPhoneBook.openPhoneBook(content);
		std::cout << PURPLE << "******************************" << std::endl;
		std::cout << PURPLE << "*Came back to phonebook main!*" << std::endl;
		std::cout << PURPLE << "******************************" << RESET << std::endl;
		std::cout << "ADD, SEARCH, or EXIT to use phonebook" << std::endl;
	}
	return 0;
}