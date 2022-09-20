#include "Form.hpp"

Form::Form() : _name("Default"), _gradeToSign(MIN_GRADE), \
	_gradeToExecute(MIN_GRADE), _isSigned(false)
{
	std::cout << this->_name << " has been constructed" \
		<< " (" <<this <<")" <<std::endl;
}

Form::Form(const std::string& name, int grade_to_sign, int grade_to_execute) : \
	_name(name), _gradeToSign(grade_to_sign), \
		_gradeToExecute(grade_to_execute), _isSigned(false)
{
	if (_gradeToSign > MIN_GRADE || _gradeToExecute > MIN_GRADE)
		throw (Form::GradeTooLowException());
	else if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw (Form::GradeTooHighException());
	else
		std::cout << this->_name << " has been constructed" \
			<< " (" <<this <<")" <<std::endl;
}

Form::Form(Form const &origin) : _name(origin.getName()),\
		_gradeToSign(origin.getGradeToSign()), \
			_gradeToExecute(origin.getGradeToExecute()), \
				_isSigned(origin.getSigned())
{
	std::cout << this->_name << " has been constructed from a copy" \
		<< " (" <<this <<")" <<std::endl;
}

Form::~Form()
{
	std::cout << this->_name << " has been destroyed" \
		<< " (" <<this <<")" <<std::endl;
}

Form & Form::operator = (Form const &origin)
{
	this->_isSigned = origin.getSigned();

	return *this;
}

std::string Form::getName() const
{
	return this->_name;
}

int Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

bool Form::getSigned() const
{
	return this->_isSigned;
}

void Form::setSigned(const bool new_value)
{
	std::cout << this << " signed value was set to " << new_value << std::endl;

	this->_isSigned = new_value;
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	int	grade = bureaucrat.getGrade();

	if (grade > _gradeToSign)
	{
		_isSigned = false;
		throw (Form::GradeTooLowException());
	}

	_isSigned = true;
	std::cout << this->_name << " was just signed by the bureaucrat " \
		<<bureaucrat.getName() << " with a grade " << bureaucrat.getGrade() << std::endl;
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("FormException: the grade is too low");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("FormException: the grade is too high");
};

const char* Form::UnsignedFormException::what() const throw()
{
	return ("Cannot execute an unsigned form");
};

std::ostream &operator << ( std::ostream &out, Form const &form)
{
	out << "Form " << form.getName() << " having a grade to sign " \
		<< form.getGradeToSign() << " and a grade to execute " \
			<< form.getGradeToExecute() << " with signed equal to " \
				<< form.getSigned();

	return (out);
}
