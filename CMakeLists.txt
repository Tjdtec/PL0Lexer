cmake_minimum_required(VERSION 3.25)
project(WindowsLexer C)

set(CMAKE_C_STANDARD 11)

add_executable(WindowsLexer DFA_DIR/main.c DFA_DIR/lexer.h DFA_DIR/lexer_function.c DFA_DIR/tool_function.c)
