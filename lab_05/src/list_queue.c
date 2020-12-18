#include "list_queue.h"

qnode_t *create_qnode(const task_t task)
{
    qnode_t *node;
    if (!(node = calloc(1, sizeof *node)))
        return NULL;
    node->task = task;
    return node;
}

void delete_qnode(qnode_t *const node)
{
    free(node);
}

listq_t *create_list_queue(const size_t cap)
{
    listq_t *queue;
    if (!(queue = calloc(1, sizeof *queue)))
        return NULL;
    queue->cap = cap;
    return queue;
}

void delete_list_queue(listq_t *queue)
{
    if (queue)
    {
        qnode_t *node;
        while (queue->front)
        {
            node = queue->front;
            queue->front = queue->front->next;
            delete_qnode(node);
        }
        free(queue);
    }
}

int is_list_full(listq_t *const queue)
{
    return queue->size == queue->cap;
}

int is_list_empty(listq_t *const queue)
{
    return queue->front == NULL;
}

int put_list_queue(listq_t *const queue, const task_t task)
{
    qnode_t *node;
    if (is_list_full(queue))
        return Q_FULL;
    if (!(node = create_qnode(task)))
        return MEM_ERR;
    if (queue->rear)
    {
        queue->rear->next = node;
        queue->rear = node;
        queue->size++;
    }
    else
    {
        queue->front = node;
        queue->rear = node;
        queue->size++;
    }
    return OK;
}

int get_list_queue(listq_t *const queue, task_t *task)
{
    if (is_list_empty(queue))
        return Q_EMPTY;
    qnode_t *node = queue->front;
    *task = node->task;
    if (queue->front == queue->rear)
    {
        queue->rear = NULL;
        queue->front = NULL;
    }
    else
    {
        queue->front = queue->front->next;
    }
    delete_qnode(node);
    queue->size--;
    return OK;
}
