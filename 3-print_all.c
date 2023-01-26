#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


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
	printf("%c", ch);
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
		printf("(nil)");
	else
		printf("%s", str);
}
/**
 * print_float - prints a char
 * @ap: list of charcters
 */
void print_float(va_list ap)
{
	float num;

	num = va_arg(ap, double);
	printf("%f", num);
}

/**
 * print_string - prints a char
 * @ap: list of charcters
 */
void print_int(va_list ap)
{
	int num;

	num = va_arg(ap, int);
	printf("%d", num);
}

/**
* print_all - prints any type of data
* @format: memroy pointed by s
*
* Return: int
*/
void print_all(const char * const format, ...)
{
	int i = 0, j = 0;
	typedef struct
	{
		const char id;
		void (*f)(va_list);
	} fmt_t;

	fmt_t fmts[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_string},
		{'\0', NULL},
	};

	va_list ap;

	va_start(ap, format);

	while (format[i] != '\0')
	{
		j = 0;
		while (fmts[j].id)
		{
			if (format[i] == fmts[j].id)
			{
				fmts[j].f(ap);
				if (format[i + 1] != '\0')
					printf(", ");
				break;
			}
			j++;
		}
		i++;
	}

	printf("\n");
	va_end(ap);
}
