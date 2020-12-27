#ifndef LIST_UTILS_H
#define LIST_UTILS_H

#include <stdlib.h>
#include <string.h>

#include "macro.h"

typedef struct list
{
    char *value;
    struct list *next;
} list_t;

int linsert(list_t *arr, char *buffer);

int deepcmp(char *s, list_t l);

int list_occupation(list_t *arr, int size);

void free_list_arr(list_t *arr, int size);

#endif