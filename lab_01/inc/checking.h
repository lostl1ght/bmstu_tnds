#ifndef CHECK_H
#define CHECK_H

#include <string.h>
#include "number.h"

#define CHECK_SUCCESS 0
#define CHECK_FAILURE 1
#define CHECK_WRONG_CHARACTERS 2
#define CHECK_MANT_ERROR 3
#define CHECK_EXP_ERROR 4

int check_str(const char str[]);
int check_char(const char *p);
size_t count_char(const char c, const char *start, const char *end);
size_t count_num(const char *start, const char *end);
int check_symb(const char *start, const char *end, const size_t dot_count);
int check_mantissa(const char *str, const char *end);
int check_exponent(const char *e_ptr);

#endif