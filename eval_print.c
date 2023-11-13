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
		{"ld", printlng
	};
}
