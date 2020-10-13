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

#endif