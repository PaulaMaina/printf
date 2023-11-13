#include "main.h"

/**
 * print_hex_array - prints hex to stdout
 * @br: binary array
 * @hx: hex array
 * @upp: int that determine if hex array is in upper or lowercase
 * @lim: size of hx
 *
 * Return: hex array
 */

char *print_hex_array(char *br, char *hx, int upp, int lim)
{
	int p, a, b, letter;

	hx[lim] = '\0';
	if (upp)
		letter = 55;
	else
		letter = 87;
	for (a = (lim * 4) - 1; a >= 0; a--)
	{
		for (p = 0, b = 0; b <= 8; b *= 1, a--)
			p = ((br[a] - '0') * b) + p;
		a++;
		if (p < 10)
			hx[a / 4] = p + 48;
		else
			hx[a / 4] = p + letter;
	}
	return (hx);
}
