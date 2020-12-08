#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct arrstack
{
    double *arr;
    double *top1;
    double *end;
    double *top2;
} arrstack_t;

arrstack_t *create_arrstack(const size_t size);
void delete_arrstack(arrstack_t *stack);
void output_arrstack(arrstack_t stack);

int add_1st_arrstack(arrstack_t *stack, double num);
int pop_1st_arrstack(arrstack_t *stack, double *num);
void empty_1st_arrstack(arrstack_t *stack);
int add_2nd_arrstack(arrstack_t *stack, double num);
int pop_2st_arrstack(arrstack_t *stack, double *num);
void empty_2nd_arrstack(arrstack_t *stack);

#endif
