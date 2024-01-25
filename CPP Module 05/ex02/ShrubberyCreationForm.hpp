#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

	private:
	ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

	public:
    ShrubberyCreationForm(std::string const &target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &other);

    void execute(Bureaucrat const &executor) const override;

	class FileCantBeOpenedException : public std::exception {
		public:
		const char *what() const noexcept override{
			return ("File can't be opened. ");
		};
	};

};

#endif
