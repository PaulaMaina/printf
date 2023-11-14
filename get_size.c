#include "main.h"

/**
 * get_size - computes the size to cast the arg
 * @format: formatted string
 * @p: args list
 *
 * Return: size
 */

int get_size(const char *format, int *p)
{
	int a = *p + 1;
	int size = 0;

	if (format[a] == 'l')
		size = I_LONG;
	else if (format[a] == 'h')
		size = I_SHORT;

	if (size == 0)
		*p = a - 1;
	else
		*p = a;

	return (size);
}
