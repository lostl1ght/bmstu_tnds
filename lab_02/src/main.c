#define _USE_MINGW_ANSI_STDIO 1
#include "flat.h"



int main(void) //int argc, char **argv
{
    flat_t *flats = NULL;
    size_t flt_cnt = 0;
    char buf;
    printf("Enter number of flats: ");
    if (scanf("%zu%c", &flt_cnt, &buf) != 2)
        return 1;
    if (input_flat_array(flats, flt_cnt))
        return 1;
    
    return 0;
}