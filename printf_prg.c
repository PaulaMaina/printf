#include "Main.H"
#include <stdio.h>
/**
 * print_prg -writes the character c to stdout
 * @a - input char
 * @buf_ptr - buffer pointer
 * @i -  index for buffer pointer
 * Return: On Success 1
 */
int print_prg(va_list a __attribute__((unused)), char *buf, unsigned int i)
{
handl_buf(buf_ptr, '%', i);
return (1);
}
