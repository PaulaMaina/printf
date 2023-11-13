#include "main.h"

/**
 * printf_char - prints a character to stdout
 * @print_args: input
 * @buf_ptr: pointer to the buffer
 * @buf_index: buffer index
 *
 * Return: 1
 */

int printf_char(va_list print_args, char *buf_ptr, unsigned int buf_index)
{
	char letter;

	letter = va_arg(print_args, int);
	buf_handler(buf_ptr, letter, buf_index);

	return (1);
}
