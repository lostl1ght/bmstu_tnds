#include "free_adr.h"

int add_to_arr(size_t adr)
{
    adr_t *adr_s;
    int rc = 0;
    if ((adr_s = find_in_arr(adr)))
        adr_s->cnt++;
    else if (arr.nmemb < ARRSIZE)
    {
        arr.arr[arr.nmemb].adr = adr;
        arr.arr[arr.nmemb].cnt = 1;
        arr.nmemb++;
    }
    else
        rc = 1;
    return rc;
}

adr_t *find_in_arr(size_t adr)
{
    for (size_t i = 0; i < arr.nmemb; i++)
        if (arr.arr[i].adr == adr)
            return arr.arr + i;
    return NULL;
}

void output_arr(void)
{
    puts("Free adresses array:");
    for (size_t i = 0; i < arr.nmemb; i++)
        printf("Adress: %zu, times used: %zu\n", arr.arr[i].adr, arr.arr[i].cnt);
}

void empty_arr(void)
{
    for (size_t i = 0; i < arr.nmemb; i++)
    {
        arr.arr[i].cnt = 0;
        arr.arr[i].adr = 0;
    }
    arr.nmemb = 0;
}
