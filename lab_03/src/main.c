#include <stdio.h>
#include "matrix.h"

typedef enum choice 
{
    END,
    INPUTSIMPLE,
    INPUTSPARSE,
    SUMSIMPLE,
    SUMSPARSE,
    ERROR
} choice_e;

choice_e menu(void);

int main(void)
{
    matrix_s m1;//, m2;
    choice_e chc;
    char flag = 1;
    while (flag)
    {
        chc = menu();
        switch (chc)
        {
            case INPUTSIMPLE:
                if (read_size(&m1))
                {
                    puts("Size input failed.");
                    break;
                }
                if (create_matrix(&m1))
                {
                    puts("Memory allocation failed.");
                    break;
                }
                puts("Enter matrix elements:");
                if (input_matrix(&m1))
                {
                    delete_matrix(&m1);
                    puts("Matrix input failed.");
                    break;
                }
                output_matrix(&m1);
                break;
            case INPUTSPARSE:
                puts("input sparese");
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
    delete_matrix(&m1);
    return 0;
}

choice_e menu(void)
{
    int rc;
    char buf[64];
    puts("\nMENU");
    puts("\tEnter 1 to input simple matrices.");
    puts("\tEnter 2 to input sparse matrices.");
    puts("\tEnter 3 to sum matrices input as matrices.");
    puts("\tEnter 4 to sum matrices input as sparse matrices.");
    puts("\tEnter 0 to end program.");
    if (scanf("%d", &rc) != 1)
    {
        fgets(buf, 64, stdin);
        rc = ERROR;
    }
    if (rc < END || rc > ERROR)
        rc = ERROR;
    return rc;
}