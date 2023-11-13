#include "main.h"

/**
 * fetch_print_func - selects the appropriate function to use
 * for a particular operation
 * @id: arg identifier
 * @ind: arg identifier index
 *
 * Return: pointer to the correct function
 */

int (*fetch_print_func(const char *id, int ind))(va_list, char *, unsigned int)
{
	print_p prf[] = {
		{"c", printf_chr}, {"s", printf_str},
		{"i", printf_int}, {"d", printf_int},
		{"b", printf_bnr}, {"u", printf_unt},
		{"o", printf_oct}, {"x", printf_hex},
		{"X", printf_upx}, {"S", printf_usr},
		{"p", printf_add}, {"li", printli},
		{"ld", printli}, {"lu", printlu},
		{"lo", printlo}, {"lx", printlx},
		{"lX", printux}, {"hi", printshi},
		{"hd", printshi}, {"hu", printshu},
		{"ho", printsho}, {"hx", printshx},
		{"hX", prinshux}, {"#o", printnoct},
		{"#x", printnhex}, {"#X", printnupx},
		{"#i", printf_int}, {"#d", printf_int}
		{"#u", printf_unt}, {"+i", printpint},
		{"+d", printpint}, {"+u", printf_unt},
		{"+o", printf_oct}, {"+x", printf_hex},
		{"+X", printf_upx}, {" i", printsint},
		{" d", printsint}, {" u", printf_unt},
		{" o", printf_oct}, {" x", printf_hex},
		{" X", printf_upx}, {"R", printf_rot},
		{"r", printf_rev}, {"%", printf_prg},
		{"l", printf_prg}, {"h", printf_prg},
		{" +i", printpint}, {" +d", printpint},
		{"+ i", printpint}, {"+ d", printpint},
		{" %", printf_prg}, {NULL, NULL},
	};
	int a = 0, b = 0, index1;

	index1 = ind;
	while (prf[a].arg_type)
	{
		if (id[ind] == prf[a].arg_type[b])
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
	return (prf[a].p);
}
