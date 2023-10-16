#include "main.h"
#include <stdio.h>
/**
 * _printf - The function produces output according to a format
 * @format: pointer that iterates through strings
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list collab;
	int printed_chars = 0;
	const char c, *str;

	va_start(collab, format);

	while (*format)
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				c = va_arg(collab, int);
				printed_chars += write(1, &c, 1);
			else if (*format == 's')
				for (str = va_arg(collab, const char *); *str; str++)
					printed_chars += write(1, str, 1);
			else if (*format == '%')
				printed_chars += write(1, "%", 1);
		}
		else
			printed_chars += write(1, format, 1);

	va_end(collab);
	return (printed_chars);
}
