#include "list_stack.h"

stacknode_t *create_stack_node(const double num)
{
    stacknode_t *node = calloc(1, sizeof *node);
    if (node)
        node->num = num;
    return node;
}

void delete_stack_node(stacknode_t *node)
{
    free(node);
}

void output_stack_node(const stacknode_t *node)
{
    printf("Number: %lf, adress: %zu\n", node->num, (size_t)node);
}

void delete_list_stack(stacknode_t *top)
{
    stacknode_t *node;
    while (top)
    {
        node = top;
        top = top->next;
        delete_stack_node(node);
    }
}

void output_list_stack(const stacknode_t *top)
{
    while (top)
    {
        output_stack_node(top);
        top = top->next;
    }
}

stacknode_t *push_list_stack(stacknode_t *top, const double num, uint64_t *ticks)
{
    stacknode_t *node;
    uint64_t start, end;
    start = tick();
    if (!(node = create_stack_node(num)))
        return NULL;
    node->next = top;
    end = tick();
    *ticks = end - start;
    // Вывод адреса;
    return node;
}

int pop_list_stack(stacknode_t **top, double *num, uint64_t *ticks)
{
    if (*top)
    {
        // void *adr;
        uint64_t start, end;
        start = tick();
        stacknode_t *new_top = (*top)->next;
        *num = (*top)->num;
        // adr = *top;
        delete_stack_node(*top);
        *top = new_top;
        end = tick();
        *ticks = end - start;
        // Запись адреса
        return 0;
    }
    else
        return 1;
}

stacknode_t *empty_list_stack(stacknode_t *top, uint64_t *ticks)
{
    uint64_t start, end;
    start = tick();
    delete_list_stack(top);
    end = tick();
    *ticks = end - start;
    return NULL;
}
