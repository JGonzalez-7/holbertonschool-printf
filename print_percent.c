#include "main.h"

/**
 * print_percent - prints a literal percent sign
 * @ap: variadic arguments provided by _printf (unused)
 * Return: number of characters written (1) or -1 on error
 */
int print_percent(va_list ap)
{
	(void)ap;

	return (_putchar('%'));
}

