#include "arr_queue.h"

arr_queue_t *create_arr_queue(const size_t cap)
{
    arr_queue_t *queue;
    if (!(queue = malloc(sizeof *queue)))
        return NULL;
    queue->cap = cap;
    queue->front = 0;
    queue->size = 0;
    queue->rear = cap -1;
    if (!(queue->arr = malloc(cap * sizeof *queue->arr)))
    {
        free(queue);
        return NULL;
    }
    return queue;
}

void delete_arr_queue(arr_queue_t *queue)
{
    free(queue->arr);
    free(queue);
}

int is_arr_full(arr_queue_t *const queue)
{
    return queue->size == queue->cap;
}

int is_arr_empty(arr_queue_t *const queue)
{
    return queue->size == 0;
}

int put_arr_queue(arr_queue_t *const queue, const task_t task)
{
    if (is_arr_full(queue))
        return 1;
    queue->rear = (queue->rear + 1) % queue->cap;
    queue->arr[queue->rear] = task;
    queue->size++;
    return 0;
}

int get_arr_queue(arr_queue_t *const queue, task_t *task)
{
    if (is_arr_empty(queue))
        return 1;
    *task = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->cap;
    queue->size--;
    return 0;
}
