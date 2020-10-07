#define _USE_MINGW_ANSI_STDIO 1
#include "flat.h"

#define SUCCESS 0
#define COUNT_FAILURE 1
#define READ_FAILURE 2

int main(void)
{
    flat_t *flats;
    int flt_cnt = 0;
    char buf;
    printf("Enter number of flats: ");
    if (scanf("%d%c", &flt_cnt, &buf) != 2 || flt_cnt < 0)
    {
        printf("Wrong number of flats!");
        return COUNT_FAILURE;
    }
    if (input_flat_array(&flats, flt_cnt))
    {
        printf("Wrong input!");
        return READ_FAILURE;
    }
    output_flat_array(flats, flt_cnt);
    free(flats);
    return SUCCESS;
}