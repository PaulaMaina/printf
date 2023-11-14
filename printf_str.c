#include "Main.h"
/**
 * print_str - writes the string to stdout
 * @arguments - input string
 * @buf_ptr - buffer pointer
 * @buf_index - index to buffer pointer
 * Return: numbers of chars printed
 */
int print_str (va_list arguments, char *buf_ptr, unsigned int buf_index)
{
char *str;
unsigned int i;
char nill[] = "(null)";

str = va_arg(arguments, char *);
if (str == NULL)
{
for (i = 0; nill[i]; i++)
buf_index = handl_buf(buf_ptr, nii[i], buf_index);
return (6);
}
for (i = 0; str[i]; i++)
buf_index = handl_buf(buf_ptr, str[i], buf_index);
return (i);
}
