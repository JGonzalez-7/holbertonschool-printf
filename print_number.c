#include "main.h"

/**
 * print_number - prints an integer using _putchar
 * @n: number to print
 *
 * Return: number of characters printed
 */
int print_number(int n)
{
	unsigned int num;      /* store positive value for printing */
	int count = 0;         /* count of printed characters */

	if (n < 0)             /* handle negative numbers */
	{
		count += _putchar('-'); /* print minus sign */
		num = -n;               /* convert to positive */
	}
	else
		num = n;               /* keep number as positive */

	if (num / 10)           /* recurse if number has more digits */
		count += print_number(num / 10);

	/* print last digit */
	count += _putchar((num % 10) + '0');

	return (count);         /* return number of characters printed */
}
