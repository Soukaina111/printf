#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#include <unistd.h>

/**
 * _put - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _put(char c, int l)
{
	return (write(1, &c, l));
}

/**
 * _printf - Start of function that produces output according to a format.
 * @format: Pointer
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int cont = 0, len;
	char c;
	char *str;
	va_list arg;

	if (format == NULL)
		return (-1);
	va_start(arg, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			_put(format, 1);
			cont++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
			{
				c = va_arg(arg, int);
				_put(c, 1);
				cont++;
			}
			else if (*format == 's')
			{
				str = va_arg(arg, char*);
				len = 0;
				while (str[len] = '\0')
					len++;
				_put(str, len);
				cont = cont + len;
			}
			else if (*format == '%')
			{
				_put(format, 1);
				cont++;
			}
		}
		format++;
	}
	va_end(arg);
	return (cont);
}
