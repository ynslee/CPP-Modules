#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("random"), grade(150) {};

Bureaucrat::Bureaucrat(std::string const _name, int _grade) : name(_name) {
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
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
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade(){
	this->grade++;
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::signForm(AForm &f){

	std::string msg;

	if (f.getSignedStatus() == true)
	{
		msg = " couldn't sign ";
		std::cout << name << msg << f.getName() << " because form is already signed" << std::endl;
	}
	else if (f.getSignGrade() < this->grade)
	{
		msg = " couldn't sign ";
		std::cout << name << msg << f.getName() << " because bureaucrat's grade is lower than form sign grade" << std::endl;
	}
	else
	{
		try { f.beSigned(*this);
		}
		catch (std::exception &e) {
			std::cerr << "caught in exception of besigned function: " << e.what() << std::endl;
		}
	}	
}

void	Bureaucrat::executeForm(AForm const & form){
	try { 
		form.execute(*this);
	}
	catch (std::exception &e) {
		std::cerr << "caught in exception of execute function: " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream &os,  const Bureaucrat &b)
{
	os << "Bureaucrat : " << b.getName() << ", bureaucrat grade is: " << b.getGrade();
	return (os);
}