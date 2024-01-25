#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &other) {
	(void)other;
}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return (*this);
}

AForm *Intern::createPresidentialPardonForm(std::string const &target) {
	return (new PresidentialPardonForm(target));
}

AForm *Intern::createRobotomyRequestForm(std::string const &target) {
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createShrubberyCreationForm(std::string const &target) {
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target) {
	std::string forms[] {"shrubbery creation", "robotomy request", "presidential pardon"};
	pointerFunction functions[] = {&Intern::createShrubberyCreationForm, &Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm};

	for (int i = 0; i < 3; i++){
		if (formName.compare(forms[i]) == 0){
			return (this->*functions[i])(target);
		}
	}
	throw FormNotFoundException();
}