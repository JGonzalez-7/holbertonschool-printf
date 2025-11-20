#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h> /* Needed for va_list handling */
#include <stdlib.h> /* General utilities like NULL */
#include <unistd.h> /* write() for direct stdout output */

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
