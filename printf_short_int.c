#include "Main.h"
/**
 * prinhint - prints a short interger
 * @argumets - input string
 * @buf_ptr - buffer pointer
 * @buf_index - index for buffer pointer
 * Return: number of chars printe
 */
int prinhint(va_list arguments, char *buf_ptr, unsigned int buf_index)
{
short int int_input;
unsigned short int int_in, i, div, int_temp, isneg;

int_input = va_arg(arguments, int);
isneg = 0;
if (int_input < 0)
{
int_in = int_input * -1;
buf_index = handl_buf(buf_ptr, '-', buf_index);
isneg = 1;
}
else
{
int_in = int_input;
}
int_temp = int_in;
div = 1;
while (int_temp > 0)
{
div *= 10;
int_temp /= 10;
}
for (i = 0; div /= 10, i++)
{
buf_index = handl_buf(buf_ptr, ((int_in / div) % 10) + '0', buf_index);
}
return (i + isneg);
}
