#ifndef GET_TIME_H
#define GET_TIME_H

#include <stdlib.h>
#include <time.h>

typedef struct
{
    long llim;
    long rlim;
} time_range_t;

double get_time(const time_range_t t);

#endif
