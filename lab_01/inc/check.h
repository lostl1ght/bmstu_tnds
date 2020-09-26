#ifndef CHECK_H
#define CHECK_H

#include <string.h>

int check_str(char str[]);
int check_char(char *p);
int check_e(char *p, char **e_pointer);
size_t count_char(char c, char *start, char *end);
size_t count_num(char *start, char *end);
int check_symb(char *start, char *end, size_t dot_count);
int check_mantissa(char *str, char *end);
int check_exponent(char *e_pointer);

#endif