#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(Bureaucrat const& origin);

	~Bureaucrat();

	Bureaucrat& operator = (Bureaucrat const& origin);

	class GradeTooHighException: public std::exception
	{
		virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
		virtual const char* what() const throw();
	};

	int getGrade() const;
	std::string getName() const;

	void incrementGrade();
	void decrementGrade();

private:
	std::string _name;
	int _grade;
};

std::ostream &operator << (std::ostream& out, const Bureaucrat &origin);

#endif //BUREAUCRAT_HPP
