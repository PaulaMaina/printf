#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * struct printfunc - struct for the printing functions
 * @arg_type: argument identifier
 * @p: pointer to the printing functions
 *
 */

typedef struct printfunc
{
	char *arg_type;
	int (*p)(va_list, char *, unsigned int);
} print_p;

int _printf(const char *format, ...);
int printf_prg(va_list __attribute__((unused)), char *, unsigned int);
int printf_char(va_list print_args, char *buf_ptr, unsigned int buf_index);
int printf_str(va_list print_args, char *buf_ptr, unsigned int buf_index);
int printf_int(va_list print_args, char *buf_ptr, unsigned int buf_index);
int printf_bnr(va_list print_args, char *buf_ptr, unsigned int buf_index);
int printf_unt(va_list print_args, char *buf_ptr, unsigned int buf_index);
int printf_oct(va_list print_args, char *buf_ptr, unsigned int buf_index);
int printf_hex(va_list print_args, char *buf_ptr, unsigned int buf_index);
int printf_upx(va_list print_args, char *buf_ptr, unsigned int buf_index);
int printf_usr(va_list print_args, char *buf_ptr, unsigned int buf_index);
int printf_add(va_list print_args, char *buf_ptr, unsigned int buf_index);
int printf_rev(va_list print_args, char *buf_ptr, unsigned int buf_index);
int printf_rot(va_list print_args, char *buf_ptr, unsigned int buf_index);
int printlngint(va_list print_args, char *buf_ptr, unsigned int buf_index);
int printlngunt(va_list print_args, char *buf_ptr, unsigned int buf_index);
int printlngoct(va_list print_args, char *buf_ptr, unsigned int buf_index);
int printlnghex(va_list print_args, char *buf_ptr, unsigned int buf_index);
int printlngupx(va_list print_args, char *buf_ptr, unsigned int buf_index);
int printshint(va_list print_args, char *buf_ptr, unsigned int buf_index);
int printshunt(va_list print_args, char *buf_ptr, unsigned int buf_index);
int printshoct(va_list print_args, char *buf_ptr, unsigned int buf_index);
int printshhex(va_list print_args, char *buf_ptr, unsigned int buf_index);
int printshupx(va_list print_args, char *buf_ptr, unsigned int buf_index);
int printpint(va_list print_args, char *buf_ptr, unsigned int buf_index);
int printnint(va_list print_args, char *buf_ptr, unsigned int buf_index);
int printnoct(va_list print_args, char *buf_ptr, unsigned int buf_index);
int printnhex(va_list print_args, char *buf_ptr, unsigned int buf_index);
int printnupx(va_list print_args, char *buf_ptr, unsigned int buf_index);
int printsint(va_list print_args, char *buf_ptr, unsigned int buf_index);
int (*fetch_print_func(const char *str, int index))(va_list char *, unsigned int);
int eval_print_func(const char *str, int ind);
unsigned int buf_handler(char *buff, char s, unsigned int buf_num);
int print_buff(char *buff, unsigned int buf_num);
char *print_bin_array(char *bin, long int n, int neg_int, int lim);
char *print_oct_array(char *br, char *oc);
char *print_lngoct_array(char *br, char *oc);
char *print_shoct_array(chaar *br, char *oc);
char *print_hex_array(char *br, char *hx, int upp, int lim);

#endif
