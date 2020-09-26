#include "../inc/io.h"

#define IO_SUCCESS 0
#define IO_FAILURE 1

#define IO_WRONG_CHARACTERS 2

int input_str(char str[])
{
    printf("Input number: ");
    if (!fgets(str, LEN, stdin))
        return IO_FAILURE;
    return IO_SUCCESS;
}
