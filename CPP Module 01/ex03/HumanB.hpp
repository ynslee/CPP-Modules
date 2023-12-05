#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

/**
 * @brief Pointer to weapon is to allow instances of HumanB
 * to be created without requiring a weapon object
 * when initiate the contruction.
 * 
 */
class HumanB{
	private:
	std::string	_name;
	Weapon		*_weapon;

	public:
	HumanB(std::string name);
	~HumanB();

	void	setWeapon(Weapon &weapon);
	void	attack() const;
};

#endif