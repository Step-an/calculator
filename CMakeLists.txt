cmake_minimum_required(VERSION 4.1)
project(calculator)

set(CMAKE_CXX_STANDARD 26)

add_executable(calculator main.cpp
        Lexer.cpp
        Lexer.h
        Token.cpp
        Token.h
        ToeknId.h)
