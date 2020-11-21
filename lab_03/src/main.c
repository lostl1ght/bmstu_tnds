#include <stdio.h>
#include "matrix.h"
#include "sparse.h"
#include "converters.h"
#include "summatrix.h"
#include "sumsparse.h"

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
    matrix_s m1, m2, mres;
    sparse_s s1, s2, sres;
    choice_e chc;
    char flag = 1;
    int inpt_m1 = 2, inpt_s1 = 2, cnvrt_to_m1 = 2, cnvrt_to_s1 = 2;
    int inpt_m2 = 2, inpt_s2 = 2, cnvrt_to_m2 = 2, cnvrt_to_s2 = 2;
    while (flag)
    {
        chc = menu();
        switch (chc)
        {
            case INPUTSIMPLE:
                if (!inpt_m1 || !cnvrt_to_m1)
                    delete_matrix(&m1);
                if (!inpt_s1 || !cnvrt_to_s1)
                    delete_sparse(&s1);
                inpt_m1 = matrux_input_wrapper(&m1);
                if (!inpt_m1)
                {
                    cnvrt_to_s1 = convert_to_sparse(&m1, &s1);
                    if (cnvrt_to_s1)
                        puts("Convertion to sparse 1 failed. You cannot sum matrices as sparse.");
                }
                else
                    puts("Input simple matrix 1 failed.");

                if (!inpt_m2 || !cnvrt_to_m2)
                    delete_matrix(&m2);
                if (!inpt_s2 || !cnvrt_to_s2)
                    delete_sparse(&s2);
                inpt_m2 = matrux_input_wrapper(&m2);
                if (!inpt_m2)
                {
                    cnvrt_to_s2 = convert_to_sparse(&m2, &s2);
                    if (cnvrt_to_s2)
                        puts("Convertion to sparse 2 failed. You cannot sum matrices as sparse.");
                }
                else
                    puts("Input simple matrix 2 failed.");
                break;
            case INPUTSPARSE:
                if (!inpt_m1 || !cnvrt_to_m1)
                    delete_matrix(&m1);
                if (!inpt_s1 || !cnvrt_to_s1)
                    delete_sparse(&s1);
                inpt_s1 = sparse_input_wrapper(&s1);
                if (!inpt_s1)
                {
                    cnvrt_to_m1 = convert_to_matrix(&m1, &s1);
                    if (cnvrt_to_m1)
                        puts("Convertion to matrix 1 failed. You cannot sum matrices as simple.");
                }
                else
                    puts("Input sparse matrix 1 failed");

                if (!inpt_m2 || !cnvrt_to_m2)
                    delete_matrix(&m2);
                if (!inpt_s2 || !cnvrt_to_s2)
                    delete_sparse(&s2);
                inpt_s2 = sparse_input_wrapper(&s2);
                if (!inpt_s2)
                {
                    cnvrt_to_m2 = convert_to_matrix(&m2, &s2);
                    if (cnvrt_to_m2)
                        puts("Convertion to matrix 2 failed. You cannot sum matrices as simple.");
                }
                else
                    puts("Input sparse matrix 2 failed");
                break;
            case SUMSIMPLE:
                if ((!inpt_m1 && !inpt_m2) || (!cnvrt_to_m1 && !cnvrt_to_m2))
                {
                    if (m1.cols != m2.cols || m1.rows != m2.rows)
                        puts("Sizes of matrices are not same.");
                    else
                    {
                        mres.cols = m1.cols;
                        mres.rows = m1.rows;
                        if (create_matrix(&mres))
                            puts("Cannot create result matrix.");
                        else
                        {
                            summatrix(&m1, &m2, &mres);
                            puts("Result:");
                            output_matrix(&mres);
                            if (convert_to_sparse(&mres, &sres))
                                puts("Cannot convert result matrix to sparse.");
                            else
                            {
                                output_sparse(&sres);
                                delete_sparse(&sres);
                            }
                            delete_matrix(&mres);
                        }
                    }
                }
                else
                    puts("Input is invalid.");
                break;
            case SUMSPARSE:
                if ((!inpt_s1 && !inpt_s2) || (!cnvrt_to_s1 && !cnvrt_to_s2))
                {
                    if (s1.c_count != s2.c_count || s1.r_count != s2.r_count)
                        puts("Sizes of matrices are not same.");
                    else
                    {
                        sres.c_count = s1.c_count;
                        sres.r_count = s1.r_count;
                        sres.n_count = s1.n_count + s2.n_count;
                        if (create_sparse(&sres))
                            puts("Cannot create result matrix.");
                        else
                        {
                            sumsparse(&s1, &s2, &sres);
                            puts("Result:");
                            if (convert_to_matrix(&mres, &sres))
                                puts("Cannot convert result matrix to simple.");
                            else
                            {
                                output_matrix(&mres);
                                delete_matrix(&mres);
                            }
                            output_sparse(&sres);
                            delete_sparse(&sres);
                        }
                    }
                }
                else
                    puts("Input is invalid.");
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
                puts("Matrix 2:");
                if (!inpt_m2 || !cnvrt_to_m2)
                    output_matrix(&m2);
                if (!inpt_s2 || !cnvrt_to_s2)
                    output_sparse(&s2);
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
    if (!inpt_m2 || !cnvrt_to_m2)
        delete_matrix(&m2);
    if (!inpt_s2 || !cnvrt_to_s2)
        delete_sparse(&s2);
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
