#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	std::cout << "CONSTRUCTING DEFAULT:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	Bureaucrat def;

	std::cout << def << std::endl;
	std::cout << "Bureaucrat: " << def.getName() << \
		", Grade: " << def.getGrade() << std::endl;

	try
	{
		def.incrementGrade();
		def.decrementGrade();
		def.decrementGrade();
	}
	catch(const std::exception& err)
	{
		std::cerr << err.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "CONSTRUCTING WITH GRADE -49:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	try
	{
		Bureaucrat bill("Bill", -49);
	}
	catch(const std::exception& err)
	{
		std::cerr << err.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "CONSTRUCTING WITH GRADE 200:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	try
	{
		Bureaucrat john("John", 200);
	}
	catch(const std::exception& err)
	{
		std::cerr << err.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "CONSTRUCTING WITH GRADE 1:" << std::endl;
	std::cout << "----------------------------" << std::endl;

	Bureaucrat sam("Sam", 1);
	Bureaucrat jack(sam);
	Bureaucrat kevin;

	std::cout << std::endl;
	try
	{
		sam.incrementGrade();
	}
	catch(const std::exception& err)
	{
		std::cerr << err.what() << std::endl;
	}

	sam.decrementGrade();
	std::cout << std::endl;

	std::cout << sam << std::endl;
	std::cout << jack << std::endl;
	std::cout << std::endl;

	kevin = jack;

	std::cout << jack << std::endl;
	std::cout << kevin << std::endl;
	std::cout << std::endl;

	return 0;
}
