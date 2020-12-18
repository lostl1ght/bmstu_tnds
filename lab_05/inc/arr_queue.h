#ifndef ARR_QUEUE_H
#define ARR_QUEUE_H

#include <stdlib.h>
#include "task.h"
#include "rc.h"

typedef struct
{
    size_t cap;
    size_t size;
    size_t front;
    size_t rear;
    task_t *arr;
} arrq_t;

arrq_t *create_arr_queue(const size_t cap);
void delete_arr_queue(arrq_t *queue);

int is_arr_full(arrq_t *const queue);
int is_arr_empty(arrq_t *const queue);

int put_arr_queue(arrq_t *const queue, const task_t task);
int get_arr_queue(arrq_t *const queue, task_t *task);

#endif
