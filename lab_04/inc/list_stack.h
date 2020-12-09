#ifndef LIST_STACK_H
#define LIST_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include "tick.h"

typedef struct stacknode stacknode_t;

struct stacknode
{
    double num;
    stacknode_t *next;
};

stacknode_t *create_stack_node(const double num);
void delete_stack_node(stacknode_t *node);
void output_stack_node(const stacknode_t *node);

void delete_list_stack(stacknode_t *top);
void output_list_stack(const stacknode_t *top);

stacknode_t *push_list_stack(stacknode_t *top, const double num, uint64_t *ticks);
int pop_list_stack(stacknode_t **top, double *num, uint64_t *ticks);
stacknode_t *empty_list_stack(stacknode_t *top, uint64_t *ticks);

#endif
