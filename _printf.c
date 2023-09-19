#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#include <unistd.h>

/**
 * _printf - Start of function that produces output according to a format.
 * @format: Pointer
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int cont = 0, len, var1, var2;
	char c;
	char *str;
	va_list arg;

	if ((format == NULL) || (format[0] == '%' && !format[1]))
		return (-1);
	va_start(arg, format);
	while (*format)
	{
		if (*format != '%')
		{
			_put(*format, 1);
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
				while (str[len] == '\0')
					len++;
				_put(*str, len);
				cont = cont + len;
			}
			else if (*format == '%')
			{
				_put(*format, 1);
				cont++;
			}
			else if (*format == 'd' )
			{
			
				var1 = (int)va_arg(arg, int);
                                _put(var1, 1);
				cont++;
			
			}

			 else if (*format == 'i' )
                        {

                                var2 = (int)va_arg(arg, int);
                                _put(var2, 1);
                                cont++;

                        }
		}
		format++;
	}
	va_end (arg);
	return (cont);
}
