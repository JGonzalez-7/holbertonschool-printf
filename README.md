# Printf Project

A custom implementation of the C standard library function printf.
This project recreates core printf behavior and helps developers
understand variadic functions, low-level system calls, and formatted
output processing in C.

Overview
--------
This project focuses on building a simplified version of printf.
It supports essential format specifiers and mimics the standard
library's behavior. It provides practical experience with:

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

Project Structure
-----------------
Each contributor owns a clear slice of the codebase to keep responsibilities explicit:

- `_printf.c` - format-string parser and dispatcher (Person A)
- `print_char.c`, `print_string.c`, `print_percent.c` - `%c`, `%s`, and `%%` handlers (Person B)
- `utils.c` - shared helpers such as `_putchar`, `print_number`, and `print_base`
- `main.c` - manual test harness comparing `_printf` to the libc `printf`
- `main.h` - central header with structs, prototypes, and documentation

Future specifiers (integers, unsigned, hex, etc.) will follow the same pattern: Person A wires new directives into `_printf.c`, Person B implements the handler file and uses the helpers exposed through `main.h`.

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

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format \
    main.c _printf.c print_char.c print_string.c print_percent.c utils.c -o printf
```

The `-Wno-format` flag silences the intentional `%r` format in `main.c` while that specifier is still under development. Remove it once `%r` is implemented.

Usage
-----
```
_printf("Character:[%c] String:[%s] Percent:[%%]\n", 'H', "Holberton");
```
The function mirrors the standard `printf` return value semantics: it returns the number of characters written or `-1` on failure (for example if `format` is `NULL`).

Language
--------
The project is written entirely in C. As a low-level language,
C allows developers to build functions from the ground up and control
every detail of how data is processed and displayed. Implementing a
custom printf provides deep insight into memory handling, system calls,
and variadic functions.
