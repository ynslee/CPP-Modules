#include "Form.hpp"

Form::Form(std::string const _name, const int _signGrade, const int _executeGrade) : name(_name), _signed(false), signGrade(_signGrade), executeGrade(_executeGrade) {
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

bool	Form::getSignedStatus() const {
	return (_signed);
}

void Form::beSigned(Bureaucrat &b) {

	std::string msg;

	if (this->getSignedStatus() == true){
		msg = " couldn't sign ";
		std::cout << b.getName() << msg << name << " because it was already signed" << std::endl;
		throw Form::AlreadySignedException();
	}
	else if (b.getGrade() > signGrade)
	{
		throw Form::GradeTooLowException();
	}
	else{
		_signed = 1;
	}
}	

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	std::string msg;

	if (f.getSignedStatus() == true)
		msg = " is signed. ";
	else
		msg = " is not signed. ";

	std::cout << "Form - " << f.getName() << msg
		<< " It requires " << f.getSignGrade() << " grade to sign and "
		<< f.getExecuteGrade() << " grade to execute. "<< std::endl;

	return (os);
}