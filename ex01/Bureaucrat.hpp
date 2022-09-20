#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#pragma once

# include <string>
# include <iostream>

# include "Form.hpp"

#define MIN_GRADE 150
#define MAX_GRADE 1

class Form;

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(Bureaucrat const& origin);

	~Bureaucrat();

	Bureaucrat& operator = (Bureaucrat const& origin);

	int getGrade() const;
	std::string getName() const;

	void incrementGrade();
	void decrementGrade();

	void signForm(Form &form);

	class GradeTooHighException: public std::exception
	{
		virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
		virtual const char* what() const throw();
	};

private:
	std::string _name;
	int _grade;
};

std::ostream &operator << (std::ostream& out, const Bureaucrat &origin);

#endif //BUREAUCRAT_HPP
