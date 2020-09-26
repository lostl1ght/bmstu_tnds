#ifndef CHECK_H
#define CHECK_H

#include <string.h>

int check_str(char str[]);
int check_char(char *p);
int check_e(char *p, char **e_pointer);
int check_mantissa(char *str, char *e_pointer);
int check_exponent(char *e_pointer);
int check_exp_len(char *e_pointer);
int check_len_exp_num(char *p);

#endif