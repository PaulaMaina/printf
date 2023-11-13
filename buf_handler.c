#include "main.h"

/**
 * buf_handler - concatenates buffer characters
 * @buff: pointer to the buffer
 * @s: character
 * @buf_index: buffer pointer index
 *
 * Return: buf_index
 *
 */

unsigned int buf_handler(char *buff, char s, unsigned int buf_index)
{
	if (buf_index == 1024)
	{
		print_buff(buff, buf_index);
		buf_index = 0;
	}
	buff[buf_index] = s;
	buf_index++;

	return (buf_index);
}
