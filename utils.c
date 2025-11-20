#include "main.h"

/**
 * _putchar - writes a character to stdout
 * @c: character to output
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	ssize_t written = write(1, &c, 1);

	if (written == -1)
		return (-1);
	return ((int)written);
}

/**
 * print_number - prints a signed long integer
 * @n: number to print
 * Return: number of characters written or -1 on error
 */
int print_num(int n)
{
	int count = 0;

	if (n < 0)
	{
		if (_putchar('-') == -1)
			return (-1);
		count++;
		n = -n;
	}

	if (n / 10)
	{
		int printed = print_number(n / 10);

		if (printed == -1)
			return (-1);
		count += printed;
	}

	if (_putchar((n % 10) + '0') == -1)
		return (-1);
	return (count + 1);
}

/**
 * print_base - prints an unsigned long in any base
 * @num: number to convert
 * @base: base to print (between 2 and 16)
 * @uppercase: flag for uppercase hexadecimal letters
 * Return: number of characters written or -1 on error
 */
int print_base(unsigned long num, int base, int uppercase)
{
	char *digits;
	int count = 0;

	if (base < 2 || base > 16)
		return (-1);

	digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

	if (num / (unsigned long)base)
	{
		int printed = print_base(num / (unsigned long)base, base, uppercase);

		if (printed == -1)
			return (-1);
		count += printed;
	}

	if (_putchar(digits[num % (unsigned long)base]) == -1)
		return (-1);
	return (count + 1);
}

