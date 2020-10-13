#define _USE_MINGW_ANSI_STDIO 1
#include "flat.h"
#include "sort.h"
#include "find.h"
#include <string.h>
#include <stdio.h>

#define SUCCESS 0
#define INPUT_FAILURE 1
#define READ_FAILURE 2
#define ARG_FAILURE 3
#define OPEN_FAILURE 4
#define DELETE_FAILURE 5
#define APPEND_FAILURE 6
#define MERGE_NO_KEY_FAILURE 7
#define INS_NO_KEY_FAILURE 8
#define MERGE_WITH_KEY_FAILURE 9
#define INS_WITH_KEY_FAILURE 10
#define FIND_FAILURE 11

void help(void);

int main(int argc, char **argv)
{
    int rc = SUCCESS;
    if (argc < 2 || argc > 5)
    {
        puts("Unknown arguments.");
        rc = ARG_FAILURE;
    }
    else if (argc == 2 && strcmp(argv[1], "-help") == 0)
    {
        help();
    }
    else if (argc == 3 && strcmp(argv[1], "-i") == 0)
    {
        FILE *f;
        f = fopen(argv[2], "w");
        if (!f)
        {
            puts("File cannot be opened.");
            rc = OPEN_FAILURE;
        }
        else
        {
            if (input_to_file(f))
            {
                puts("Failure during input.");
                rc = INPUT_FAILURE;
            }
            fclose(f);
        }
    }
    else if (argc == 3 && strcmp(argv[1], "-o") == 0)
    {
        FILE *f;
        f = fopen(argv[2], "r");
        if (!f)
        {
            puts("File cannot be opened.");
            rc = OPEN_FAILURE;
        }
        else
        {
            if (output_table(f))
            {
                puts("Failure during reading.");
                rc = READ_FAILURE;
            }
            fclose(f);
        }
    }
    else if (argc == 5 && strcmp(argv[1], "-d") == 0)
    {
        int index;
        FILE *f_in, *f_out;
        if (sscanf(argv[2], "%d", &index) != 1 || index < 0)
            rc = ARG_FAILURE;
        else
        {
            f_in = fopen(argv[3], "r");
            if (!f_in)
            {
                puts("Input file cannot be opened.");
                rc = OPEN_FAILURE;
            }
            else
            {
                f_out = fopen(argv[4], "w");
                if (!f_out)
                {
                    fclose(f_in);
                    puts("Output file cannot be opened.");
                    rc = OPEN_FAILURE;
                }
                else
                {
                    if (delete_by_index(f_in, f_out, index))
                    {
                        puts("Failure during deletion.");
                        rc = DELETE_FAILURE;
                    }
                    else
                        printf("Flat number %d deleted.", index);
                    fclose(f_in);
                    fclose(f_out);
                }
            }
        }
    }
    else if (argc == 4 && strcmp(argv[1], "-a") == 0)
    {
        FILE *f_in, *f_out;
        f_in = fopen(argv[2], "r");
        if (!f_in)
        {
            puts("Input file cannot be opened.");
            rc = OPEN_FAILURE;
        }
        else
        {
            f_out = fopen(argv[3], "w");
            if (!f_out)
            {
                fclose(f_in);
                puts("Output file cannot be opened.");
                rc = OPEN_FAILURE;
            }
            else
            {
                if (append_to_file(f_in, f_out))
                {
                    puts("Failure during appending.");
                    rc = APPEND_FAILURE;
                }
                else
                    puts("Flat was appended.");
                fclose(f_in);
                fclose(f_out);
            }
        }
    }
    else if (argc == 4 && strcmp(argv[1], "-mrg") == 0)
    {
        FILE *f_in, *f_out;
        f_in = fopen(argv[2], "r");
        if (!f_in)
        {
            puts("Input file cannot be opened.");
            rc = OPEN_FAILURE;
        }
        else
        {
            f_out = fopen(argv[3], "w");
            if (!f_out)
            {
                fclose(f_in);
                puts("Output file cannot be opened.");
                rc = OPEN_FAILURE;
            }
            else
            {
                if (merge_sort_no_keys(f_in, f_out))
                {
                    puts("Failure during sorting.");
                    rc = MERGE_NO_KEY_FAILURE;
                }
                else
                    puts("Array was sorted.");
                fclose(f_in);
                fclose(f_out);
            }
        }
    }
    else if (argc == 4 && strcmp(argv[1], "-ins") == 0)
    {
        FILE *f_in, *f_out;
        f_in = fopen(argv[2], "r");
        if (!f_in)
        {
            puts("Input file cannot be opened.");
            rc = OPEN_FAILURE;
        }
        else
        {
            f_out = fopen(argv[3], "w");
            if (!f_out)
            {
                fclose(f_in);
                puts("Output file cannot be opened.");
                rc = OPEN_FAILURE;
            }
            else
            {
                if (insert_sort_no_keys(f_in, f_out))
                {
                    puts("Failure during sorting.");
                    rc = INS_NO_KEY_FAILURE;
                }
                else
                    puts("Array was sorted.");
                fclose(f_in);
                fclose(f_out);
            }
        }
    }
    else if (argc == 5 && strcmp(argv[1], "-mrg") == 0 && strcmp(argv[2], "-k") == 0)
    {
        FILE *f_in, *f_out;
        f_in = fopen(argv[3], "r");
        if (!f_in)
        {
            puts("Input file cannot be opened.");
            rc = OPEN_FAILURE;
        }
        else
        {
            f_out = fopen(argv[4], "w");
            if (!f_out)
            {
                fclose(f_in);
                puts("Output file cannot be opened.");
                rc = OPEN_FAILURE;
            }
            else
            {
                if (merge_sort_with_keys(f_in, f_out))
                {
                    puts("Failure during sorting.");
                    rc = MERGE_WITH_KEY_FAILURE;
                }
                else
                    puts("Array was sorted.");
                fclose(f_in);
                fclose(f_out);
            }
        }
    }
    else if (argc == 5 && strcmp(argv[1], "-ins") == 0 && strcmp(argv[2], "-k") == 0)
    {
        FILE *f_in, *f_out;
        f_in = fopen(argv[3], "r");
        if (!f_in)
        {
            puts("Input file cannot be opened.");
            rc = OPEN_FAILURE;
        }
        else
        {
            f_out = fopen(argv[4], "w");
            if (!f_out)
            {
                fclose(f_in);
                puts("Output file cannot be opened.");
                rc = OPEN_FAILURE;
            }
            else
            {
                if (insert_sort_with_keys(f_in, f_out))
                {
                    puts("Failure during sorting.");
                    rc = INS_WITH_KEY_FAILURE;
                }
                else
                    puts("Array was sorted.");
                fclose(f_in);
                fclose(f_out);
            }
        }
    }
    else if (argc == 4 && strcmp(argv[1], "-f") == 0)
    {
        FILE *f_in, *f_out;
        f_in = fopen(argv[2], "r");
        if (!f_in)
        {
            puts("Input file cannot be opened.");
            rc = OPEN_FAILURE;
        }
        else
        {
            f_out = fopen(argv[3], "w");
            if (!f_out)
            {
                fclose(f_in);
                puts("Output file cannot be opened.");
                rc = OPEN_FAILURE;
            }
            else
            {
                int rcc;
                if ((rcc = find_in_file(f_in, f_out)) > 0)
                {
                    puts("Failure during finding.");
                    rc = FIND_FAILURE;
                }
                else if (rcc == -1)
                {
                    puts("Flats were not found.");
                }
                else
                    puts("Flats were found.");
                fclose(f_in);
                fclose(f_out);
            }
        }
    }
    else
    {
        puts("Unknown arguments.");
        rc = ARG_FAILURE;
    }
    return rc;
}

void help(void)
{
    puts("-help | Get help.");
    puts("-i out.txt | Get flats from stream and write them to out.txt");
    puts("-o in.txt | Output a table of flats from in.txt.");
    puts("-d index in.txt out.txt | Delete an index flat from in.txt and write the rest to out.txt");
    puts("-a in.txt out.txt | Read an array of flats from in.txt, append a flat and write to out.txt.");
    puts("-mrg [-k] in.txt out.txt | Merge sort struct array from in.txt and write to out.txt. If -k is invoked, array of keys will be sorted instead.");
    puts("-ins [-k] in.txt out.txt | Insertion struct array from in.txt and write to out.txt. If -k is invoked, array of keys will be sorted instead.");
    puts("-f in.txt out.txt | Find in in.txt all the second hand 2 room flats in chosen price range without animals, write results in out.txt.");
}
