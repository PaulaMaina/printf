#include "Main.h"
/**
 * prinhunt - prints a short unsigned integer
 * @arguments: number to print
 * @buf_ptr: buffer pointer
 * @buf_index: index for buffer pointer
 * Return: number of chars printed
 */
int prinhunt(va_list arguments, char *buf_ptr, unsigned int buf_index)
{
unsigned short int int_in, int_temp, i, div;
int_in = va_arg(arguments, unsigned int);
int_temp = int_in;
div = 1;

while  (int_temp > 9)
{
div *= 10;
int_temp /= 10;
}
for (i = 0; div > 0; div /= 10, i++)
{
buf_index = handl_buf(buf_ptr, ((int_in / div) % 10) + '0', buf_index);
}
return (i);
}
