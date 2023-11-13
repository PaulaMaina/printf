#include "main.h"

/**
 * eval_print_func - returns the number of identifiers
 * @arg_id: identifier for arguments
 * @ind: index for the arg. identifier
 *
 * Return: number of args
 */

int eval_print_func(const char *arg_id, int ind)
{
	print_p prf[] = {
		{"c", printf_chr}, {"s", printf_str}, {"i", printf_int},
		{"d", printf_int}, {"b", printf_bnr}, {"u", printf_unt},
		{"o", printf_oct}, {"x", printf_hex}, {"X", printf_upx},
		{"S", printf_usr}, {"p", printf_add}, {"li", printlngint},
		{"ld", printli}, {"lu", printlu}, {"lo", printlo},
		{"lx", printlx}, {"lX", printux}, {"hi", printshi},
		{"hd", printshi}, {"hu", printshu}, {"ho", printsho},
		{"hx", printshx}, {"hX", printshux}, {"#o", printnoct},
		{"#x", printnhex}, {"X", printnupx}, {"#i", printnint},
		{"#d", printf_int}, {"#u", printf_hex}, {"+i", printpint},
		{"+d", printpint}, {"+u", printf_unt}, {"+o", printf_oct},
		{"+x", printf_hex}, {"+X", printf_upx}, {" i", printsint},
		{" d", printsint}, {" u", printf_unt}, {" o", printf_oct},
		{" x", printf_hex}, {" X", printf_upx}, {"R", printf_rot},
		{"r", printf_rev}, {"%", printf_prg}, {"l", printf_prg},
		{"h", printf_prg}, {" +i", printpint}, {" +d", printpint},
		{"+ i", printpint}, {"+ d", printpint}, {" %", printf_prg},
		{NULL, NULL},
	};
	int a = 0, int b = 0, index1;

	index1 = ind;
	while (prf[a].arg_type)
	{
		if (arg_id[ind] == prf[a].arg_type[b])
		{
			if (prf[a].arg_type[b + 1] != '\0')
				ind++, b++;
			else
				break;
		}
		else
		{
			b = 0;
			a++;
			ind = index1;
		}
	}
	return (b);
}
