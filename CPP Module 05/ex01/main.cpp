#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	Form f("A very important form", 5, 3);
	std::cout << f << std::endl << std::endl;

	// Form a(f);
	// std::cout << a << std::endl;

	// Form b = a;
	// std::cout << a << std::endl;
	
	// a = b;
	// std::cout << a << std::endl;


	Bureaucrat m("Mark", 106);
	std::cout << m << std::endl << std::endl;
	
	Bureaucrat j("Johnson", 1);
	std::cout << j << std::endl << std::endl;
	
	m.signForm(f);
	std::cout << std::endl;

	f.beSigned(m);
	std::cout << std::endl;

	std::cout << f << std::endl << std::endl;

	j.signForm(f);
	std::cout << std::endl;

	std::cout << f << std::endl << std::endl;

	Form error("Error", 151, -1);
	std::cout << error << std::endl << std::endl;

	return 0;
}