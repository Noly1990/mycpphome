cmake_minimum_required(VERSION 2.8.4)
project(my_cpp_home)

set(CMAKE_CXX_STANDARD 20)

add_executable(my_cpp_home main.cpp contacts/contacts.cpp contacts/contacts.h)