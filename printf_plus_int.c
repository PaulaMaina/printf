#include "Main.H"
/**
 * prinpint - print interger with plus symbol
 * @arguments - input string
 * @buf_ptr- buffer pointer
 * @buf_index - index for buffer pointer
 * Return - number of chars printed
 */
int prinpint(va_list arguments, char *buf_ptr, unsigned int buf_index)
{
int int_input;
unsigned int int_in, int_temp, i, div;

int_input = va_arg(arguments, int);
if (int_input < 0)
{
int_in = int_input * -1;
buf_index = handl_buf(buf_ptr, '-', buf_index);
}
else
{
int_in = int_put;
buf_index = handl_buf(buf_ptr, '+', buf_index);
}
int_temp = int_in;
div = 1;
while (int_temp > 9)
{
div *= 10;
Int_temp /= 10;
}
for (i = 0; div > 0; div /= 10, i++)
{
buf_index = handl_buf(buf_ptr, ((int_in / div) % 10) + '0', buf_index);
}
return (i + 1);
}