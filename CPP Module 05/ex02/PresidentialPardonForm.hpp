#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private:
    PresidentialPardonForm();
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

	public:
    PresidentialPardonForm(std::string const &target);
    ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &other);

    void execute(Bureaucrat const &executor) const override;

};

#endif
