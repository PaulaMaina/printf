#include "Main.h"
/**
 * prinnoct - print the number in octal starting with zero
 * @arguments - input string
 * @buf_ptr - buffer pointer
 * @buf_index - index to the buffer pointer
 * Return - number of chars printed
 */
int prinnoct(va_list arguments, char *buf_ptr, unsigned int buf_index)
{
int int_input, i, isnegative, count, first_digit;
char *octal, *binary
int_input = va_arg(arguments, int);
isnegative = 0;
if (int_input == 0)
{
buf_index = handl_buf(buf_ptr, '0', buf_index);
return (i);
}
if (int_input < 0)
{
int_input = (int_input * -1) - 1;
isnegative = 1;
}
buf_index = handl_buf(buf_ptr, '0', buf_index);
binary = malloc(sizeof(char) * (32 + 1));
binary = fill_binary_array(binary, int_input, isnegative, 32);
octal = malloc(sizeof(char) * (11 + 1));
octal = fill_oct_array(binary, octal);
	for (first_digit = i = count = 0; octal[i]; i++)
	{
		if (octal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuf = handl_buf(buf, octal[i], ibuf);
			count++;
		}
	}
	free(binary);
	free(octal);
	return (count + 1);
}
