#include "Main.h"
/**
 * prinhhex - prints a short decimal in hexadecimal
 * @arguments: input string
 * @buf_ptr: buffer pointer
 * @buf_index: index for buffer pointer
 * Return: number of chars printed
 */
int prinhhex(va_list arguments, char *buf_ptr, unsigned int buf_index)
{
short int Int_input, i, isnegatibe, count, first_digit;
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
binary = malloc(sizeof(char) * (16 + 1));
binary = fill_binary_array(binary, int_input, isnegative, 16);
hexadecimal = malloc(sizeof(char) * (4 + 1));
hexadecimal = fill_hex_array(binary, hexadecimal, 0, 4);
for (first_digit = i = count = 0; hexadecimal[i]; i++)
{
if (hexadecimal[i] != '0' && first_digit == 0)
first_digit = 1;
if (first_digit)
{
buf_ptr = handl_buf(buf_ptr, hexadecimal[i], buf_index);
count++;
}
}
free(binary);
free(hexadecimal);
return (count);
}

