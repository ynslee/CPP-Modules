#include "Form.hpp"

Form::Form(std::string const _name, bool _signed, const int _signGrade, const int _executeGrade) : name(_name), _signed(false), signGrade(_signGrade), executeGrade(_executeGrade) {
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::~Form() {};

Form::Form(const Form &other) : name(other.name), _signed(other._signed), signGrade(other.signGrade), executeGrade(other.executeGrade) {};

Form& Form::operator=(const Form &other) {
	if (this == &other)
		return (*this);
	_signed = other._signed;
	return (*this);
}

std::string Form::getName() const {
	return (name);
}

int	Form::getSignGrade() const {
	return (signGrade);
}

int	Form::getExecuteGrade() const {
	return (executeGrade);
}

bool	Form::getSigned() const {
	return (_signed);
}

void Form::beSigned(Bureaucrat &b) {
	if (b.getGrade() > signGrade)
	{
		std::cout << b.getName() << "couldn't sign" << name;
		throw Form::BureaucratCantSignException();
	}
}	

