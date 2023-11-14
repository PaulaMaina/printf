#include "main.h"

/**
 * get_wid - computes the width for printing
 * @format: input string
 * @p: list of arguments
 * @list: arg list
 *
 * Return: width
 */

int get_wid(const char *format, int *p, va_list list)
{
	int a;
	int wid = 0;

	for (a = *p + 1; format[a] != '\0'; a++)
	{
		if (digit(format[a]))
		{
			wid *= 10;
			wid += format[a] - '0';
		}
		else if (format[a] == '*')
		{
			a++;
			wid = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*p = a - 1;

	return (wid);
}
