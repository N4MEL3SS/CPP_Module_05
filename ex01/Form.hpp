#ifndef FORM_HPP
# define FORM_HPP

# pragma once

# include <string>
# include <iostream>

# include "Bureaucrat.hpp"

# define MIN_GRADE 150
# define MAX_GRADE 1

class Bureaucrat;

class Form
{
public:
	Form();
	Form(const std::string& name, int grade_to_sign, int grade_to_execute);
	Form(Form const &origin);

	~Form();

	Form & operator=(Form const & ref);

	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	std::string getName() const;

	void setSigned(bool new_value);

	void beSigned(Bureaucrat &bureaucrat);

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

private:
	const std::string _name;
	const int _gradeToSign;
	const int _gradeToExecute;
	bool _isSigned;
};

std::ostream &operator << (std::ostream &out, const Form &form);

#endif //FORM_HPP
