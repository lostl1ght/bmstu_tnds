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
    printf("%lf\n", node->num);
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

stacknode_t *push_list_stack(stacknode_t *top, const double num)
{
    stacknode_t *node;
    if (!(node = create_stack_node(num)))
        return NULL;
    // Вывод адреса
    node->next = top;
    return node;
}

int pop_list_stack(stacknode_t **top, double *num)
{
    if (*top)
    {
        stacknode_t *new_top = (*top)->next;
        *num = (*top)->num;
        // Запись адреса
        delete_stack_node(*top);
        *top = new_top;
        return 0;
    }
    else
        return 1;
}

stacknode_t *empty_list_stack(stacknode_t *top)
{
    delete_list_stack(top);
    return NULL;
}
