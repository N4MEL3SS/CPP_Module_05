cmake_minimum_required(VERSION 3.21)
project(Module_5)

set(CMAKE_CXX_STANDARD 98)
add_compile_options(-Wall -Wextra -Werror)

add_executable(Module_5_ex00 ex00/main.cpp ex00/Bureaucrat.cpp ex00/Bureaucrat.hpp)
add_executable(Module_5_ex01 ex01/main.cpp)
add_executable(Module_5_ex02 ex02/main.cpp)
add_executable(Module_5_ex03 ex03/main.cpp)
