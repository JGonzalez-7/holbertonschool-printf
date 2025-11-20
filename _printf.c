#include "main.h"

/**
 * _printf - custom printf function
 * @format: format string to parse
 *
 * Return: number of printed characters
 */
int _printf(const char *format, ...)
{
	va_list args;          /* handle variable arguments */
	int i = 0;             /* index for format string */
	int count = 0;         /* total characters printed */

	if (!format)           /* null format string check */
		return (-1);

	va_start(args, format); /* initialize argument list */

	while (format && format[i])     /* loop through format chars */
	{
		if (format[i] == '%')       /* check for format specifier */
		{
			i++;                    /* move to specifier char */

			/* handle integer formats */
			if (format[i] == 'd' || format[i] == 'i')
				count += print_number(va_arg(args, int));

			/* handle literal '%' */
			else if (format[i] == '%')
				count += _putchar('%');

			/* unrecognized specifier: print it literally */
			else
				count += _putchar(format[i]);
		}
		else
			count += _putchar(format[i]); /* normal character */

		i++;        /* move to next character */
	}

	va_end(args);           /* cleanup */
	return (count);         /* return total printed chars */
}
