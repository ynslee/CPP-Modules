#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
	const std::string	name;
	bool	_signed;
	const int signGrade;
	const int executeGrade;
	Form();

	public:
	Form(std::string const _name, bool _signed, const int _signGrade, const int _executeGrade);
	~Form();
	Form(const Form &other);
	Form& operator=(const Form &other);
	std::string getName() const;
	int	getSignGrade() const;
	int getExecuteGrade() const;
	bool	getSigned() const;
	void beSigned(Bureaucrat &b);
	void signForm(Bureaucrat &b);

	class GradeTooHighException : public std::exception {
		public:
		const char *what() const noexcept override{
			return ("Form : Grade is too high. ");
		};
	};

	class GradeTooLowException : public std::exception{
		public:
		const char *what() const noexcept override{
			return ("Form : Grade is too low. ");
		};
	};

	class AlreadySignedException : public std::exception{
		public:
		const char *what() const noexcept override{
			return ("Form is already signed. ");
		};
	};

	class BureaucratCantSignException : public std::exception{
		public:
		const char *what() const noexcept override{
			return (" because Bureaucrat has too low grade to sign. ");
		};
	};
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif