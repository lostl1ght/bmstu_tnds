#include <stdio.h>
#include "matrix.h"
#include "sparse.h"
#include "matrix_process.h"

typedef enum choice 
{
    END,
    INPUTSIMPLE,
    INPUTSPARSE,
    SUMSIMPLE,
    SUMSPARSE,
    OUTPUT,
    ERROR
} choice_e;

choice_e menu(void);

int main(void)
{
    matrix_s m1;//, m2;
    sparse_s s1;//, s2;
    choice_e chc;
    char flag = 1;
    int inpt_m1 = 2, inpt_s1 = 2, cnvrt_to_m1 = 2, cnvrt_to_s1 = 2;
    // int inpt_m2 = 2, inpt_s2 = 2, cnvrt_to_m2 = 2, cnvrt_to_s2 = 2;
    while (flag)
    {
        chc = menu();
        switch (chc)
        {
            case INPUTSIMPLE:
                inpt_m1 = matrux_input_wrapper(&m1);
                if (!inpt_m1)
                {
                    cnvrt_to_s1 = convert_to_sparse(&m1, &s1);
                    if (cnvrt_to_s1)
                        puts("Convertion to sparse failed. You cannot sum matrices as sparse.");
                }
                else
                    puts("Input simple matrix failed.");
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
            case OUTPUT:
                puts("Matrix 1:");
                if (!inpt_m1 || !cnvrt_to_m1)
                    output_matrix(&m1);
                if (!inpt_s1 || !cnvrt_to_s1)
                    output_sparse(&s1);
                break;
            default:
                puts("Unknown option.");
                break;
        }
    }
    if (!inpt_m1 || !cnvrt_to_m1)
        delete_matrix(&m1);
    if (!inpt_s1 || !cnvrt_to_s1)
        delete_sparse(&s1);
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
    puts("\tEnter 5 to output matrices input.");    
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