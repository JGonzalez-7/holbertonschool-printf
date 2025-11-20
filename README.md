# Printf Project

A custom implementation of the C standard library function printf.
This project recreates core printf behavior and helps developers
understand variadic functions, low-level system calls, and formatted
output processing in C.

Overview
--------
This project focuses on building a simplified version of printf.
It supports essential format specifiers and mimics the standard
library’s behavior. It provides practical experience with:

- Variadic functions (stdarg.h)
- Manual output handling using write()
- Implementing formatting logic
- Modular C design and debugging

Purpose
-------
- Strengthen knowledge of C programming fundamentals
- Provide insight into how core standard library functions operate internally
- Encourage teamwork and collaborative problem-solving
- Build a reliable and maintainable custom printf function

Features
--------
- Fully custom _printf implementation
- Supports a subset of printf format specifiers
- Modular source code for easier maintenance
- Error handling and consistent output formatting
- Includes test cases for verification

Intended Audience
-----------------
- Holberton School students learning low-level programming
- New C developers exploring variadic functions
- Anyone interested in how printf works internally

Supported Specifiers
--------------------
A format specifier is a set of characters that tells a formatted
I/O function how to process and display data.

Specifier | Description                          | Example
%c        | Prints a single character             | H
%s        | Prints a string                       | Hello
%%        | Prints a literal percent sign         | %
%d        | Prints a signed decimal integer       | 42
%i        | Prints a signed integer (same as %d)  | 42

Compilation Instructions
------------------------
Compile the project using the command shown below
(used on Ubuntu 20.04 LTS):

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c

Language
--------
The project is written entirely in C. As a low-level language,
C allows developers to build functions from the ground up and control
every detail of how data is processed and displayed. Implementing a
custom printf provides deep insight into memory handling, system calls,
and variadic functions.

## Contributors
This project was completed as a team effort by:

**Joshua Gonzalez:** [GitHub Profile](https://github.com/JGonzalez-7)
[LinkedIn Profile](www.linkedin.com/in/joshua-gonzalez)

Hello, I’m Joshua Gonzalez, one of the developers who worked on this project. Feel free to explore my work and connect with me on LinkedIn. I’m excited about the possibility of collaborating and exchanging ideas with you.
