#include "main.h"

/**
 * get_prec - computes the precision of a string
 * @format: formatted string
 * @p: arg list to be printed
 * @list:argument list
 *
 * Return: precision
 */

int get_prec(const char *format, int *p, va_list list)
{
	int a = *p + 1;
	int prec = -1;

	if (format[a] != '.')
		return (prec);

	prec = 0;

	for (a  += 1; format[a] != '\0'; a++)
	{
		if (digit(format[a]))
		{
			prec *= 10;
			prec += format[a] - '0';
		}
		else if (format[a] == '*')
		{
			a++;
			prec = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*p = a - 1;

	return (prec);
}
