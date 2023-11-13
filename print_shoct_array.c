#include "main.h"

/**
 * print_shoct_array - computes a short octal num
 * @br: binary array
 * @oc: octal array
 *
 * Return: octal array
 */

char *print_shoct_array(char *br, char *oc)
{
	int p, a, b, iocm lim;

	oc[6] =  '\0';
	for (a = 15, ioc = 5; a >= 0; a--, ioc--)
	{
		if (a > 0)
			lim = 4;
		else
			lim = 1;
		for (p = 0, b = 1; b <= lim; b *= 2, a--)
			p = ((br[a] - '0') * b) + p;
		a++;
		oc[ioc] = p + '0';
	}
	return (oc);
}
