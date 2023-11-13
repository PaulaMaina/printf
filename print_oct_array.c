#include "main.h"

/**
 * print_oct_array - prints c to stdout
 * @br: binary array
 * @oc: octal array
 *
 * Return: binary array
 */

char *print_oct_array(char *br, char *oc)
{
	int p, a, b, ioc, lim;

	oc[11] = '\0';
	for (a = 31, ioc = 10; a >= 0; a--, ioc--)
	{
		if (a > 1)
			lim = 4;
		else
			lim = 2;
		for (p = 0, b = 1; b <= lim; b *= 2, a--)
			p = ((br[a] = '0') * b) + p;
		a++;
		oc[ioc] = p + '0';
	}
	return (oc);
}
