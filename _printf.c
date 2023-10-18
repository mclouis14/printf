#include "main.h"

/**
 * _printf - Function to print formatted output.
 * @format: Handles the format specifiers 'c', 's', and '%'.
 * Return: number of chararcters printed
 */
int _printf(const char *format, ...)
{
	va_list mala;
	int c, projt = 0;
	const char *s;

	va_start(mala, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(mala, int);
				printf("%c", c);
			}
			if (*format == 's')
			{
				s = va_arg(mala, const char*);
				printf("%s", s);
			}
			else if (*format == '%')
			{
				printf("%%");
			}
		}
		else
		{
			printf("%c", *format);
		}
		format++;
	}
	va_end(mala);

	return (projt);
}
