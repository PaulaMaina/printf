#include "main.h"

/**
 * _printf - produces output based on a
 * particulat format
 * @format: the input string
 *
 * Return: number of printed characters
 */

int _printf(const char *format, ...)
{
	unsigned int a = 0, n = 0, buf_index = 0;
	va_list print_args;
	int (*func)(va_list, char *, unsigned int);
	char *b;	/* buffer */

	va_start(print_args, format), b = malloc(1024 * sizeof(char));
	if (!format || !b || (format[a] == '%' && !format[a + 1]))
		return (-1);
	if (!format[a])
		return (0);
	for (a = 0; format && format[a]; a++)
	{
		if (format[a] == '%')
		{
			if (format[a + 1] == '\0')
			{
				print_buff(b, buf_index), free(b), va_end(print_args);
				return (-1);
			}
			else
			{
				func = fetch_print_func(format, a + 1);
				if (func == NULL)
				{
					if (format[a + 1] == ' ' && !format[a + 2])
						return (-1);
					buf_handler(b, format[a], buf_index), n++, a--;
				}
				else
				{
					n += func(print_args, b, buf_index);
					a += fetch_print_func(format, a + 1);
				}
			} a++;
		}
		else
			buf_handler(b, format[a], buf_index), n++;
		for (buf_index = n; buf_index > 1024; buf_index -= 1024)
			;
	}
	print_buff(b, buf_index), free(b), va_end(print_args);
	return (n);
}
