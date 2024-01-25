#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	Form f("📄Doggo📄", 5, 3);
	std::cout << f << std::endl;

	// Form a(f);
	// std::cout << a << std::endl;

	// Form b = a;
	// std::cout << a << std::endl;
	
	// a = b;
	// std::cout << a << std::endl;


	Bureaucrat s("Sunny", 106);
	std::cout << s << std::endl;
	
	Bureaucrat c("Chuchi", 1);
	std::cout << c << std::endl << std::endl;
	
	s.signForm(f);
	std::cout << std::endl;

try {
	f.beSigned(s);
	std::cout << std::endl;
}
catch (std::exception &e) {
	std::cerr << "Caught Grade too low exception: " << e.what() << std::endl;
}

	std::cout << f << std::endl;

	c.signForm(f);
	std::cout << std::endl;

	std::cout << f << std::endl;

	c.signForm(f);
	std::cout << std::endl;

try {
	f.beSigned(c);
	std::cout << std::endl;
}
catch (Form::AlreadySignedException &e) {
	std::cerr << "Caught Already signed exceptiion: " << e.what() << std::endl;
}

try {
	Form error("Error", 151, 0);
} catch (const std::exception &e){
	std::cerr << "Caught in Grade exception  - can't make form" << std::endl;
}
	return 0;
}