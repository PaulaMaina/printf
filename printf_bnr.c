#include "main.h"

/**
 * printf_bnr - prints a decimal num in binary
 * @print_args: input
 * @buf_ptr: pointer to the buffer
 * @buf_index: buffer index
 *
 * Return: num of printed characters
 */

int printf_bnr(va_list print_args, char *buf_ptr, unsigned int buf_index)
{
	int n, len, a, digit1, isneg;
	char *bin;

	n = va_arg(print_args, int);
	isneg = 0;
	if (n == 0)
	{
		buf_index = buf_handler(buf_ptr, '0', buf_index);
		return (1);
	}
	if (n < 0)
	{
		n = (n * -1) - 1;
		isneg = 1;
	}
	bin = malloc((32 + 1) * sizeof(char));
	bin = print_bin_array(bin, n, isneg, 32);
	digit1 = 0;
	for (len = a = 0; bin[a]; a++)
	{
		if (digit1 == 0 && bin[a] == '1')
			digit1 = 1;
		if (digit1 == 1)
		{
			buf_index = buf_handler(buf_ptr, bin[a], buf_index);
			len++;
		}
	}
	free(bin);
	return (len);
}
