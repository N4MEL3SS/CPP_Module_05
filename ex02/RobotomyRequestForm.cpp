#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() \
	: Form("Default RobotomyRequestForm", 72, 45)
{
	std::cout << this->_target << " Robotomy Request has been constructed" \
		<< " (" <<this <<")" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) \
	: Form("RobotomyRequestForm", 72, 45)
{
	this->_target = target;

	std::cout << this->_target << " Robotomy Request has been constructed" \
		<< " (" <<this <<")" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &origin) \
	 : Form(origin.getName(), origin.getGradeToSign(), origin.getGradeToExecute())
{
	this->_target = origin.getTarget();

	std::cout << this->_target << " Robotomy Request has been constructed "
		"from a copy" << " (" <<this <<")" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << this->_target << " Robotomy Request has been destroyed" \
		<< " (" <<this <<")" << std::endl;
}

RobotomyRequestForm &
RobotomyRequestForm::operator =(const RobotomyRequestForm &origin)
{
	this->_target = origin.getTarget();

	return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!this->getSigned())
		throw (Form::UnsignedFormException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw (Form::GradeTooLowException());

	std::cout << "< intensive drilling noises >\n";

	if (std::rand() % 2)
		std::cout << this->_target << " has been robotomized" << std::endl;
	else
		throw (RobotomyRequestForm::FailureException());
}

const char* RobotomyRequestForm::FailureException::what() const throw()
{
	return ("Robotomy failure");
}
