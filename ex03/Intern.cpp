#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "An Intern has been constructed" \
		<< " (" <<this <<")" << std::endl;
}

Intern::Intern(const Intern &origin)
{
	(void)origin;
	std::cout << "An Intern has been constructed from a copy" \
		<< " (" <<this <<")" << std::endl;
}

Intern::~Intern()
{
	std::cout << "An Intern has been destroyed" \
		<< " (" <<this <<")" << std::endl;
}

Intern &Intern::operator = (const Intern &origin)
{
	(void)origin;
	return *this;
}

Form *Intern::makeForm(std::string name, std::string target)
{
	Form *form;
	int indexForm = NOT_FOUND_FORM;
	std::string forms[COUNT_FORMS] = {"PresidentialPardonForm", \
		"RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i < COUNT_FORMS; i++)
	{
		if (name == forms[i])
			indexForm = i;
	}

	switch (indexForm)
	{
		case 0:
			form = new PresidentialPardonForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new ShrubberyCreationForm(target);
			break;
		default:
			throw FormNotFoundException();
	}

	std:: cout << "Intern creates " << forms[indexForm] << std::endl;
	return form;
}

const char *Intern::FormNotFoundException::what() const throw() {
	return "Form not found";
}
