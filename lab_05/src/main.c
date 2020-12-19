#include <stdio.h>
#include "model.h"

#define BUFSIZE 64

int menu(void);
int arr_menu(void);
int list_menu(void);
void output_param(time_range_t t1, time_range_t t2, time_range_t t3, time_range_t t4);

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
                            output_param(t1, t2, t3, t4);
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
                            {
                                listq_t *q1, *q2;
                                if (!(q1 = create_list_queue(cap)))
                                    puts("Couldn't create a queue.");
                                else if (!(q2 = create_list_queue(cap)))
                                {
                                    delete_list_queue(q1);
                                    puts("Couldn't create a queue.");
                                }
                                else
                                {
                                    list_model(q1, q2, t1, t2, t3, t4);
                                    delete_list_queue(q1);
                                    delete_list_queue(q2);
                                }
                            }
                            break;
                        case 2:
                            puts("input");
                            break;
                        case 3:
                            output_param(t1, t2, t3, t4);
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

void output_param(time_range_t t1, time_range_t t2, time_range_t t3, time_range_t t4)
{
    printf("Type 1 request income time:  min - %ld, max - %ld\n", t1.llim, t1.rlim);
    printf("Type 2 request income time:  min - %ld, max - %ld\n", t2.llim, t2.rlim);
    printf("Type 1 request process time: min - %ld, max - %ld\n", t3.llim, t3.rlim);
    printf("Type 2 request process time: min - %ld, max - %ld\n", t4.llim, t4.rlim);
}
