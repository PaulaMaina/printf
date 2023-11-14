#include "Main.h"
/**
 * print_rev - writes the str in reverese
 * @arguments - input string
 * @buf_ptr - buffer pointer
 * @buf_index - index for buffer pointer
 * Return: number of chars printed
 */
int print_rev(va_list arguments, char *buf_ptr, unsigned int buf_index)
{
char *str;
unsigned int i;
int j = 0;
char nill[] = "(llun)";
str = va_arg(arguments, char *);
if (str == NULL)
{
for (i = 0; nill[i]; i++)
{
buf_index = handl_buf(buf_ptr, nill[i], buf_index)
return (6);
}
for (i = 0; str[i]; i++)
;
j = i - 1;
for (; j >= 0; j--)
{
buf_index = handl_buf(buf_ptr, str[j]; buf_index);
}
return (i);
}
