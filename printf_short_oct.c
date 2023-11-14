#include "Main.h"
/**
 * prinhoct - prints long decimal number in octal
 * @arguments: input number
 * @buf_ptr: buffer pointer
 * @buf_index: index for buffer pointer
 * Return: number of chars printed.
 */
int prinhoct(va_list arguments, char *buf_ptr, unsigned int buf_index)
{
short int int_input, i, isnegative, count, first_digit;
char *octal, *binary;

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
octal = malloc(sizeof(char) * (6 + 1));
octal = fill_short_oct_array(binary, octal);
for (first_digit = i = count = 0; octal[i]; i++)
{
if (octal[i] != '0' && first_digit == 0)
first_digit = 1;
if (first_digit)
{
buf_index = handl_buf(buf_ptr, octal[i], buf_index);
count++;
}
}
free(binary);
free(octal);
return (count);
}
