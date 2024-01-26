#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class AForm;

class Intern{
	private:
	AForm *createShrubberyCreationForm(std::string const &target);
	AForm *createRobotomyRequestForm(std::string const &target);
	AForm *createPresidentialPardonForm(std::string const &target);
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);

	public:
	Intern();
	~Intern();
	AForm *makeForm(std::string const &formName, std::string const &target);

	class FormNotFoundException : public std::exception {
		public:
		const char *what() const noexcept override{
			return ("Form not found. ");
		};
	};
};

typedef	AForm*	(Intern::*pointerFunction)(const std::string &);

#endif