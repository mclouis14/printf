#include "main.h"

/**
 * _printf - Function to print formatted output.
 * @format: Handles the format specifiers 'c', 's', and '%'.
 * Return: number of chararcters printed
 */
int _printf(const char *format, ...)
{
	va_list mala;
	int projt = 0;
	const char *s;

	va_start(mala, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				putchar(va_arg(mala, int));
			}
			if (*format == 's')
			{
				s = va_arg(mala, const char*);
				while (*s)
				{
					putchar(*s);
					s++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				projt++;
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
