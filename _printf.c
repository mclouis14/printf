#include "main.h"

/**
 * _printf - Function to print formatted output.
 * @format: Handles the format specifiers 'c', 's', and '%'.
 * Return: number of chararcters printed
 */
int _printf(const char *format, ...)
{
	int projt = 0;
	va_list mala;

	va_start(mala, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				int c = va_arg(mala, int);

				projt += printf("%c", c);
			}
			else if (*format == 's')
			{
				const char *s = va_arg(mala, const char *);

				projt += printf("%s", s);
			}
			else if (*format == '%')
			{
				projt += printf("%%");
			}
		}
		else
		{
			putchar(*format);
			projt++;
		}
		format++;
	}
	va_end(mala);
	return (projt);
}
