#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * _printf - Start of function that produces output according to a format.
 * @format: Pointer
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	char c;
	const char *s;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format+;
			if (*format == 'c')
			{
				c = va_arg(args, int);
				putchar(c);
				i++;
			}
			if (*format == 's')
			{
				s = va_arg(args, const char *);
				while (*s != '\0')
				{
					putchar(*s);
					s++;
					i++;
				}
			}
			if (*format == '%')
			{
				putchar('%');
				i++;
			}
			else
			{
				putchar('%');
				putchar(*format);
				i += 2;
			}
		}
		else
		{
		putchar(*format);
		i++;
		}
		format++;
	}
	va_end(args);
	return (i);
}
