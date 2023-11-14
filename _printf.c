#include "main.h"

void print_buf(char buf[], int *buf_index);

/**
 * _printf - produces output based on a format
 * @format: intput
 *
 * Return: number of printed chars
 */

int _printf(const char *format, ...)
{
	int a, char_print = 0, printed_ch = 0;
	int flag, wid, prec, size, buf_index = 0;
	va_list list;
	char buf[BUF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			buf[buf_index++] = format[a];
			if (buf_index == BUF_SIZE)
				print_buf(buf, &buf_index);
			printed_ch++;
		}
		else
		{
			print_buf(buf, &buf_index);
			flag = get_flag(format, &a);
			wid = get_wid(format, &a, list);
			prec = get_prec(format, &a, list);
			size = get_size(format, &a);
			++a;
			char_print = print_handler(format, &a, list, buf,
					flag, wid, prec, size);
			if (char_print == -1)
				return (-1);
			printed_ch += char_print;
		}
	}
	print_buf(buf, &buf_index);
	va_end(list);

	return (printed_ch);
}

/**
 * print_buf - prints buffer contents
 * @buf: buffer array
 * @buf_index: buffer index
 */

void print_buf(char buf[], int *buf_index)
{
	if (*buf_index > 0)
		write(1, &buf[0], *buf_index);

	*buf_index = 0;
}
