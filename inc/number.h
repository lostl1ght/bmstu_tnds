#ifndef NUMBER_H
#define NUMBER_H

#include <stdio.h>

#define MAX_MANTISSA 5
#define MAX_EXPONENT 2

typedef struct number
{
    int sign_m;
    int mantissa[MAX_MANTISSA * 2];
    size_t len_m;
    int sign_e;
    int exponent;
} number_t;

#endif