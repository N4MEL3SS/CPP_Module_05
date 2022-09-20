#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

# define COUNT_FORMS 3
# define NOT_FOUND_FORM -1;

class Form;

class Intern
{
public:
	Intern();
	Intern(Intern const &origin);

	~Intern();

	Intern & operator = (Intern const &origin);

	static Form *makeForm(const std::string& form_name, const std::string& form_target);

	class FormNotFoundException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

#endif //INTERN_HPP
