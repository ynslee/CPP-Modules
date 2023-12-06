#include "PhoneBook.hpp"
#include <string> //compare
#include <iomanip> //setw
#include <sstream> //ss

PhoneBook::PhoneBook() : _index(-1), _contactCount(0) {};
PhoneBook::~PhoneBook() {};

Contact *PhoneBook::_findContact() { return (this->_contacts); }

static std::string put_content()
{
	std::string	_input;

	while (42)
	{
		std::getline(std::cin, _input, '\n');
		if (std::cin.eof())
		{
			std::cout << "reached the end of file!" << std::endl;
			std::exit(0);
		}
		if (!_input.empty())
			return (_input);
		else
			std::cout << "Invalid input!" << std::endl;
	}
}

void	PhoneBook::_addContact()
{
	if (_index == MAXIMUM_SIZE - 1)
		_index = 0;
	else
		_index++;
	std::cout << "Type your first name" << std::endl;
	_contacts[_index].putFirstName(put_content());
	std::cout << "Type your last name" << std::endl;
	_contacts[_index].putLastName(put_content());
	std::cout << "Type your nickname" << std::endl;
	_contacts[_index].putNickName(put_content());
	std::cout << "Type your phone number" << std::endl;
	_contacts[_index].putNumber(put_content());
	std::cout << "Type your darkest secret" << std::endl;
	_contacts[_index].putSecret(put_content());
	if (_contactCount >= MAXIMUM_SIZE)
		_contactCount = MAXIMUM_SIZE;
	else
		_contactCount++;
}

void	PhoneBook::openPhoneBook(std::string content)
{
	if (content.compare("ADD") == 0)
		this->_addContact();
	else if (content.compare("SEARCH") == 0)
		this->_searchIndex();
	else if (content.compare("EXIT") == 0)
	{
		std::cout << "You have closed the phone book" << std::endl;
		std::cout << "All the contacts will be removed" <<std::endl;
		std::exit(0);
	}
	else
		std::cout << "not a valid input! please type ADD, SEARCH, or EXIT as command" << std::endl;
}

static std::string truncate(std::string str)
{
	if (str.length() > 10)
	{
		std::string _truncate = str.substr(0, 10);
		_truncate[9] = '.';
		return (_truncate);
	}
	else
		return (str);
}

static void	set_column()
{
	std::cout << GREEN << std::endl;
	std::cout << '|';
	std::cout << std::setw(10) << truncate("Index") << '|';
	std::cout << std::setw(10) << truncate("First Name") << '|';
	std::cout << std::setw(10) << truncate("Last Name") << '|';
	std::cout << std::setw(10) << truncate("Nickname")<< '|';
	std::cout << RESET << std::endl;
}

static void put_column(Contact _contacts, int index)
{
	std::cout << GREY << std::endl;
	std::cout << '|';
	std::cout << std::setw(10) << index << '|';
	std::cout << std::setw(10) << truncate(_contacts.getFirstName()) << '|';
	std::cout << std::setw(10) << truncate(_contacts.getLastName()) << '|';
	std::cout << std::setw(10) << truncate(_contacts.getNickName()) << '|';
	std::cout << RESET << std::endl;
	return ;
}


void	PhoneBook::_searchIndex() const
{
	std::string 		content;
	int i;

	if (this->_contactCount == 0)
		std::cout << "There is nothing in the phonebook yet!" << std::endl;
	else
	{
		set_column();
		for (i = 0; i < this->_contactCount; i++)
			put_column(this->_contacts[i], i);
		while (42)
		{
			std::cout << "Please choose Index number(ex. 0) : ";
			content = put_content();
			std::stringstream ss(content);
			ss >> i;
			int number;
			number = i;
			std::stringstream check;
			check << number;
			std::string str = check.str();
			int result = content.compare(str);
			if (!result && !ss.fail() && i >= 0 && i < this->_contactCount)
				break ;
			else
				std::cout << "\nPlease enter a valid index : 0 - " << this->_contactCount - 1 << std::endl;
		}
		if (i >= 0 && i < this->_contactCount)
		{
			std::cout << std::endl;
			std::cout << "------------ Chosen contact" << std::endl;
			std::cout << "Phone book index is: " << i << std::endl;
			std::cout << "First name: " << this->_contacts[i].getFirstName() << std::endl;
			std::cout << "Last name: " << this->_contacts[i].getLastName() << std::endl;
			std::cout << "Nick name: " << this->_contacts[i].getNickName() << std::endl;
			std::cout << "Phone number: " << this->_contacts[i].getNumber() << std::endl;
			std::cout << " ** Darkest Secret ** : " << this->_contacts[i].getSecret() << "\n\n" << std::endl;
				while (42)
			{
				std::cout << "\n----------please enter to return";
				std::getline(std::cin, content, '\n');
				if (content.empty())
					return ;
				else
					continue;
			}
		}
		else
		{
			std::cout << "Please put valid index!" << std::endl;
			return ;
		}
	}
}





































