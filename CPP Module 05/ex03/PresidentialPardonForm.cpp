#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm(target, 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	(void)other;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	AForm::execute(executor);
	std::cout << executor.getName() << " executed " << getName() << std::endl;
	std::cout << executor.getName() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}