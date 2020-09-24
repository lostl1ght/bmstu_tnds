#include "../inc/io.h"
#include <stdio.h>

#define IO_SUCCESS 0
#define IO_FAILURE 1

int input_str(char str[])
{
    printf("Input number: ");
    if (!fgets(str, MAX_SYMBOLS + 3, stdin))
        return IO_FAILURE;
    return IO_SUCCESS;
}
