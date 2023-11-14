#include "main.h"

/**
 * print_accept - detemines if characters are printable
 * @ch: char to be evaluated
 *
 * Return: 1 on success, else 0
 */

int print_accept(char ch)
{
	if (ch >= 32 && ch < 127)
		return (1);

	return (0);
}

/**
 * append_hex - appends ascii code
 * @buf: buffer array
 * @index: starting potin
 * @code: ascii code
 *
 * Return: 3
 */

int append_hex(char code, char buf[], int index)
{
	char to_map[] = "0123456789ABCDEF";

	if (code < 0)
		code *= -1;

	buf[index++] = '\\';
	buf[index++] = 'x';

	buf[index++] = to_map[code / 16];
	buf[index] = to_map[code % 16];

	return (3);
}

/**
 * digit - confirms a char is a digit
 * @ch: char being checked
 *
 * Return: 1 on success, else 0
 */

int digit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);

	return (0);
}

/**
 * conv_size_num - casts a num to size
 * @n: number being casted
 * @size: detemins the cast type
 *
 * Return: casted number
 */

long int conv_size_num(long int n, int size)
{
	if (size == I_LONG)
		return (n);
	else if (size == I_SHORT)
		return ((short)n);

	return ((int)n);
}

/**
 * conv_size_unsign - casts a num to size
 * @n: number being casted
 * @size: determined cast type
 *
 * Return: casted number
 */

long int conv_size_unsign(unsigned long int n, int size)
{
	if (size == I_LONG)
		return (n);
	else if (size == I_SHORT)
		return ((unsigned short)n);

	return ((unsigned int)n);
}
