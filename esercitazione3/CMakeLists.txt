cmake_minimum_required(VERSION 3.20) 
project(esercitazione_3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

set(SOURCES esercitazione3.cpp rational.hpp)
add_executable(esercitazione_3 ${SOURCES})