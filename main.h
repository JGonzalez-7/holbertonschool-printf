#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h> /* Needed for va_list handling */
#include <stdlib.h> /* General utilities like NULL */
#include <unistd.h> /* write() for direct stdout output */

/**
 * struct printer - maps a specifier to its handler
 * @spec: format specifier character (e.g. 'c', 's')
 * @fn: pointer to the function that knows how to print that specifier
 */
typedef struct printer
{
	char spec;
	int (*fn)(va_list ap);
} printer_t;

/**
 * _printf - custom printf implementation
 * @format: format string with directives
 * Return: count of characters printed
 */
int _printf(const char *format, ...);

/**
 * print_char - prints a single character
 * @ap: argument list containing the character
 * Return: number of characters written
 */
int print_char(va_list ap);

/**
 * print_string - prints a string
 * @ap: argument list containing the string
 * Return: number of characters written
 */
int print_string(va_list ap);

/**
 * print_percent - prints a literal percent sign
 * @ap: unused argument list
 * Return: number of characters written
 */
int print_percent(va_list ap);

/**
 * print_integer - prints signed integers
 * @ap: argument list containing the integer
 * Return: number of characters written
 */
int print_integer(va_list ap);

/**
 * print_binary - prints unsigned integers in binary
 * @ap: argument list containing the integer
 * Return: number of characters written
 */
int print_binary(va_list ap);

/**
 * print_unsigned - prints unsigned decimal integers
 * @ap: argument list containing the integer
 * Return: number of characters written
 */
int print_unsigned(va_list ap);

/**
 * print_octal - prints numbers in base 8
 * @ap: argument list containing the integer
 * Return: number of characters written
 */
int print_octal(va_list ap);

/**
 * print_hex_lower - prints numbers in base 16 lowercase
 * @ap: argument list containing the integer
 * Return: number of characters written
 */
int print_hex_lower(va_list ap);

/**
 * print_hex_upper - prints numbers in base 16 uppercase
 * @ap: argument list containing the integer
 * Return: number of characters written
 */
int print_hex_upper(va_list ap);

/**
 * print_S - prints strings with non-printable chars as hex
 * @ap: argument list containing the string
 * Return: number of characters written
 */
int print_S(va_list ap);

/**
 * print_pointer - prints memory addresses
 * @ap: argument list containing the pointer
 * Return: number of characters written
 */
int print_pointer(va_list ap);

/**
 * print_reverse - prints strings in reverse
 * @ap: argument list containing the string
 * Return: number of characters written
 */
int print_reverse(va_list ap);

/**
 * print_rot13 - prints strings encoded in rot13
 * @ap: argument list containing the string
 * Return: number of characters written
 */
int print_rot13(va_list ap);

/**
 * _putchar - writes a character to stdout
 * @c: character to output
 * Return: number of characters written
 */
int _putchar(char c);

/**
 * print_number - prints signed numbers recursively
 * @n: number to print
 * Return: number of characters written
 */
int print_number(int n);

/**
 * print_base - prints unsigned numbers in any base
 * @num: number to convert
 * @base: target base
 * @uppercase: flag for uppercase letters
 * Return: number of characters written
 */
int print_base(unsigned long num, int base, int uppercase);

#endif /* MAIN_H */
