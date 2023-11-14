#include "Main.h"
/**
 * print_usr: prints a value of a string
 * and value of non printed chars
 * @arguments: input string
 * @buf_ptr: pointer to buffer
 * @buf_index: index to buffer pointer
 * Return: number of chars to be printed
 */
int print_usr(va_list arguments, char *buf_ptr, unsigned int buf_index)
{
unsigned char *str;
char *hexadecimal, *binary;
unsigned int i, sum, op;

str va_arg(arguments, unsigned char *);
binary = malloc(sizeof(char) * (32 + 1));
hexadecimal = malloc(sizeof(char) * (8 + 1);
for (sum = i = 0; str[i]; i++)
{
if (str[i] < 32 || str[i] > 127)
{
buf_index = handl_buf(buf_ptr, '\\', buf_index);
buf_index = handl_buf(buf_ptr, 'x', buf_index);
op = str[i];
binary = fill_binary_array(binary, op, 0, 32);
hexadecimal = fill_hex_array(bianry, hexadecimal, 1, 8);
buf_index = handl_buf(buf_ptr, hexadecima[6], buf_index);
buf_index = handl_buf(buf_ptr, hexadecimal[7], buf_index);
sum += 3;
}
else
buf_index = handl_buf(buf_ptr, str[i], buf_index);
}
free(bianry);
free(hexadecimal);
return (i + sum);
}
