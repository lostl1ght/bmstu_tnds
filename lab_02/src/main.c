#define _USE_MINGW_ANSI_STDIO 1
#include "flat.h"
#include <string.h>
#include <stdio.h>

#define SUCCESS 0
#define INPUT_FAILURE 1
#define READ_FAILURE 2
#define ARG_FAILURE 3
#define OPEN_FAILURE 4

void help(void);

int main(int argc, char **argv)
{
    if (argc < 2 || argc == 4 || argc > 5)
    {
        puts("Unknown arguments.");
        return ARG_FAILURE;
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
            return OPEN_FAILURE;
        }
        if (input_flats_to_file(f))
        {
            puts("Failure during input.");
            return INPUT_FAILURE;
        }
        fclose(f);
    }

    return SUCCESS;
}

void help(void)
{
    puts("-help | Get help.");
    puts("-i out.txt | Get flats from stream and write them to out.txt");
    puts("-o in.txt | Output a table of flats from in.txt.");
    puts("-s1 [k] in.txt out.txt | Sort 1 struct array from in.txt and write to out.txt. If k is invoked, array of keys will be sorted instead.");
    puts("-s2 [k] in.txt out.txt | Sort 2 struct array from in.txt and write to out.txt. If k is invoked, array of keys will be sorted instead.");
    puts("-d index in.txt out.txt | Delete an index flat from in.txt and write the rest to out.txt");
}
