#include "Main.H"
/*prinlunt - prints a long unsiged interger
 * @arguments - number to print
 * @buf_ptr - buffer pointer
 * @buf_index - index for buffer pointer
 * Return - number of chars printed
 */
int prinlunt(var_list arguments, char *buf_ptr, unsigned int buf_index)
{
unsigned long int int_in, int_ temp, i, div;
int_in = va_arg(arguments, unsigned long int);
int_temp = int_in;
div = 1;

while (int_temp > 9)
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
