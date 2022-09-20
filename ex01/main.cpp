#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "CONSTRUCTING FORM:" << std::endl;
	std::cout << "----------------------------" << std::endl;

	Form c_form("C14", 10, 5);
	Form d_form("D02", 100, 75);

	std::cout << std::endl;

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

	Bureaucrat	bob("Bob", 8);
	Bureaucrat	bill("Bill", 76);
	std::cout << std::endl;
	//-----------------------------------------------------


	std::cout << "SIGN FORMS:" << std::endl;
	std::cout << "----------------------------" << std::endl;

	std::cout << "SIGN BOB:" << std::endl;
	bob.signForm(c_form);
	bob.signForm(d_form);

	std::cout << std::endl;

	std::cout << "SIGN BILL:" << std::endl;
	bill.signForm(c_form);
	bill.signForm(d_form);
	//-----------------------------------------------------


	std::cout << std::endl;
	std::cout << "DESTRUCTORS:" << std::endl;
	std::cout << "----------------------------" << std::endl;

	return 0;
}
