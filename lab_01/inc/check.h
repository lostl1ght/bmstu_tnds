#ifndef CHECK_H
#define CHECK_H

#include <string.h>

int check_str(const char str[]);
int check_char(const char *p);
size_t count_char(const char c, const char *start, const char *end);
size_t count_num(const char *start, const char *end);
int check_symb(const char *start, const char *end, const size_t dot_count);
int check_mantissa(const char *str, const char *end);
int check_exponent(const char *e_pointer);

#endif