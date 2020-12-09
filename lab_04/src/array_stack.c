#include "array_stack.h"

arrstack_t *create_arrstack(const size_t size, uint64_t *ticks)
{
    arrstack_t *stack;
    uint64_t start, end;
    start = tick();
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
    end = tick();
    *ticks = end - start;
    return stack;
}

void delete_arrstack(arrstack_t *stack)
{
    free(stack->arr);
    free(stack);
}

void output_arrstack(arrstack_t *stack)
{
    double *top1 = stack->top1;
    double *top2 = stack->top2;
    printf("Array size: %zu\n", stack->end - stack->arr);
    puts("First array stack:");
    while (stack->arr < top1)
    {
        top1--;
        printf("%lf\n", *top1);
    }
    puts("Second array stack:");
    while (stack->end > top2)
    {
        printf("%lf\n", *top2);
        top2++;
    }
}

int push_1st_arrstack(arrstack_t *stack, const double num, uint64_t *ticks)
{
    uint64_t start, end;
    if (stack->top1 == stack->top2)
        return 1;
    start = tick();
    *stack->top1 = num;
    stack->top1++;
    end = tick();
    *ticks = end - start;
    return 0;
}

int pop_1st_arrstack(arrstack_t *stack, double *const num, uint64_t *ticks)
{
    uint64_t start, end;
    if (stack->top1 == stack->arr)
        return 1;
    start = tick();
    stack->top1--;
    *num = *stack->top1;
    end = tick();
    *ticks = end - start;
    return 0;
}

void empty_1st_arrstack(arrstack_t *stack, uint64_t *ticks)
{
    uint64_t start, end;
    start = tick();
    stack->top1 = stack->arr;
    end = tick();
    *ticks = end - start;
}

int push_2nd_arrstack(arrstack_t *stack, const double num, uint64_t *ticks)
{
    uint64_t start, end;
    if (stack->top1 == stack->top2)
        return 1;
    start = tick();
    stack->top2--;
    *stack->top2 = num;
    end = tick();
    *ticks = end - start;
    return 0;
}

int pop_2nd_arrstack(arrstack_t *stack, double *const num, uint64_t *ticks)
{
    uint64_t start, end;
    if (stack->top2 == stack->end)
        return 1;
    start = tick();
    *num = *stack->top2;
    stack->top2++;
    end = tick();
    *ticks = end - start;
    return 0;
}

void empty_2nd_arrstack(arrstack_t *stack, uint64_t *ticks)
{
    uint64_t start, end;
    start = tick();
    stack->top2 = stack->end;
    end = tick();
    *ticks = end - start;
}
