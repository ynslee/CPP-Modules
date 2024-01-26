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

	srand(time(0));
	static int randomise = rand();
	std::cout << "DRRIIILLLLIIIIIINGGG: Zzzzzzz ZZzzzz Clanky Clank!🤖" << std::endl;
	std::cout << "DRRIIILLLLIIIIIINGGG: Zzzzzzz ZZzzzz Clanky Clank Clank!🤖" << std::endl;
	if (randomise % 2 == 0)
	{
		randomise++;
		std::cout << executor.getName() << " succefully robotomised " << getName() << std::endl;
	}
	else{
		randomise++;
		throw RobotomyFailedException();
	}
}