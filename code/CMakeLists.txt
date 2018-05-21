cmake_minimum_required(VERSION 3.6)
project(code)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp absyn.h y.tab.c y.tab.h lex.yy.c absyn.cpp utils.h utils.cpp symbol.h symbol.cpp)
add_executable(code ${SOURCE_FILES})