#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};

/* this is to reach private member functions as make them as array of function pointers.
*/
typedef	void	(Harl::*pointerFunction)();

#endif
