#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

typedef struct
{
	const char id;
	void (*f)(va_list);
} fmt_t;

int _putchar(char c);
int _printf(const char *format, ...);



#endif /* MAIN_H */
