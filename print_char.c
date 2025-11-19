#include "main.h"

/**
 * print_char - prints a single character from the argument list
 * @ap: variadic arguments provided by _printf
 * Return: number of characters written (always 1)
 */
int print_char(va_list ap)
{
	char c = (char)va_arg(ap, int);

	return (_putchar(c));
}

