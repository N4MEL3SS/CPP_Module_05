#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : \
	Form("Default Presidential Pardon Form", 25, 5)
{
	this->_target = "Default";

	std::cout << this->_target << "Presidential Pardon has been constructed" \
		<< " (" <<this <<")" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) \
	: Form("Presidential Pardon Form", 25, 5)
{
	this->_target = target;

	std::cout << this->_target << "Presidential Pardon has been constructed" \
		<< " (" <<this <<")" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm
	&origin) : Form(origin.getName(), origin.getGradeToSign(), \
		origin.getGradeToExecute())
{
	this->_target = origin.getTarget();

	std::cout << this->_target << "Presidential Pardon has been constructed from a copy" \
		<< " (" <<this <<")" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << this->_target << "Presidential Pardon has been destroyed" \
		<< " (" <<this <<")" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator = (const
		PresidentialPardonForm &origin)
{
	this->_target = origin.getTarget();

	return *this;
}

std::string PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!this->getSigned())
		throw (Form::UnsignedFormException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw (Form::GradeTooLowException());
	else
		std::cout << this->_target << " was pardoned by Zafod Beeblebrox" << std::endl;
}
