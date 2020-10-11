#ifndef FLAT_H
#define FLAT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXN 32

#define FLT_SUCCESS 0
#define FLT_FAILURE 1

typedef struct old
{
    int year;
    int owner_cnt;
    int lst_rsdnt_cnt;
    bool were_anmls;
} old_t;

typedef union type
{
    bool is_trim;
    old_t old; 
} type_t;

typedef struct flat
{
    char adr[MAXN];
    int area;
    int price_per_m2;
    long price;
    int room_cnt;
    bool is_new;
    type_t type;
} flat_t;

int get_from_stream(flat_t *flat);
void readable_output(flat_t *flat);
int input_flats_to_file(FILE *f);
void simple_output(FILE *f, flat_t *flat);
int get_flat_array(flat_t *flats, int count);
void write_in_file(FILE *f, flat_t *flats, int count);

#endif