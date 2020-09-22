#ifndef IO_H
#define IO_H

#include "number.h"

#define MAX_SYMBOLS 38

int input_str(char str[]);
int parse_number(char str[], number_t *num);

#endif