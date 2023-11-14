#include "main.h"

/**
 * printf_char - prints a character
 * @args: input
 * @buf: buffer array
 * @flag: computes flags
 * @wid: width
 * @prec: specifies precision
 * @size: specifies size
 * Return: number of printed chars
 */

int printf_char(va_list args, char buf[],
		int flag, int wid, int prec, int size)
{
	char ch = va_arg(args, int);

	return (write_char(ch, buf, flag, wid, prec, size));
}

/**
 * printf_str - prints a string
 * @args: input
 * @buf: buffer array
 * @flag: computes flags
 * @wid: width
 * @prec: specifies precision
 * @size: specifies size
 * Return: number of printed chars
 */
int printf_str(va_list args, char buf[],
		int flag, int wid, int prec, int size)
{
	int len = 0, a;
	char *s = va_arg(args, char *);

	UNUSED(buf);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(prec);
	UNUSED(size);
	if (s == NULL)
	{
		s = "(null)";
		if (prec >= 6)
			s = "      ";
	}

	while (s[len] != '\0')
		len++;
	if (prec >= 0 && prec < len)
		len = prec;
	if (wid > len)
	{
		if (flag & P_MINUS)
		{
			write(1, &s[0], len);
			for (a = wid - len; a > 0; a--)
				write(1, " ", 1);
			return (wid);
		}
		else
		{
			for (a = wid - len; a > 0; a--)
				write(1, " ", 1);
			write(1, &s[0], len);
			return (wid);
		}
	}

	return (write(1, s, len));
}

/**
 * printf_perc - prints a %
 * @args: input
 * @buf: buffer array
 * @flag: computes flags
 * @wid: width
 * @prec: specifies precision
 * @size: specifies size
 * Return: number of printed chars
 */
int printf_perc(va_list args, char buf[],
		int flag, int wid, int prec, int size)
{
	UNUSED(args);
	UNUSED(buf);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(prec);
	UNUSED(size);

	return (write(1, "%%", 1));
}

/**
 * printf_str - prints a string
 * @args: input
 * @buf: buffer array
 * @flag: computes flags
 * @wid: width
 * @prec: specifies precision
 * @size: specifies size
 * Return: number of printed chars
 */
int printf_int(va_list args, char buf[],
		int flag, int wid, int prec, int size)
{
	int a = BUF_SIZE - 2;
	int neg = 0;
	long int num = va_arg(args, long int);
	unsigned long int n;

	num = conv_size_num(num, size);

	if (num == 0)
		buf[a--] = '0';
	buf[BUF_SIZE - 1] = '\0';
	n = (unsigned long int)num;

	if (num < 0)
	{
		n = (unsigned long int)((-1) * num);
		neg = 1;
	}

	while (n > 0)
	{
		buf[a--] = (n % 10) + '0';
		n /= 10;
	}
	a++;

	return (write_int(neg, a, buf, flag, wid, prec, size));
}

/**
 * printf_bin - prints a unsigned int
 * @args: input
 * @buf: buffer array
 * @flag: computes flags
 * @wid: width
 * @prec: specifies precision
 * @size: specifies size
 * Return: number of printed chars
 */
int printf_bin(va_list args, char buf[],
		int flag, int wid, int prec, int size)
{
	unsigned int p, q, a, total;
	unsigned int b[32];
	int tally;

	UNUSED(buf);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(prec);
	UNUSED(size);

	p = va_arg(args, unsigned int);
	q = 2147483648;
	b[0] = p / q;
	for (a = 1; a < 32; a++)
	{
		q /= 2;
		b[a] = (p / q) % 2;
	}
	for (a = 0, total = 0, tally = 0; a < 32; a++)
	{
		total += b[a];
		if (total || a == 32)
		{
			char c = '0' + b[a];

			write(1, &c, 1);
			tally++;
		}
	}
	return (tally);
}
