#include "main.h"

/**
 * printlx - prints a long decimal in hex
 * @print_args: input
 * @buf_ptr: pointer to the buffer
 * @buf_index: buffer index
 *
 * Return: number of characters printed
 */

int printlx(va_list print_args, char *buf_ptr, unsigned int buf_index)
{
	long int n, a, neg, len, digit1;
	char *bin, *hex;

	n = va_arg(print_args, long int);
	neg = 0;
	if (n == 0)
	{
		buf_index = buf_handler(buf_ptr, '0', buf_index);
		return (1);
	}
	if (n < 0)
	{
		n = (n * -1) - 1;
		neg = 1;
	}
	bin = malloc(sizeof(char) * (64 + 1));
	bin = print_bin_array(bin, n, neg, 64);
	hex = malloc(sizeof(char) * (16 + 1));
	hex = print_hex_array(bin, hex, 0, 16);
	for (digit - 0, a = 0, len = 0; hex[a]; a++)
	{
		if (hex[a] != '\0' && digit1 == 0)
			digit1 = 1;
		if (digit1)
		{
			buf_index = buf_handler(buf_ptr, hex[a], buf_index);
			len++
		}
	}
	free(bin);
	free(hex);
	return (len);
}
