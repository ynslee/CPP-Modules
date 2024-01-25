#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
	const std::string	name;
	bool	_signed;
	const int signGrade;
	const int executeGrade;
	AForm();
	AForm& operator=(const AForm &other);

	public:
	AForm(std::string const _name, const int _signGrade, const int _executeGrade);
	virtual ~AForm() = 0;
	AForm(const AForm &other);
	std::string getName() const;
	int	getSignGrade() const;
	int getExecuteGrade() const;
	bool	getSignedStatus() const;
	void beSigned(Bureaucrat &b);
	virtual void execute(Bureaucrat const & executor) const;

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
			return ("Form is already signed. \n");
		};
	};

	class NotSignedException : public std::exception{
		public:
		const char *what() const noexcept override{
			return ("Form is not signed. \n");
		};
	};

};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif
