#include "AForm.hpp"

AForm::AForm(std::string const _name, const int _signGrade, const int _executeGrade) : name(_name), _signed(false), signGrade(_signGrade), executeGrade(_executeGrade) {
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm() {};

AForm::AForm(const AForm &other) : name(other.name), _signed(other._signed), signGrade(other.signGrade), executeGrade(other.executeGrade) {};

AForm& AForm::operator=(const AForm &other) {
	if (this == &other)
		return (*this);
	_signed = other._signed;
	return (*this);
}

std::string AForm::getName() const {
	return (name);
}

int	AForm::getSignGrade() const {
	return (signGrade);
}

int	AForm::getExecuteGrade() const {
	return (executeGrade);
}

bool	AForm::getSignedStatus() const {
	return (_signed);
}

void AForm::beSigned(Bureaucrat &b) {

	std::string msg;

	if (this->getSignedStatus() == true){
		msg = " couldn't sign ";
		std::cout << b.getName() << msg << name << " because it was already signed" << std::endl;
		throw AForm::AlreadySignedException();
	}
	else if (b.getGrade() > signGrade)
	{
		throw AForm::GradeTooLowException();
	}
	else{
		msg = " will be signed by ";
		std::cout << name << msg << b.getName() << std::endl;
		_signed = 1;
	}
}

void AForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > executeGrade)
		throw AForm::GradeTooLowException();
	else if (getSignedStatus() == false)
		throw AForm::NotSignedException();
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
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