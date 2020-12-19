#include <stdio.h>
#include "arr_model.h"

#define BUFSIZE 64

int menu(void);
int arr_menu(void);
int list_menu(void);

int main(void)
{
    srand(clock());
    int cmd = -1;

    while ((cmd = menu()))
    {
        time_range_t t1 = {.llim = 1, .rlim = 5};
        time_range_t t2 = {.llim = 0, .rlim = 3};
        time_range_t t3 = {.llim = 0, .rlim = 4};
        time_range_t t4 = {.llim = 0, .rlim = 1};
        size_t cap = 10;
        switch (cmd)
        {
            case 1:
                while ((cmd = arr_menu()))
                    switch (cmd)
                    {
                        case 1:
                            {
                                arrq_t *q1, *q2;
                                if (!(q1 = create_arr_queue(cap)))
                                    puts("Couldn't create a queue.");
                                else if (!(q2 = create_arr_queue(cap)))
                                {
                                    delete_arr_queue(q1);
                                    puts("Couldn't create a queue.");
                                }
                                else
                                {
                                    arr_model(q1, q2, t1, t2, t3, t4);
                                    delete_arr_queue(q1);
                                    delete_arr_queue(q2);
                                }
                            }
                            break;
                        case 2:
                            puts("input");
                            break;
                        case 3:
                            puts("show");
                            break;
                        default:
                            puts("Unknown command");
                            break;
                    }
                break;
            case 2:
                while ((cmd = list_menu()))
                    switch (cmd)
                    {
                        case 1:
                            puts("run");
                            break;
                        case 2:
                            puts("input");
                            break;
                        case 3:
                            puts("show");
                            break;
                        default:
                            puts("Unknown command");
                            break;
                    }
                break;
            default:
                puts("Unknown command");
                break;
        }
    }
    puts("Goodbye!");
    return 0;
}

int menu(void)
{
    int cmd;
    char buf[BUFSIZE];
    puts("\n\tQueue modelling.");
    puts("1. Array model");
    puts("2. List model.");
    puts("0. Exit.");
    printf("Command: ");
    if (scanf("%d", &cmd) != 1)
    {
        fgets(buf, BUFSIZE, stdin);
        return -1;
    }
    return cmd;
}

int arr_menu(void)
{
    int cmd;
    char buf[BUFSIZE];
    puts("\n\tArray queue menu.");
    puts("1. Run model.");
    puts("2. Set parameters.");
    puts("3. Show parameters.");
    puts("0. Exit.");
    printf("Command: ");
    if (scanf("%d", &cmd) != 1)
    {
        fgets(buf, BUFSIZE, stdin);
        return -1;
    }
    return cmd;
}

int list_menu(void)
{
    int cmd;
    char buf[BUFSIZE];
    puts("\n\tList queue menu.");
    puts("1. Run model.");
    puts("2. Set parameters.");
    puts("3. Show parameters.");
    puts("0. Exit.");
    printf("Command: ");
    if (scanf("%d", &cmd) != 1)
    {
        fgets(buf, BUFSIZE, stdin);
        return -1;
    }
    return cmd;
}
