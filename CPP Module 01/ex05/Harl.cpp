#include "Harl.hpp"

Harl::Harl() {
	std::cout << "Harl constructed" << std::endl;
};

Harl::~Harl() {
	std::cout << "Harl deconstructed" << std::endl;
};

void	Harl::debug(void)
{
	std::cout << "**********DEBUG in process" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "**********INFO in process" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "**********WARNING in process" << std::endl;
	std::cout <<  "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "**********ERROR in process" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

/*(this->*func)() is calling the member function that func points to on the current object. This is necessary because member functions need to be called on an object, and a function pointer does not have an object associated with it
*/
void	Harl::complain(std::string level)
{
	pointerFunction	Harls[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*Harls[i])();
			return ;
		}
	}
	std::cout << "This is not a Proper complain!" << std::endl;
}