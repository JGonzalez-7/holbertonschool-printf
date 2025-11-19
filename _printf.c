#include "main.h"

/**
 * find_printer - locates the correct handler for a specifier
 * @spec: format specifier to match
 * Return: pointer to the matching function, or NULL if none exists
 */
static int (*find_printer(char spec))(va_list)
{
	printer_t printers[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{0, NULL}
	};
	int i;

	for (i = 0; printers[i].spec != 0; i++)
	{
		if (printers[i].spec == spec)
			return (printers[i].fn);
	}

	return (NULL);
}

/**
 * _printf - produces output according to a format
 * @format: character string containing zero or more directives
 * Return: number of characters printed, or -1 on failure
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i, count = 0;
	int (*handler)(va_list);

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			if (_putchar(format[i]) == -1)
			{
				va_end(ap);
				return (-1);
			}
			count++;
			continue;
		}

		i++;
		if (format[i] == '\0')
		{
			va_end(ap);
			return (-1);
		}

		handler = find_printer(format[i]);
		if (handler != NULL)
		{
			int printed = handler(ap);

			if (printed == -1)
			{
				va_end(ap);
				return (-1);
			}
			count += printed;
		}
		else
		{
			if (_putchar('%') == -1 || _putchar(format[i]) == -1)
			{
				va_end(ap);
				return (-1);
			}
			count += 2;
		}
	}
	va_end(ap);

	return (count);
}

