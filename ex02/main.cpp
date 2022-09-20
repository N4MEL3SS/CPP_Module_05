#include <iostream>
#include <ctime>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	std::srand(std::time(0));

	std::cout << std::endl;
	std::cout << "CONSTRUCTING:" << std::endl;
	std::cout << "----------------------------" << std::endl;

	Bureaucrat				bob("Bob", 1);
	Bureaucrat				bill("Bill", 142);
	PresidentialPardonForm	president("president");
	RobotomyRequestForm		robo("robo");
	ShrubberyCreationForm	shrub("shrub");

	std::cout << std::endl << std::endl;
	//-----------------------------------------------------


	std::cout << "SHRUBBERY CREATION FORM:" << std::endl;
	std::cout << "----------------------------" << std::endl;

	std::cout << std::endl << "[UNSIGNED]" << std::endl;
	bob.executeForm(shrub);
	shrub.beSigned(bob);

	std::cout << std::endl << "[SIGNED]" << std::endl;
	bob.executeForm(shrub);
	std::cout << std::endl;

	std::cout << std::endl << "[GRADE TO EXE TOO LOW]" << std::endl;
	bill.executeForm(shrub);
	std::cout << std::endl << std::endl;
	//-----------------------------------------------------


	std::cout << std::endl;
	std::cout << "ROBOTOMY REQUEST FORM:" << std::endl;
	std::cout << "----------------------------" << std::endl;

	std::cout << std::endl << "[UNSIGNED]" << std::endl;
	bob.executeForm(robo);
	robo.beSigned(bob);

	std::cout << std::endl << "[SIGNED (50% success chance)]" << std::endl;
	bob.executeForm(robo);
	std::cout << std::endl;
	bob.executeForm(robo);
	std::cout << std::endl;
	bob.executeForm(robo);
	std::cout << std::endl;
	bob.executeForm(robo);
	std::cout << std::endl;

	std::cout << std::endl << "[GRADE TO EXE TOO LOW]" << std::endl;
	bill.executeForm(robo);
	std::cout << std::endl << std::endl;
	//-----------------------------------------------------


	std::cout << std::endl;
	std::cout << "PRESIDENTIAL PARDON FORM:" << std::endl;
	std::cout << "----------------------------" << std::endl;

	std::cout << std::endl << "[UNSIGNED]" << std::endl;
	bob.executeForm(president);
	president.beSigned(bob);

	std::cout << std::endl << "[SIGNED]" << std::endl;
	bob.executeForm(president);
	std::cout << std::endl;

	std::cout << std::endl << "[GRADE TO EXE TOO LOW]" << std::endl;
	bill.executeForm(president);
	std::cout << std::endl << std::endl;
	//-----------------------------------------------------


	std::cout << std::endl;
	std::cout << "DESTRUCTORS:" << std::endl;
	std::cout << "----------------------------" << std::endl;

	return 0;
}
