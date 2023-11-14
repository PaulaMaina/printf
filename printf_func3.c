#include "main.h"

/**
 * printf_unsign - prints an unsigned int
 * @args: input
 * @buf: buffer array
 * @flag: computes flags
 * @wid: width
 * @prec: specifies precision
 * @size: specifies size
 * Return: number of printed chars
 */
int printf_unsign(va_list args, char buf[],
		int flag, int wid, int prec, int size)
{
	int a = BUF_SIZE - 2;
	unsigned long int n = va_arg(args, unsigned long int);

	n = conv_size_unsign(n, size);

	if (n == 0)
		buf[a--] = '0';
	buf[BUF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buf[a--] = (n % 10) + '0';
		n /= 10;
	}

	a++;

	return (write_unsign(0, a, buf, flag, wid, prec, size));
}

/**
 * printf_oct - prints unsigned numbers as octal
 * @args: input
 * @buf: buffer array
 * @flag: computes flags
 * @wid: width
 * @prec: specifies precision
 * @size: specifies size
 * Return: number of printed chars
 */
int printf_oct(va_list args, char buf[],
		int flag, int wid, int prec, int size)
{
	int a = BUF_SIZE - 2;
	unsigned long int n = va_arg(args, unsigned long int);
	unsigned long int num = n;

	UNUSED(wid);

	n = conv_size_unsign(n, size);

	if (n == 0)
		buf[a--] = '0';

	buf[BUF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buf[a--] = (n % 8) + '0';
		n /= 8;
	}

	if (flag & P_HASH && num != 0)
		buf[a--] = '0';

	a++;

	return (write_unsign(0, a, buf, flag, wid, prec, size));
}

/**
 * printf_hex - prints unsigned nums in hex
 * @args: input
 * @buf: buffer array
 * @flag: computes flags
 * @wid: width
 * @prec: specifies precision
 * @size: specifies size
 * Return: number of printed chars
 */
int printf_hex(va_list args, char buf[],
		int flag, int wid, int prec, int size)
{
	return (printf_hexc(args, "0123456789abcdef", buf,
				flag, 'x', wid, prec, size));
}

/**
 * printf_upp - prints unsigned nums in uppercase hex
 * @args: input
 * @buf: buffer array
 * @flag: computes flags
 * @wid: width
 * @prec: specifies precision
 * @size: specifies size
 * Return: number of printed chars
 */
int printf_upp(va_list args, char buf[],
		int flag, int wid, int prec, int size)
{
	return (printf_hexc(args, "0123456789ABCDEF", buf,
				flag, 'X', wid, prec, size));
}

/**
 * printf_hex - prints unsigned nums in upper and lower hex
 * @args: input
 * @to_map: array to map the number to
 * @buf: buffer array
 * @flag: computes flags
 * @ch_flag: computes active flags
 * @wid: width
 * @prec: specifies precision
 * @size: specifies size
 * Return: number of printed chars
 */
int printf_hexc(va_list args, char to_map[], char buf[],
		int flag, char ch_flag, int wid, int prec, int size)
{
	int a = BUF_SIZE - 2;
	unsigned long int n = va_arg(args, unsigned long int);
	unsigned long int num = n;

	UNUSED(wid);

	n = conv_size_unsign(n, size);

	if (n ==  0)
		buf[a--] = '0';

	buf[BUF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buf[a--] = to_map[n % 16];
		n /= 16;
	}

	if (flag && P_HASH && num != 0)
	{
		buf[a--] = ch_flag;
		buf[a--] = '0';
	}

	a++;

	return (write_unsign(0, a, buf, flag, wid, prec, size));
}
