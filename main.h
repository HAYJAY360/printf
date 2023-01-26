#ifndef MAIN_H
#define MAIN_H

#include <cstdarg>
#include <stdio.h>

typedef struct
{
	const char id;
	void (*f)(va_list);
} fmt_t;

int _putchar(char c);
void print_char(va_list ap);
void print_string(va_list ap);
int _printf(const char *format, ...);



#endif /* MAIN_H */
