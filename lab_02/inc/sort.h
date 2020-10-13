#ifndef SORT_H
#define SORT_H

#include "flat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(flat_t *arr, int l, int m, int r);
void merge_sort(flat_t *arr, int l, int r);
int merge_sort_no_keys(FILE *f_in, FILE *f_out);
int insert_sort_no_keys(FILE *f_in, FILE *f_out);
int merge_sort_with_keys(FILE *f_in, FILE *f_out);
int insert_sort_with_keys(FILE *f_in, FILE *f_out);
void merge_keys(key_t *arr, int l, int m, int r);
void merge_sort_keys(key_t *arr, int l, int r);
void get_key_array(flat_t *flats, key_t *keys, int count);

#endif