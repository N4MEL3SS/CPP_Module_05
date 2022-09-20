#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "Form.hpp"

class Form;

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &origin);

	~PresidentialPardonForm();

	PresidentialPardonForm &operator = (PresidentialPardonForm const &origin);

	std::string	getTarget() const;

	void execute(Bureaucrat const & executor) const;

private:
	std::string	_target;
};

#endif //PRESIDENTIAL_PARDON_FORM_HPP
