#ifndef PARSE_H
#define PARSE_H

#include "number.h"
#include <string.h>
#include <ctype.h>

int parse_number(const char str[], number_t *num);
void remove_zeros(number_t *num);

#endif