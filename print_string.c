#include "main.h"

/**
 * print_string - prints a string argument
 * @ap: variadic arguments provided by _printf
 * Return: number of characters written
 */
int print_string(va_list ap)
{
	char *str = va_arg(ap, char *);
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		if (_putchar(*str) == -1)
			return (-1);
		count++;
		str++;
	}

	return (count);
}

