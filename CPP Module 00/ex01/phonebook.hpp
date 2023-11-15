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

# include <iostream>


class PhoneBook
{
  private:
	int			index;
	int			count;
	Contact		record[8];
	Contact*	getContact();
	void		add();
	void		search() const;
	int			getTotal();

  public:
	PhoneBook();
	~PhoneBook();
};

#endif