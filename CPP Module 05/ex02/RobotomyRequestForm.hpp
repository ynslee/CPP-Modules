#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {

	private:
	RobotomyRequestForm();
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

	public:
    RobotomyRequestForm(std::string const &target);
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &other);

    void execute(Bureaucrat const &executor) const override;

	class RobotomyFailedException : public std::exception {
		public:
		const char *what() const noexcept override{
			return ("Robotomy failed. ");
		};
	};

};

#endif