#include "array_stack.h"

arrstack_t *create_arrstack(const size_t size)
{
    arrstack_t *stack;
    if (!(stack = malloc(sizeof *stack)))
        return NULL;
    if (!(stack->arr = malloc(size * sizeof *stack->arr)))
    {
        free(stack);
        return NULL;
    }
    stack->end = stack->arr + size;
    stack->cur1 = stack->arr;
    stack->cur2 = stack->end;
    return stack;
}

void delete_arrstack(arrstack_t *stack)
{
    free(stack->arr);
    free(stack);
}

void output_arrstack(arrstack_t stack)
{
    puts("First array stack:");
    while (stack.arr <= stack.cur1)
    {
        printf("%lf\n", stack.cur1);
        stack.cur1--;
    }
    puts("Second stack:");
    while (stack.end > stack.cur2)
    {
        printf("%lf\n", stack.cur2);
        stack.cur2++;
    }
}

int add_1st_stack(arrstack_t *stack, double num);
void pop_1st_stack(arrstack_t *stack);
void empty_1st_stack(arrstack_t *stack);
int add_2nd_stack(arrstack_t *stack, double num);
void pop_2st_stack(arrstack_t *stack);
void empty_2nd_stack(arrstack_t *stack);
