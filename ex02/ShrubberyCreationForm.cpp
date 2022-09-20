#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() \
	: Form("Default Shrubbery Creation Form", 145, 137)
{
	this->_target = "Default";

	std::cout << this->_target << "Shrubbery Creation has been constructed" \
		<< " (" <<this <<")" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) \
	: Form("Default Shrubbery Creation Form", 145, 137)
{
	this->_target = target;

	std::cout << this->_target << "Shrubbery Creation has been constructed" \
		<< " (" <<this <<")" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm&origin)
	: Form(origin.getName(), origin.getGradeToSign(), \
		origin.getGradeToExecute())
{
	this->_target = origin.getTarget();

	std::cout << this->_target << "Shrubbery Creation has been constructed from a copy" \
		<< " (" <<this <<")" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << this->_target << "Shrubbery Creation has been destroyed" \
		<< " (" <<this <<")" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const
ShrubberyCreationForm &origin)
{
	this->_target = origin.getTarget();

	return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::string	tree =
	"			&&& &&  & &&			"
	"	  && &\\/&\\|& ()|/ @, &&		"
	"	  &\\/(/&/&||/& /_/)_&/_&		"
	"	&() &\\/&|()|/&\\/ '% & ()		"
	"	&_\\_&&_\\ |& |&&/&__%_/_& &&	"
	"	&&  && & &| &| /& & % ()& /&&	"
	"	()&_--()&\\&\\|&&-&&--%---()~	"
	"			  \\|||					"
	"				|||					"
	"				|||					"
	"				|||					"
	"		  , -=-~  .-^- _			"
	"							   ejm97";

	if (!this->getSigned())
		throw (Form::UnsignedFormException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw (Form::GradeTooLowException());
	else
	{
		std::string file_name = this->getTarget();
		file_name.append("_shrubbery");
		std::ofstream out(file_name.c_str());

		if (!out.is_open())
		{
			std::cout << "Couldn't open the output file" << std::endl;
			return ;
		}
		out << tree;
	}
}
