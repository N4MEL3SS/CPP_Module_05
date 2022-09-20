#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include <iomanip>
# include <fstream>

# include "Form.hpp"

class Form;

class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(ShrubberyCreationForm const &origin);

	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator = (ShrubberyCreationForm const &origin);

	std::string	getTarget() const;

	void execute(Bureaucrat const & executor) const;

private:
	std::string	_target;
};

#endif //SHRUBBERY_CREATION_FORM_HPP
