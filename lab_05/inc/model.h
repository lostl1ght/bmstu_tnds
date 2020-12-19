#ifndef MODEL_H
#define MODEL_H

#include "arr_queue.h"
#include "list_queue.h"
#include "task.h"
#include "get_time.h"
#include <math.h>
#include <stdio.h>

void arr_model(arrq_t *const q1, arrq_t *const q2,
               const time_range_t t1, const time_range_t t2,
               const time_range_t t3, const time_range_t t4);

void list_model(listq_t *const q1, listq_t *const q2,
               const time_range_t t1, const time_range_t t2,
               const time_range_t t3, const time_range_t t4);

#endif