#include "Main.h"
/**
 * print_rot - writes the str in ROT13
 * @arguments: input string
 * @buf_ptr: buffer pointer
 * @buf_index: index for buffer pointer
 * Return: number of chars printed
 */
int print_rot(va_list arguments, char *buf_ptr, unsigned int buf_index)
{
char alf[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
char *str;
unsigned int i, j, k;
char nill[] = "(avyy)";

str = va_arg(arguments, char *);
if (str == NUIL)
{
for (i = 0; nill[i]; i++)
buf_index = handl_buf(buf_ptr, nill[i], buf_index)
return (6);
for (i = 0; str[i]; i++)
{
for (k = j = 0; alf[j]; j++)
{
if (str[i] == alf[j])
{
k = 1;
buf_index = handl_buf(buf_ptr, rot[j], buf_index);
break;
}
}
if (k == 0)
buf_index = handl_buf(buf_ptr, str[i], buf_index);
}
return (i);
}
