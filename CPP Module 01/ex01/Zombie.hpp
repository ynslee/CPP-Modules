#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie{

	private:
		std::string		_Name;
	
	public:

	 Zombie();
	 ~Zombie();

	void		announce(void);
	void		setName(std::string name);
	std::string	getName() const;
};

Zombie	*zombieHorde(int N, std::string name);

#endif