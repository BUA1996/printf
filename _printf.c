#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int _printf(const char *format, ...);

/**
 * _printf - is a custom printf function in C
 * @format: format variable string for the function
 * Return: the str, char or values input
 */

int _printf(const char *format, ...)
{
	int print = 0;
	va_list args;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			print++;
		}
		else
		{
			format++;
			if (*format == '%')
			{
				write(1, format, 1);
				print++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				int strlen = 0;

				while (str[strlen] != '\0')
				{
					strlen++;
				}
				write(1, str, strlen);
				print += strlen;
			}
			else if (*format == 'c')
			{
				char notst = (char)va_arg(args, int);

				write(1, &notst, 1);
				print++;
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);

				print += print_integer(num);
			}
			else if (*format == 'b')
			{
				unsigned int num = va_arg(args, unsigned int);

				print += print_binary(num);
			}
			else
			{
				format--;
				write(1, format, 1);
				print++;
			}
		}

		format++;
	}
	va_end(args);
	return (print);
}
