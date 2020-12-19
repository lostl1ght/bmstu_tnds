#ifndef LIST_QUEUE_H
#define LIST_QUEUE_H

#include <stdlib.h>
#include "task.h"
#include "rc.h"
#include "free_adr.h"

typedef struct qnode qnode_t;

struct qnode
{
    task_t task;
    qnode_t *next;
};

typedef struct
{
    size_t cap;
    size_t size;
    qnode_t *front;
    qnode_t *rear;
} listq_t;

qnode_t *create_qnode(const task_t task);
void delete_qnode(qnode_t *const node);

listq_t *create_list_queue(const size_t cap);
void delete_list_queue(listq_t *queue);

int is_list_full(listq_t *const queue);
int is_list_empty(listq_t *const queue);

int put_list_queue(listq_t *const queue, const task_t task);
int get_list_queue(listq_t *const queue, task_t *task);

#endif
