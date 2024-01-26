#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat Chuchi ("Chuchi", 5);
	Bureaucrat Sunny("Sunny", 150);

	std::cout << Chuchi << std::endl;
	std::cout << Sunny << std::endl;

	Intern Lauri;
	AForm *shrubbery;

	try {shrubbery = Lauri.makeForm("shrubbery creation", "Plant");
	}catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << *shrubbery << std::endl;

	AForm *robotomy;
	try {
		robotomy = Lauri.makeForm("robotomy request", "Drilling");
	} catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << *robotomy << std::endl;

	AForm *presidential;
	try {
		presidential = Lauri.makeForm("presidential pardon", "Sauli");
	}catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << *presidential << std::endl;

	try {
		AForm *ChuchiEatsEggs = Lauri.makeForm("Chuchi eats eggs", "Doggo");
		(void)ChuchiEatsEggs;
	}catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	try {
		Sunny.signForm(*shrubbery);
	}catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try {Chuchi.signForm(*shrubbery);
	}catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try{Sunny.signForm(*robotomy);
	}catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try{Sunny.signForm(*presidential);
	}catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	try {Sunny.executeForm(*shrubbery);
	}catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	try{Chuchi.executeForm(*shrubbery);
	}catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try{Chuchi.executeForm(*robotomy);
	}catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try{Chuchi.executeForm(*presidential);
	}catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	delete shrubbery;
	delete robotomy;
	delete presidential;

	return (0);
}