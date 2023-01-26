include <stdarg.h>
#include <stdio.h>
#include "main.h"

void print_char(va_list ap);
void print_float(va_list ap);


/**
 * print_char - prints a char
 * @ap: list of charcters
 */
void print_char(va_list ap)
{
	char ch;

	ch = va_arg(ap, int);
	_putchar(ch);
}

/**
 * print_string - prints a char
 * @ap: list of charcters
 */
void print_string(va_list ap)
{
	char *str;

	str = va_arg(ap, char *);
	if (str == NULL)
	{
		_putchar('(');
		_putchar('n');
		_putchar('i');
		_putchar('l');
		_putchar(')');
	}
	else
	{
		while (str)
		{
			_putchar(*str);
			str++;
		}
	}
}

/**
 * _printf - std printf clone
 * @format: str format sepcifier
 * @...: va_list
 *
 * Return: int, number of charachters printed
*/
int _printf(const char *format, ...)
{
	int i = 0, j = 0;

	fmt_t fmts[] = {
		{'c', print_char},
		{'s', print_string},
		{'\0', NULL},
	};

	va_list ap;

	va_start(ap, format);

	if (format == NULL)
		return (-1);

	while (format[i] != '\0')
	{
		j = 0;
		while (fmts[j].id)
		{
			if (format[i] == fmts[j].id && format[i-1] == '%')
			{
				fmts[j].f(ap);
				if (format[i + 1] != '\0')
					_putchar(',');
				break;
			}
			j++;
		}
		i++;
	}

	_putchar('\n');
	va_end(ap);
	return (0);
}
