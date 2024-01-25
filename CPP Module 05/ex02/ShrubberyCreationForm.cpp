#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm(target, 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	(void)other;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	std::ofstream file(getName() + "_shrubbery");

	AForm::execute(executor);
	if (file.is_open()){
		file << "            ^" << std::endl;
		file << "           / \\" << std::endl;
		file << "          /___\\" << std::endl;
		file << "         /* * *\\" << std::endl;
		file << "        /_______\\" << std::endl;
		file << "       /*  * *  *\\" << std::endl;
		file << "      /___________\\" << std::endl;
		file << "     /*   * * *   *\\" << std::endl;
		file << "    /_______________\\" << std::endl;
		file << "   /*    * * * *    *\\" << std::endl;
		file << "  /___________________\\" << std::endl;
		file << "          |||||" << std::endl;
		file.close();

		std::cout << executor.getName() << " executed " << getName() << std::endl;
	}
	else{
		throw FileCantBeOpenedException();
	}

}