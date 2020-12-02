#include <stdio.h>
#include <string.h>

#include "ds.h"
#include "defines.h"

void welcome()
{
    printf("%s", "Given program enables comparing time used to add \n"
                 "2 sparse matrices stored as standard matrix or sparse \ncolumn way. \n\n");
    printf("%s",
           "Choose action by typing a number:\n");
    printf("%s",
           "1. Enter a matrix by hand.\n"
           "2. Generate matrices by percentage filling.\n"
           "3. Add matrices using standard way.\n"
           "4. Add matrices using sparse column way.\n"
           "5. Output all matrices in standard look.\n"
           "6. Output all matrices in sparse column look.\n"
           "0. Exit.\n\n");
}

void clean_input_stream()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

int input_interval(type_t *const num, const type_t left, const type_t right)
{
    if (scanf(type_spec, num) != GOT_ARG)
    {
        clean_input_stream();
        return INVALID_INT_INPUT_ERROR;
    }

    if (*num < left || *num > right)
    {
        clean_input_stream();
        return INVALID_INTERVAL_ERROR;
    }

    return OK;
}