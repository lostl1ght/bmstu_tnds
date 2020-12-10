#ifndef FREE_ADR_H
#define FREE_ADR_H

#include <stdio.h>

#define ARRSIZE 256

typedef struct adr
{
    size_t adr;
    size_t cnt;
} adr_t;

typedef struct adrarr
{
    adr_t arr[ARRSIZE];
    size_t nmemb;
} adrarr_t;

extern adrarr_t arr;

int add_to_arr(size_t adr);
adr_t *find_in_arr(size_t adr);
void empty_adr_arr(void);
void output_arr(void);
void empty_arr(void);

#endif