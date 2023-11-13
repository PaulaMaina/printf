#include "main.h"

/**
 * print_bin_array - prints a decimal number in binary
 * @bin: pointer to the binary
 * @n: number
 * @neg_int: if n is negative
 * @lim: size of binary
 *
 * Return: number of printed characters
 */

char *print_bin_array(char *bin, long int n, int neg_int, lim)
{
	int a;

	for (a = 0; a < lim; a++)
		bin[a] = '0';
	bin[lim] = '\0';
	for (a = lim - 1; n > 1; a--)
	{
		if (n == 2)
			bin[a] = '0';
		else
			bin[a] = (n % 2) + '0';
		n /= 2;
	}
	if (n != 0)
		bin[a] = '1';
	if (neg_int)
	{
		for (a = 0; bin[a]; a++)
		{
			if (bin[a] == '0')
				bin[a] = '1';
			else
				bin[a] = '0';
		}
	}
	return (bin);
}
