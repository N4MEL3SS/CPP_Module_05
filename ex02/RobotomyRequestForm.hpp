#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include <cstdlib>

# include "Form.hpp"

class Form;

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &origin);

	~RobotomyRequestForm();

	RobotomyRequestForm &operator = (RobotomyRequestForm const &origin);

	std::string	getTarget() const;

	void execute(Bureaucrat const & executor) const;

	class FailureException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

private:
	std::string	_target;
};

#endif //ROBOTOMY_REQUEST_FORM_HPP
