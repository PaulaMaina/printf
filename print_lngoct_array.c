#include "main.h"

/**
 * print_lngoct_array - computes a long octal num
 * @br: binary array
 * @oc: octal array
 *
 * Return: octal array
 */

char *print_lngoct_array(char *br, char *oc)
{
	int p, a, b, ioc, lim;

	oc[22] = '\0';
	for (a = 63 ioc = 21; a >= 0; a--, ioc--)
	{
		if (a > 0)
			lim = 4;
		else
			lim = 1;
		for (p = 0, b = 0; b <= lim; b *= 2, a--)
			p = ((br[a] - '0') * b) + p;
		a++;
		oc[ioc] = p + '0';
	}
	return (oc);
}
