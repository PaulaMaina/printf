#include "main.h"

/**
 * get_flag - computes active flags
 * @format: formatted string
 * @p: takes a param
 *
 * Return: flags
 */

int get_flag(const char *format, int *p)
{
	int b, a;
	int flag = 0;
	const char FLAG_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const char FLAG_AR[] = {P_MINUS, P_PLUS, P_ZERO, P_HASH, P_SPACE, 0};

	for (a = *p + 1; format[a] != '\0'; a++)
	{
		for (b = 0; FLAG_CH[b] != '\0'; b++)
		{
			if (format[a] == FLAG_CH[b])
			{
				flag |= FLAG_AR[b];
				break;
			}
		}

		if (FLAG_CH[b] == 0)
			break;
	}
	*p = a - 1;

	return (flag);
}
