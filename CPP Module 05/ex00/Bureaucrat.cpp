#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("random"), grade(150) {};

Bureaucrat::Bureaucrat(std::string const _name, int _grade) : name(_name) {
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
	this->grade = _grade;
};

Bureaucrat::~Bureaucrat() {};

Bureaucrat::Bureaucrat(const Bureaucrat &other): name(other.getName()){
	*this = other;
	return ;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &other){
	if (this != &other){
		this->grade = other.getGrade();
	}
	return (*this);

}

std::string Bureaucrat::getName() const{
	return this->name;
}

int	Bureaucrat::getGrade() const{
	return this->grade;
}

void	Bureaucrat::setGrade(int _grade){
	this->grade = _grade;
}

void	Bureaucrat::incrementGrade(){
	this->grade--;
	if (this->grade < 1)
		throw GradeTooHighException();
}

void	Bureaucrat::decrementGrade(){
	this->grade++;
	if (this->grade > 150)
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream &os,  const Bureaucrat &b)
{
	os << "Bureaucrat : " << b.getName() << ", bureaucrat grade is: " << b.getGrade();
	return (os);
}