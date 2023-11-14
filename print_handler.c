#include "main.h"

/**
 * print_handler - prints an arg depending on its type
 * @fmrt: formatted list
 * @p: args to be printed
 * @list: list of args
 * @buf: pointer to the buffer
 * @flag: computes active flags
 * @wid: width
 * @prec: precision
 * @size: size
 *
 * Return: 1 or 2
 */

int print_handler(const char *fmrt, int *p,
		va_list list, char buf[], int flag, int wid, int prec, int size)
{
	int a, len = 0, printed = -1;
	print_t types[] = {
		{'c', printf_char}, {'s', printf_str}, {'%', printf_perc},
		{'i', printf_int}, {'d', printf_int}, {'b', printf_bin},
		{'u', printf_unsign}, {'o', printf_oct}, {'x', printf_hex},
		{'X', printf_upp}, {'p', printf_ptr}, {'S', printf_nonprint},
		{'r', printf_rev}, {'R', printf_rot13}, {'\0', NULL}
	};
	for (a = 0; types[a].fmrt != '\0'; a++)
	{
		if (fmrt[*p] == types[a].fmrt)
			return (types[a].func(list, buf, flag, wid, prec,
						size));
	}

	if (types[a].fmrt == '\0')
	{
		if (fmrt[*p] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (fmrt[*p - 1] == ' ')
			len += write(1, " ", 1);
		else if (wid)
		{
			--(*p);
			while (fmrt[*p] != ' ' && fmrt[*p] != '%')
				--(*p);
			if (fmrt[*p] == ' ')
				--(*p);
			return (1);
		}
		len += write(1, &fmrt[*p], 1);
		return (len);
	}
	return (printed);
}
