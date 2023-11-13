#include "Main.h"
/**
 * prinhex - print number in hex beginning with zero
 * @arguments - input string
 * @buf_ptr - buffer pointer
 * @buf_index - index for buffer pointer
 * Return - number of chars printed
 */
int prinhex(var_list arguments, char *buf_ptr, unsigned int buf_index)
{
int int_input, i, isnegative, count, first_digit;
char *hexadecimal, *binary;

int_input = va_arg(arguments, int);
isnegative = 0;
if (int_input == 0)
{
buf_index = handl_buf(buf_ptr, '0', buf_index);
return (1);
}
if (int_input < 0)
{
int_input = (int_input * -1) - 1;
isnegative = 1;
}
buf_index = handl_buf(buf_ptr, '0', buf_index);
buf_index = handl_buf(buf_ptr, 'x', buf_index);
binary = malloc(sizeof(char) * (32 + 1));
binary = fill_binary_array(binary, int_input, isnegative, 32);
hexadecimal = malloc(sizeof(char) * (8 + 1));
hexadecimal = fill_hex_array(binary, hexadecimal, 0, 8);
for (first_digit = i = count = 0; hexadecimal[i]; i++)
{
if (hexadecimal[i] != '0' && first_digit == 0)
first_digit = 1;
if (first_digit)
{
buf_index = handl_buf(buf_ptr, hexadecima[i], buf_index);
count++;
}
}
free(binary);
free(hexadecimal);
return (count + 2);
}