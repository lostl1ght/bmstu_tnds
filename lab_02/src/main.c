#define _USE_MINGW_ANSI_STDIO 1
#include "flat.h"
#include <string.h>
#include <stdio.h>

#define SUCCESS 0
#define INPUT_FAILURE 1
#define READ_FAILURE 2
#define ARG_FAILURE 3
#define OPEN_FAILURE 4
#define DELETE_FAILURE 5

void help(void);

int main(int argc, char **argv)
{
    int rc = SUCCESS;
    if (argc < 2 || argc == 4 || argc > 5)
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
    else if (argc == 5 && strcmp(argv[1], "-d"))
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
                rc = OPEN_FAILURE;
            }
            else
            {
                f_out = fopen(argv[4], "w");
                if (!f_out)
                {
                    fclose(f_in);
                    rc = OPEN_FAILURE;
                }
                else
                {
                    if (delete_by_index(f_in, f_out, index))
                    {
                        puts("Failure during deletion");
                        rc = DELETE_FAILURE;
                    }
                    printf("Flat number %d deleted.", index);
                    fclose(f_in);
                    fclose(f_out);
                }
            }
        }
    }

    return rc;
}

void help(void)
{
    puts("-help | Get help.");                                            // Сделано
    puts("-i out.txt | Get flats from stream and write them to out.txt"); // Сделано
    puts("-o in.txt | Output a table of flats from in.txt.");             // Сделано
    puts("-d index in.txt out.txt | Delete an index flat from in.txt and write the rest to out.txt");
    puts("-a in.txt out.txt | Read an array of flats from in.txt, append a flat and write to out.txt.");
    puts("-s1 [-k] in.txt out.txt | Sort 1 struct array from in.txt and write to out.txt. If -k is invoked, array of keys will be sorted instead.");
    puts("-s2 [-k] in.txt out.txt | Sort 2 struct array from in.txt and write to out.txt. If -k is invoked, array of keys will be sorted instead.");
}
