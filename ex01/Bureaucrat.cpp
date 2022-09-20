#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("DefaultName"), _grade(MIN_GRADE)
{
	std::cout << "A default Bureaucrat has been constructed" << " (" << this << ")\n";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	if (grade > MIN_GRADE)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade < MAX_GRADE)
		throw (Bureaucrat::GradeTooHighException());
	else
	{
		this->_grade = grade;
		std::cout << "A Bureaucrat " << this->_name << " with a grade " \
		<< this->_grade << " has been constructed" << " (" << this << ")\n";
	}
}


Bureaucrat::Bureaucrat(const Bureaucrat &origin)
{
	this->_name = origin.getName() + "_copy";
	this->_grade = origin.getGrade();

	std::cout << "A Bureaucrat " << this->_name << " with a grade " << \
	this->_grade << " has been constructed from a copy" << " (" << this <<")\n";
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &origin)
{
	this->_name = origin.getName() + "_operator_copy";
	this->_grade = origin.getGrade();

	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << this->_name << " has been destroyed" << " (" << this << ")\n";
}


void Bureaucrat::incrementGrade()
{
	std::cout << "Incrementing bureaucrat " << this->_name << \
		" grade " << this->_grade << " by 1\n";

	if (this->_grade - 1 < MAX_GRADE)
		throw (Bureaucrat::GradeTooHighException());
	else
		this->_grade--;

	std::cout << "New grade: " << this->_grade << "\n";
}

void Bureaucrat::decrementGrade()
{
	std::cout << "Decrementing bureaucrat " << this->_name << \
		" grade " << this->_grade << " by 1\n";

	if (this->_grade + 1 > MIN_GRADE)
		throw (Bureaucrat::GradeTooLowException());
	else
		this->_grade++;

	std::cout << "New grade: " << this->_grade << "\n";
}

void Bureaucrat::signForm(class Form &form)
{
	try
	{
		form.beSigned(*this);

		std::cout << "Bureaucrat " << this->_name << " with a grade " << \
			this->_grade << " successfully signs " << form << std::endl;
	}
	catch (const std::exception& err)
	{
		std::cout << "Bureaucrat " << this->_name << " with a grade " << \
			this->_grade << " cannot sign " << form << " because " << err.what() \
				<< std::endl;
	}
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("BureaucratException: Cannot get a grade > 150!");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("BureaucratException: Cannot get a grade < 1!");
}

std::ostream &operator << (std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << "Bureaucrat " << bureaucrat.getName() << " with a grade " << bureaucrat.getGrade();
	return (out);
}
