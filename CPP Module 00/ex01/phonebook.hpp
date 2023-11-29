#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define GREY "\033[38m"
# define PURPLE "\033[95m"
# define MAXIMUM_SIZE 8

# include <iostream>
# include "Contact.hpp"


class PhoneBook
{
  private:
	int			_index;
	int			_count;
	Contact		_contacts[MAXIMUM_SIZE];
	Contact*	_findContact();
	void		_addContact();
	void		_searchIndex() const;

  public:
	PhoneBook();
	~PhoneBook();

	void	openPhoneBook(std::string content);
};

#endif