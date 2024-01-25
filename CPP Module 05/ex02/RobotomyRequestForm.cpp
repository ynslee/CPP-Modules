#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm(target, 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	(void)other;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	AForm::execute(executor);

	std::srand(static_cast<unsigned int>(std::time(NULL)));
	if (std::rand() % 2 == 0)
	{
		std::cout << executor.getName() << " executed " << getName() << std::endl;
		std::cout << "DRRIIILLLLIIIIIINGGG: Zzzzzzz ZZzzzz Clanky Clank!🤖" << std::endl;
	}
	else
		throw RobotomyFailedException();
}