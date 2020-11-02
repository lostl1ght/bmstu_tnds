#include <stdio.h>

typedef enum choice
{
    END,
    INPUT,
    SUMSIMPLE,
    SUMSPARSE,
    ERROR
} choice_t;

int menu(void);

int main(void)
{
    int rc;
    char flag = 1;
    while (flag)
    {
        rc = menu();
        switch (rc)
        {
            case INPUT:
                puts("input");
                // input_matrix();
                break;
            case SUMSIMPLE:
                puts("simple");
                // sum_as_simple();
                break;
            case SUMSPARSE:
                puts("sparse");
                // sum_as_sparse();
                break;
            case END:
                puts("Goodbye!");
                flag = 0;
                break;
            default:
                puts("Unknown option.");
                break;
        }
    }
    return 0;
}

int menu(void)
{
    int rc;
    char buf[64];
    puts("\nMENU");
    puts("\tEnter 1 to input matrices.");
    puts("\tEnter 2 to sum matrices input as matrices.");
    puts("\tEnter 3 to sum matrices input as sparse matrices.");
    puts("\tEnter 0 to end program.");
    if (scanf("%d", &rc) != 1)
    {
        fgets(buf, 64, stdin);
        rc = ERROR;
    }
    if (rc < 0)
        rc = ERROR;
    return rc;
}