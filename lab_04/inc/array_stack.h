#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include "tick.h"

typedef struct arrstack
{
    double *arr;
    double *top1;
    double *end;
    double *top2;
} arrstack_t;

arrstack_t *create_arrstack(const size_t size, uint64_t *ticks);
void delete_arrstack(arrstack_t *stack);
void output_arrstack(arrstack_t *stack);

int push_1st_arrstack(arrstack_t *stack, const double num, uint64_t *ticks);
int pop_1st_arrstack(arrstack_t *stack, double *const num, uint64_t *ticks);
void empty_1st_arrstack(arrstack_t *stack, uint64_t *ticks);
int push_2nd_arrstack(arrstack_t *stack, const double num, uint64_t *ticks);
int pop_2nd_arrstack(arrstack_t *stack, double *const num, uint64_t *ticks);
void empty_2nd_arrstack(arrstack_t *stack, uint64_t *ticks);

#endif
