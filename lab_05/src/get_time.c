#include "get_time.h"

double get_time(const time_range_t t)
{
    double rnd = (double)rand() / (double)RAND_MAX;
    return (t.rlim - t.llim) * rnd + t.llim;
}
