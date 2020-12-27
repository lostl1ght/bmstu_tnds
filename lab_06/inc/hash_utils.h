#ifndef HASH_UTILS_H
#define HASH_UTILS_H

#include <stdio.h>
#include <math.h>

#include "macro.h"

#include "list_utils.h"

int is_prime(unsigned int num);

unsigned int next_prime(int n);

int file_len(FILE *f);

int fbytes(FILE *f);

int safe_hash(char *s, int n);

int unsafe_hash(char *s, int n);

int build_hash_table(list_t **arr, int size, FILE *f, int (*hash)(char *, int));

void print_hash_table(list_t *arr, int size);

#endif