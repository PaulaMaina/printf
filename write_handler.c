#include "main.h"

/**
 * write_char - prints string
 * @c: charcter types
 * @buf: buffer array
 * @flag: computes flag
 * @wid: width
 * @prec: precision
 * @size: size
 *
 * Return: number of printed characters
 */

int write_char(char c, char buf[], int flag, int wid, int prec, int size)
{
	int a = 0;
	char add = ' ';

	UNUSED(prec);
	UNUSED(size);

	if (flag & P_ZERO)
		add = '0';

	buf[a++] = c;
	buf[a] = '\0';

	if (wid > 1)
	{
		buf[BUF_SIZE - 1] = '\0';
		for (a = 0; a < wid - 1; a++)
			buf[BUF_SIZE - a - 2] = add;

		if (flag & P_MINUS)
			return (write(1, &buf[0], 1) +
				       write(1, &buf[BUF_SIZE - a - 1], wid - 1));
		else
			return (write(1, &buf[BUF_SIZE - a - 1], wid - 1)
					+ write(1, &buf[0], 1));
	}
	return (write(1, &buf[0], 1));
}

/**
 * write_int - prints string
 * @neg: args
 * @index: types
 * @buf: buffer array
 * @flag: compute flags
 * @wid: width
 * @prec: precision
 * @size: size
 *
 * Return: number of prtined characters
 */
int write_int(int neg, int index, char buf[],
		int flag, int wid, int prec, int size)
{
	int len = BUF_SIZE - index - 1;
	char add = ' ', ch_ext = 0;

	UNUSED(size);

	if ((flag && P_ZERO) && !(flag & P_MINUS))
		add = '0';
	if (neg)
		ch_ext = '-';
	else if (flag & P_PLUS)
		ch_ext = '+';
	else if (flag & P_SPACE)
		ch_ext = ' ';

	return (write_nums(index, buf, flag, wid, prec,
				len, add, ch_ext));
}
/**
 * write_nums - prints numbers using a buffer
 * @index: starting point
 * @buf: buffer array
 * @flag: compute flags
 * @wid: width
 * @prec: precision
 * @len: length of number
 * @add: padding character
 * @ch_ext: extra character
 *
 * Return: number of prtined characters
 */

int write_nums(int index, char buf[],
		int flag, int wid, int prec, int len, char add, char ch_ext)
{
	int a, start_add = 1;

	if (prec == 0 && index == BUF_SIZE - 2 && buf[index] == '0'
			&& wid == 0)
		return (0);
	if (prec == 0 && index == BUF_SIZE - 2 && buf[index] == '0')
		buf[index] = add = ' ';
	if (prec > 0 && prec < len)
		add = ' ';
	while (prec > len)
		buf[--index] = '0', len++;
	if (ch_ext != 0)
		len++;
	if (wid > len)
	{
		for (a = 1; a < wid - len + 1; a++)
			buf[a] = add;
		buf[a] = '\0';
		if (flag & P_MINUS && add == ' ')
		{
			if (ch_ext)
				buf[--index] = ch_ext;
			return (write(1, &buf[index], len) +
					write(1, &buf[1], a - 1));
		}
		else if (!(flag & P_MINUS) && add == ' ')
		{
			if (ch_ext)
				buf[--index] = ch_ext;
			return (write(1, &buf[1], a - 1) +
					write(1, &buf[index], len));
		}
		else if (!(flag & P_MINUS) && add == ' ')
		{
			if (ch_ext)
				buf[--start_add] = ch_ext;
		return (write(1, &buf[start_add], a - start_add) +
				write(1, &buf[index], len - (1 - start_add)));
		}
	}
	if (ch_ext)
		buf[--index] = ch_ext;
	return (write(1, &buf[index], len));
}

/**
 * write_ptr - prints numbers using a buffer
 * @index: starting point
 * @buf: buffer array
 * @flag: compute flags
 * @wid: width
 * @len: length of number
 * @add: padding character
 * @ch_ext: extra character
 * @start_add: starting point for padding
 *
 * Return: number of printed characters
 */

int write_ptr(char buf[], int index, int len,
		int wid, int flag, char add, char ch_ext, int start_add)
{
	int a;

	if (wid > len)
	{
		for (a = 3; a < wid - len + 3; a++)
			buf[a] = add;
		buf[a] = '\0';
		if (flag & P_MINUS && add == ' ')
		{
			buf[--index] = 'x';
			buf[--index] = '0';
			if (ch_ext)
				buf[--index] = ch_ext;
			return (write(1, &buf[index], len) +
					write(1, &buf[3], a - 3));
		}
		else if (!(flag & P_MINUS) && add == ' ')
		{
			buf[--index] = 'x';
			buf[--index] = '0';
			if (ch_ext)
				buf[--index] = ch_ext;
			return (write(1, &buf[3], a - 3) +
					write(1, &buf[index], len));
		}
		else if (!(flag & P_MINUS) && add == '0')
		{
			if (ch_ext)
				buf[--start_add] = ch_ext;
			buf[1] = '0';
			buf[2] = 'x';
			return (write(1, &buf[start_add], a - start_add) +
					write(1, &buf[index], len - (1 - start_add) - 2));
		}
	}
	buf[--index] = 'x';
	buf[--index] = '0';
	if (ch_ext)
		buf[--index] = ch_ext;
	return (write(1, &buf[index], BUF_SIZE - index - 1));
}

/**
 * write_unsign - prints an unsigned num
 * @neg: args
 * @index: types
 * @buf: buffer array
 * @flag: compute flags
 * @wid: width
 * @prec: precision
 * @size: size
 *
 * Return: number of prtined characters
 */

int write_unsign(int neg, int index, char buf[],
		int flag, int wid, int prec, int size)
{
	int len = BUF_SIZE - index - 1, a = 0;
	char add = ' ';

	UNUSED(neg);
	UNUSED(size);

	if (prec == 0 && index == BUF_SIZE - 2 && buf[index] == '0')
		return (0);
	if (prec > 0 && prec < len)
		add = ' ';

	while (prec > len)
	{
		buf[--index] = '0';
		len++;
	}

	if ((flag && P_ZERO) && !(flag & P_MINUS))
		add = '0';

	if (wid > len)
	{
		for (a = 0; a < wid - len; a++)
			buf[a] = add;

		buf[a] = '\0';

		if (flag & P_MINUS)
		{
			return (write(1, &buf[index], len) +
					write(1, &buf[0], a));
		}
		else
		{
			return (write(1, &buf[0], a) +
					write(1, &buf[index], len));
		}
	}

	return (write(1, &buf[index], len));
}
