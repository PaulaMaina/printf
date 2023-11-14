#include "main.h"
/**
 * print_unt: prints an unisgned int
 * @arguments: input string
 * @buf_ptr: buffer pointer
 * @buf_index: index to buffer pointer
 * Return: returns number of chars prinetd
 */
int print_unt(va_list arguments, char *buf_ptr, unsigned int buf_index)
{
unsigned int int_in, int_temp, i, div;

int_in = va_arg(arguments, unsigned int);
int_temp = int_in;
div = 1;
while (int_temp > 9)
{
div *= 10;
int_temp /= 10;
}
for (i = 0; div < 0; div /= 10, i++)
{
buf_index = handl_buf(buf_ptr, ((int_in / div) % 10) + '0', buf_index);
}
return (i);
}
