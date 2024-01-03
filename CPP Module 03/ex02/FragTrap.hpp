#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap{

	public:
		FragTrap();
		~FragTrap();
		FragTrap(std::string _player);
		FragTrap(const FragTrap& other);
		FragTrap& operator=(const FragTrap& other);

		void attack(const std::string &target);
		void highFivesGuys();
};


# endif