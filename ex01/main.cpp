#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat	bob("Bob", 1);
	Bureaucrat	bill("Bill", 132);

	std::cout << std::endl;
	std::cout << "CONSTRUCTING FORM:" << std::endl;
	std::cout << "----------------------------" << std::endl;

	Form c_form("C14", 4, 6);
	Form d_form("D02", 146, 135);

	try
	{
		Form p_form("P69", 666, 1337);
	}
	catch(const std::exception& err)
	{
		std::cerr << err.what() << std::endl;
	}

	try
	{
		Form p_form("P69", -666, -1337);
	}
	catch(const std::exception& err)
	{
		std::cerr << err.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "SIGN FORMS:" << std::endl;
	std::cout << "----------------------------" << std::endl;

	std::cout << "SIGN OK:" << std::endl;
	bob.signForm(c_form);
	std::cout << std::endl;

	std::cout << "SIGN KO:" << std::endl;
	bill.signForm(c_form);

	std::cout << std::endl;
	std::cout << "DESTRUCTORS:" << std::endl;
	std::cout << "----------------------------" << std::endl;

	return 0;
}
