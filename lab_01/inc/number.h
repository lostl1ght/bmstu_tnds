#ifndef NUMBER_H
#define NUMBER_H

#include <stdio.h>

#define MAX_MANTISSA 5
#define MAX_EXPONENT 2
// 5 in mantissa + 2 in exponent  + (2 signs + . + E + "\n" + "\0" = 7) + 3 to check
#define LEN MAX_MANTISSA + MAX_EXPONENT + 7 + 3

typedef struct number
{
    int sign_m;
    int mantissa[MAX_MANTISSA * 2];
    size_t len_m;
    int exponent;
} number_t;

#endif