#include "main.h"

/**
 * printf_ptr - prints the value of pointer variable
 * @args: input
 * @buf: buffer array
 * @flag: computes flags
 * @wid: width
 * @prec: specifies precision
 * @size: specifies size
 * Return: number of printed chars
 */
int printf_ptr(va_list args, char buf[],
		int flag, int wid, int prec, int size)
{
	char ch_ext = 0, add = ' ';
	int index = BUF_SIZE - 2, len = 2, add_start = 1;
	unsigned long num_addr;
	char to_map[] = "0123456789abcdef";
	void *addr = va_arg(args, void *);

	UNUSED(wid);
	UNUSED(size);

	if (addr == NULL)
		return (write(1, "(nil)", 5));

	buf[BUF_SIZE - 1] = '\0';
	UNUSED(prec);

	num_addr = (unsigned long)addr;

	while (num_addr > 0)
	{
		buf[index--] = to_map[num_addr % 16];
		num_addr /= 16;
		len++;
	}

	if ((flag & P_ZERO) && !(flag & P_MINUS))
		add = '0';
	if (flag & P_PLUS)
		ch_ext = '+', len++;
	else if (flag & P_SPACE)
		ch_ext = ' ', len++;

	index++;

	return (write_ptr(buf, index, len,
				wid, flag, add, ch_ext, add_start));
}

/**
 * printf_nonprint - prints ascii codes in hex for characters that are not
 * printable
 * @args: input
 * @buf: buffer array
 * @flag: computes flags
 * @wid: width
 * @prec: specifies precision
 * @size: specifies size
 * Return: number of printed chars
 */
int printf_nonprint(va_list args, char buf[],
		int flag, int wid, int prec, int size)
{
	int a = 0, off = 0;
	char *s = va_arg(args, char *);

	UNUSED(flag);
	UNUSED(wid);
	UNUSED(prec);
	UNUSED(size);

	if (s == NULL)
		return (write(1, "(null)", 6));

	while (s[a] != '\0')
	{
		if (print_accept(s[a]))
			buf[a + off] = s[a];
		else
			off += append_hex(s[a], buf, a + off);
		a++;
	}
	buf[a + off] = '\0';

	return (write(1, buf, a + off));
}

/**
 * printf_rev - prints a string in reverse
 * @args: input
 * @buf: buffer array
 * @flag: computes flags
 * @wid: width
 * @prec: specifies precision
 * @size: specifies size
 * Return: number of printed chars
 */
int printf_rev(va_list args, char buf[],
		int flag, int wid, int prec, int size)
{
	char *s;
	int a, tally;

	UNUSED(buf);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(size);

	s = va_arg(args, char *);

	if (s == NULL)
	{
		UNUSED(prec);

		s = ")Null(";
	}

	for (a = 0; s[a]; a++)
		;
	for (a = a - 1; a >= 0; a--)
	{
		char ch = s[a];

		write(1, &ch, 1);
		tally++;
	}
	return (tally);
}

/**
 * printf_rot13 - prints a rot13 string
 * @args: input
 * @buf: buffer array
 * @flag: computes flags
 * @wid: width
 * @prec: specifies precision
 * @size: specifies size
 * Return: number of printed chars
 */
int printf_rot13(va_list args, char buf[],
		int flag, int wid, int prec, int size)
{
	char p;
	char *s;
	unsigned int a, b;
	int tally = 0;
	char i[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char o[] = "NOPQRSTUVWXYZABCEDFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	s = va_arg(args, char *);

	UNUSED(buf);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(prec);
	UNUSED(size);

	if (s == NULL)
		s = "(AHYY)";
	for (a = 0; s[a]; a++)
	{
		for (b = 0; i[b]; b++)
		{
			if (i[b] == s[a])
			{
				p = o[b];

				write(1, &p, 1);
				tally++;
				break;
			}
		}
		if (!i[b])
		{
			p = s[a];

			write(1, &p, 1);
			tally++;
		}
	}
	return (tally);
}
