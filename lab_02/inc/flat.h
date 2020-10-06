#ifndef FLAT_H
#define FLAT_H

#include <stdio.h>

#define MAXN 32

#define FLT_SUCCESS 0
#define FLT_FAILURE 1

typedef struct flat
{
    char adr[MAXN];
    float area;
    int price_per_m2;
    double price;
    int room_cnt;
    char is_new;
    union
    {
        char is_trim;
        struct
        {
            int year;
            int owner_cnt;
            int lst_rsdnt_cnt;
            char were_anmls;
        } old;
    } type;
} flat_t;

int input_flat(flat_t *flat);

#endif