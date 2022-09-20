cmake_minimum_required(VERSION 3.21)
project(Module_5)

set(CMAKE_CXX_STANDARD 98)
add_compile_options(-Wall -Wextra -Werror)

add_executable(Module_5_ex00 ex00/main.cpp ex00/Bureaucrat.cpp ex00/Bureaucrat.hpp)
add_executable(Module_5_ex01 ex01/main.cpp ex01/Bureaucrat.cpp ex01/Bureaucrat.hpp ex01/Form.cpp ex01/Form.hpp)
add_executable(Module_5_ex02 ex02/main.cpp ex02/Bureaucrat.cpp ex02/Bureaucrat.hpp ex02/Form.cpp ex02/Form.hpp ex02/PresidentialPardonForm.cpp ex02/PresidentialPardonForm.hpp ex02/RobotomyRequestForm.cpp ex02/RobotomyRequestForm.hpp ex02/ShrubberyCreationForm.cpp ex02/ShrubberyCreationForm.hpp)
add_executable(Module_5_ex03 ex03/main.cpp ex03/Bureaucrat.cpp ex03/Bureaucrat.hpp ex03/Form.cpp ex03/Form.hpp ex03/PresidentialPardonForm.cpp ex03/PresidentialPardonForm.hpp ex03/RobotomyRequestForm.cpp ex03/RobotomyRequestForm.hpp ex03/ShrubberyCreationForm.cpp ex03/ShrubberyCreationForm.hpp ex03/Intern.cpp ex03/Intern.hpp)
