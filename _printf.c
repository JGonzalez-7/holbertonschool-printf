#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string to parse
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;      /* argument list */
	int i = 0;         /* index for format string */
	int count = 0;     /* number of printed characters */
	char *str;         /* string pointer for %s */

	if (!format)       /* handle NULL format */
		return (-1);

	va_start(args, format); /* initialize argument list */

	while (format[i])       /* iterate through format string */
	{
		if (format[i] == '%')   /* check for format specifier */
		{
			i++;                /* move to specifier char */

			if (format[i] == 'c')          /* handle char */
				count += _putchar(va_arg(args, int));

			else if (format[i] == 's')     /* handle string */
			{
				str = va_arg(args, char *);
				if (!str)
					str = "(null)";
				while (*str)
					count += _putchar(*str++);
			}

			else if (format[i] == 'd' || format[i] == 'i') /* integer */
				count += print_number(va_arg(args, int));

			else if (format[i] == '%')      /* print percent sign */
				count += _putchar('%');

			else                            /* invalid specifier */
				count += _putchar(format[i]);
		}
		else
			count += _putchar(format[i]);   /* normal character */

		i++;                                /* next character */
	}

	va_end(args);                           /* cleanup arguments */
	return (count);                         /* return count */
}
