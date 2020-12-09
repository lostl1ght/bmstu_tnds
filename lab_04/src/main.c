#include <stdio.h>
#include "array_stack.h"

#define BUFSIZE 64

int main_menu(void);
int arr_menu(void);
int list_menu(void);

int main(void)
{
    int main_cmd, cmd;
    char buf[BUFSIZE];
    arrstack_t *arrstack = NULL;
    long size;
    while ((main_cmd = main_menu()))
        switch (main_cmd)
        {
            case 1:
                while ((cmd = arr_menu()))
                    switch (cmd)
                    {
                        case 1:
                            if (arrstack)
                                delete_arrstack(arrstack);
                            puts("Enter array size:");
                            if (scanf("%ld", &size) != 1 || size < 1)
                            {
                                fgets(buf, BUFSIZE, stdin);
                                puts("Wrong size.");
                            }
                            else 
                            {
                                uint64_t ticks;
                                arrstack = create_arrstack(size, &ticks);
                                if (!arrstack)
                                    puts("Couldn't create a stack.");
                                else
                                    printf("Time of creating: %lu. Done.", ticks);
                            }
                            break;
                        case 2:
                            if (!arrstack)
                                puts("A stack wasn't created.");
                            else
                            {
                                double num;
                                uint64_t ticks;
                                puts("Enter a number to the 1st stack:");
                                if (scanf("%lf", &num) != 1)
                                {
                                    fgets(buf, BUFSIZE, stdin);
                                    puts("Wrong number.");
                                }
                                else if (push_1st_arrstack(arrstack, num, &ticks))
                                    puts("Stacks are full.");
                                else
                                    printf("Time of pushing: %lu. Done.", ticks);
                            }
                            break;
                        case 3:
                            if (!arrstack)
                                puts("A stack wasn't created.");
                            else
                            {
                                double num;
                                uint64_t ticks;
                                puts("Enter a number to push to the 2nd stack:");
                                if (scanf("%lf", &num) != 1)
                                {
                                    fgets(buf, BUFSIZE, stdin);
                                    puts("Wrong number.");
                                }
                                else if (push_2nd_arrstack(arrstack, num, &ticks))
                                    puts("Stacks are full.");
                                else
                                    printf("Time of pushing: %lu. Done.", ticks);
                            }
                            break;
                        case 4:
                            if (!arrstack)
                                puts("A stack wasn't created.");
                            else
                            {
                                double num;
                                uint64_t ticks;
                                if (pop_1st_arrstack(arrstack, &num, &ticks))
                                    puts("Couldn't pop a number. First stack is empty.");
                                else
                                    printf("Number: %lf. Time of popping a number: %lu", num, ticks);
                            }
                            break;
                        case 5:
                            if (!arrstack)
                                puts("A stack wasn't created.");
                            else
                            {
                                double num;
                                uint64_t ticks;
                                if (pop_2nd_arrstack(arrstack, &num, &ticks))
                                    puts("Couldn't pop a number. Second stack is empty.");
                                else
                                    printf("Number: %lf. Time of popping a number: %lu", num, ticks);
                            }
                            break;
                        case 6:
                            if (!arrstack)
                                puts("A stack wasn't created.");
                            else
                            {
                                uint64_t ticks;
                                empty_1st_arrstack(arrstack, &ticks);
                                printf("Time of emptying: %lu. Done.", ticks);
                            }
                            break;
                        case 7:
                            if (!arrstack)
                                puts("A stack wasn't created.");
                            else
                            {
                                uint64_t ticks;
                                empty_2nd_arrstack(arrstack, &ticks);
                                printf("Time of emptying: %lu. Done.", ticks);
                            }
                            break;
                        case 8:
                            if (!arrstack)
                                puts("A stack wasn't created.");
                            else
                                output_arrstack(arrstack);
                            break;
                        default:
                            puts("unknown");
                            break;
                    }
                if (arrstack)
                    delete_arrstack(arrstack);
                arrstack = NULL;
                break;
            case 2:
                while ((cmd = list_menu()))
                    switch (cmd)
                    {
                        case 1:
                            puts("create");
                            break;
                        case 2:
                            puts("push 1");
                            break;
                        case 3:
                            puts("pop 1");
                            break;
                        case 4:
                            puts("empty 1");
                            break;
                        case 5:
                            puts("out");
                            break;
                        default:
                            puts("unknown");
                            break;
                    }
                break;
            default:
                puts("Unknown command.");
                break;
        }
    puts("Goodbye!");
    return 0;
}

int main_menu(void)
{
    int cmd;
    char buf[BUFSIZE];
    puts("\n\t\tWelcome to Stack Playground.");
    puts("\tEnter a number to choose stack type:");
    puts("1. Array stack.");
    puts("2. List stack.");
    puts("0. Exit program.");
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
    puts("\n\t\tArray stack menu.");
    puts("\tEnter a number to choose command:");
    puts("1. Create an array stack.");
    puts("2. Push a number to the 1st stack.");
    puts("3. Push a number to the 2nd stack.");
    puts("4. Pop a number from the 1st stack.");
    puts("5. Pop a number from the 2nd stack.");
    puts("6. Empty the 1st stack.");
    puts("7. Empty the 2nd stack.");
    puts("8. Output stacks.");
    puts("0. Exit this menu.");
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
    puts("\n\t\tList stack menu.");
    puts("\tEnter a number to choose command:");
    puts("1. Create a list stack.");
    puts("2. Push a number to the stack.");
    puts("3. Pop a number from the stack.");
    puts("4. Empty the stack.");
    puts("5. Output stack.");
    puts("0. Exit this menu.");
    printf("Command: ");
    if (scanf("%d", &cmd) != 1)
    {
        fgets(buf, BUFSIZE, stdin);
        return -1;
    }
    return cmd;
}
