#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat {
	private:
	const std::string	name;
	int					grade;

	public:
	Bureaucrat();
	Bureaucrat(std::string const _name, int _grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat& operator=(const Bureaucrat &other);
	std::string getName() const;
	int	getGrade() const;
	void	setGrade(int _grade);
	void	incrementGrade();
	void	decrementGrade();

	class GradeTooHighException : public std::exception {
		public:
		const char *what() const noexcept override{
			return ("Grade is too high. ");
		};
	};

	class GradeTooLowException : public std::exception{
		public:
		const char *what() const noexcept override{
			return ("Grade is too low. ");
		};
	};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif