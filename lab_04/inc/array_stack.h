#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct arrstack
{
    double *arr;
    double *cur1;
    double *end;
    double *cur2;
} arrstack_t;

arrstack_t *create_arrstack(const size_t size);
void delete_arrstack(arrstack_t *stack);
void output_arrstack(arrstack_t stack);

int add_1st_stack(arrstack_t *stack, double num);
void pop_1st_stack(arrstack_t *stack);
void empty_1st_stack(arrstack_t *stack);
int add_2nd_stack(arrstack_t *stack, double num);
void pop_2st_stack(arrstack_t *stack);
void empty_2nd_stack(arrstack_t *stack);

#endif
