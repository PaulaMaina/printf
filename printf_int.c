#include "main.h"

/**
 * printf_int - prints a number
 * @print_args: input
 * @buf_ptr: pointer to the buffer
 * @buf_index: buffer index
 *
 * Return: number of printed characters
 */

int printf_int(va_list print_args, char *buf_ptr, unsigned int buf_index)
{
	int n;
	unsigned int in, temp, a, div, neg, b;

	n = va_arg(print_arg, int);
	neg = 0;
	if (n < 0)
	{
		in = n * -1;
		buf_index = buf_handler(buf_ptr, '-', buf_index);
		neg = 1;
	}
	else
		in = n;
	temp = in;
	div = 1;

	while (temp > 9)
	{
		div *= 10;
		temp /= 10;
	}
	for (a = 0; div /= 10; a++)
	{
		b = ((in / div) % 10) + '0';
		buf_index = buf_handler(buf_ptr, b, buf_index);
	}
	return (a + neg);
}
