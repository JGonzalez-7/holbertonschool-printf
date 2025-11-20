#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string to parse
 *
 * Return: number of printed characters, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list args;          /* handle variable arguments */
	int i = 0;             /* index through format string */
	int count = 0;         /* count of printed characters */
	char *str;             /* string pointer for %s */

	if (!format)           /* NULL format string check */
		return (-1);

	va_start(args, format); /* start processing arguments */

	while (format[i])       /* iterate through format text */
	{
		if (format[i] == '%')   /* found possible specifier */
		{
			if (format[i + 1] == '\0') /* trailing '%' is invalid */
			{
				va_end(args);
				return (-1);
			}

			i++;                /* move to specifier character */

			/* character format */
			if (format[i] == 'c')
				count += _putchar(va_arg(args, int));

			/* string format */
			else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				if (!str)
					str = "(null)";
				while (*str)
					count += _putchar(*str++);
			}

			/* integer formats (%d, %i) */
			else if (format[i] == 'd' || format[i] == 'i')
				count += print_number(va_arg(args, int));

			/* double percent "%%" */
			else if (format[i] == '%')
				count += _putchar('%');

			/* invalid specifier: print '%' + invalid char */
			else
			{
				count += _putchar('%');
				count += _putchar(format[i]);
			}
		}
		else
		{
			/* regular non-format character */
			count += _putchar(format[i]);
		}

		i++;                    /* advance to next character */
	}

	va_end(args);               /* clean up argument list */
	return (count);             /* return total printed chars */
}
