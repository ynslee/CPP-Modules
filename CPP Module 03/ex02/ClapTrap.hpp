#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap{
	protected:
		int _hitPoints;
		int	_energyPoints;
		int	_attackDamage;
		std::string	_name;

	public:
		ClapTrap();
		~ClapTrap();
		ClapTrap(std::string _player);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

};


# endif