#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <unistd.h>

int main(void) {
	
	std::cout << "\n*********🌲Shrubbery Test🌲**********" << std::endl;
	ShrubberyCreationForm ShrubberyForm("Christmas tree");
	Bureaucrat Santa("Santa", 1);
	Bureaucrat Elf("Elf", 150);

	std::cout << ShrubberyForm << std::endl;
	std::cout << Santa << std::endl;
	std::cout << Elf << std::endl;
	
	Santa.signForm(ShrubberyForm);
	try {
	std::cout << "elf is trying to execute the form" << std::endl;
	Elf.executeForm(ShrubberyForm);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	ShrubberyForm.execute(Santa);

	std::cout << "\n\n*********🤖ROBOTOMY TEST🤖**********" << std::endl;

	RobotomyRequestForm RobbotomyForm("Robbotomy");
	RobotomyRequestForm Sample("Sample");
	RobotomyRequestForm Sample1("Sample1");
	RobotomyRequestForm Sample2("Sample2");
	RobotomyRequestForm Sample3("Sample3");
	RobotomyRequestForm Sample4("Sample4");

	std::cout << RobbotomyForm << std::endl;

	try {
		std::cout << "elf is trying to sign the form" << std::endl;
		RobbotomyForm.beSigned(Elf);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	Santa.signForm(RobbotomyForm);
	try {
		std::cout << "elf is trying to execute the form" << std::endl;
		Elf.executeForm(RobbotomyForm);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Santa is trying to execute the form" << std::endl;
		Santa.executeForm(RobbotomyForm);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	Santa.signForm(Sample);
	Santa.signForm(Sample1);
	Santa.signForm(Sample2);
	Santa.signForm(Sample3);
	Santa.signForm(Sample4);

	try {
		std::cout << "Santa is trying to execute the form" << std::endl;
		Santa.executeForm(RobbotomyForm);
		Santa.executeForm(Sample);
		Santa.executeForm(Sample1);
		Santa.executeForm(Sample2);
		Santa.executeForm(Sample3);
		Santa.executeForm(Sample4);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}


	std::cout << "\n\n*********💂‍♀️Presidential Pardon Form test💂‍♀️**********" << std::endl;

	PresidentialPardonForm Presidential("Madame President");

	std::cout << Presidential << std::endl;
	
		try {
		std::cout << "elf is trying to sign the form" << std::endl;
		Presidential.beSigned(Elf);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	Santa.signForm(Presidential);
	try {
		std::cout << "elf is trying to execute the form" << std::endl;
		Elf.executeForm(Presidential);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Santa is trying to execute the form" << std::endl;
		Santa.executeForm(Presidential);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}