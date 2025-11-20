#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string to parse
 *
 * Return: number of printed characters, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list args;      /* argument list */
	int i = 0;         /* index for format string */
	int count = 0;     /* total printed characters */
	char *str;         /* string pointer for %s */

	if (!format)       /* handle NULL format string */
		return (-1);

	va_start(args, format); /* initialize argument list */

	while (format[i])       /* loop through format string */
	{
		if (format[i] == '%')   /* found a format specifier */
		{
			/* FIX: handle incomplete format: "%" at end */
			if (format[i + 1] == '\0')
			{
				va_end(args);
				return (-1);
			}

			i++;                /* move to actual specifier */

			if (format[i] == 'c')          /* char specifier */
				count += _putchar(va_arg(args, int));

			else if (format[i] == 's')     /* string specifier */
			{
				str = va_arg(args, char *);
				if (!str)
					str = "(null)";
				while (*str)
					count += _putchar(*str++);
			}

			else if (format[i] == 'd' || format[i] == 'i')
				count += print_number(va_arg(args, int)); /* integer */

			else if (format[i] == '%')     /* percent literal */
				count += _putchar('%');

			else                            /* invalid specifier */
				count += _putchar(format[i]);
		}
		else
			count += _putchar(format[i]);   /* normal character */

		i++;                                /* move to next char */
	}

	va_end(args);                           /* cleanup */
	return (count);                         /* return printed count */
}
