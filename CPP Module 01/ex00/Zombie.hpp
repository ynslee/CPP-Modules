#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

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

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

#endif
