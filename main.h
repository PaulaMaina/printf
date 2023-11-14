#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUF_SIZE 1024

#define P_MINUS 1
#define P_PLUS 2
#define P_ZERO 4
#define P_HASH 8
#define P_SPACE 16

#define I_SHORT 1
#define I_LONG 2

/**
 * struct print - struct print
 * @fmrt: format
 * @func: associated function
 */

typedef struct print
{
	char fmrt;
	int (*func)(va_list, char[], int, int, int, int);
} print_t;

int _printf(const char *format, ...);
int print_handler(const char *fmrt, int *p,
va_list list, char buf[], int flag, int wid, int prec, int size);

int printf_char(va_list args, char buf[],
		int flag, int wid, int prec, int size);
int printf_str(va_list args, char buf[],
		int flag, int wid, int prec, int size);
int printf_perc(va_list args, char buf[],
		int flag, int wid, int prec, int size);
int printf_int(va_list args, char buf[],
		int flag, int wid, int prec, int size);
int printf_bin(va_list args, char buf[],
		int flag, int wid, int prec, int size);
int printf_unsign(va_list args, char buf[],
		int flag, int wid, int prec, int size);
int printf_oct(va_list args, char buf[],
		int flag, int wid, int prec, int size);
int printf_hex(va_list args, char buf[],
		int flag, int wid, int prec, int size);
int printf_upp(va_list args, char buf[],
		int flag, int wid, int prec, int size);
int printf_hexc(va_list args, char to_map[],
	       char buf[], int flag, char ch_flag, int wid, int prec, int size);
int printf_nonprint(va_list args, char buf[],
		int flag, int wid, int prec, int size);
int printf_ptr(va_list args, char buf[],
		int flag, int wid, int prec, int size);
int get_flag(const char *format, int *p);
int get_wid(const char *format, int *p, va_list list);
int get_prec(const char *format, int *p, va_list list);
int get_size(const char *format,  int *p);
int printf_rev(va_list args, char buf[],
		int flag, int wid, int prec, int size);
int printf_rot13(va_list args, char buf[],
		int flag, int wid, int prec, int size);
int write_char(char c, char buf[],
		int flag, int wid, int prec, int size);
int write_int(int neg, int index,
		char buf[], int flag, int wid, int prec, int size);
int write_nums(int n, char buf[],
		int flag, int wid, int prec, int len, char add, char ch_ext);
int write_ptr(char buf[], int n,
		int len, int wid, int flag, char add, char ch_ext, int start_add);
int write_unsign(int neg, int n, char buf[],
		int flag, int wid, int prec, int size);
int print_accept(char);
int append_hex(char, char[], int);
int digit(char);

long int conv_size_num(long int n, int size);
long int conv_size_unsign(unsigned long int n, int size);

#endif
