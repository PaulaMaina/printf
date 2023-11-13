#include "main.h"

/**
 * printf_hex - prints a decimal in hex
 * @print_args: input
 * @buf_ptr: pointer to the buffer
 * @buf_index: buffer index
 *
 * Return: number of printed characters
 */


int printf_hex(va_list print_args, char *buf_ptr, unsigned int buf_index)
{
	int n, a, neg, len, digit1;
	char *bin, *hex;

	n = va_arg(print_args, int);
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
	bin = malloc(sizeof(char) * (32 + 1));
	bin = print_bin_array(bin, n, neg, 32);
	hex = malloc(sizeof(char) * (8 + 1));
	hex = print_hex_array(bin, hex, 0, 8);
	for (digit1 = 0, a = 0, len = 0; hex[a]; a++)
	{
		if (hex[a] != '\0' && digit1 == 0)
			digit1 = 1;
		if (digit1)
		{
			buf_index = buf_handler(buf_ptr, hex, buf_index);
			len++;
		}
	}
	free(bin);
	free(hex);
	return (len);
}
