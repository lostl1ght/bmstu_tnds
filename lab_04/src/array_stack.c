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
    stack->top1 = stack->arr;
    stack->top2 = stack->end;
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
    while (stack.arr <= stack.top1)
    {
        printf("%lf\n", stack.top1);
        stack.top1--;
    }
    puts("Second stack:");
    while (stack.end > stack.top2)
    {
        printf("%lf\n", stack.top2);
        stack.top2++;
    }
}

int add_1st_arrstack(arrstack_t *stack, double num)
{
    if (stack->top1 + 1 == stack->top2)
        return 1;
    *stack->top1 = num;
    stack->top1++;
    return 0;
}

int pop_1st_arrstack(arrstack_t *stack, double *num)
{
    if (stack->top1 == stack->arr)
    stack->top1--;
    *num = *stack->top1;
    return 0;
}

void empty_1st_arrstack(arrstack_t *stack)
{
    stack->top1 = stack->arr;
}

int add_2nd_arrstack(arrstack_t *stack, double num)
{
    if (stack->top1 + 1 == stack->top2)
        return 1;
    stack->top2--;
    *stack->top2 = num;
    return 0;
}

int pop_2st_arrstack(arrstack_t *stack, double *num)
{
    if (stack->top2 == stack->end)
        return 1;
    *num = *stack->top2;
    stack->top2++;
    return 0;
}

void empty_2nd_arrstack(arrstack_t *stack)
{
    stack->top2 = stack->end;
}
