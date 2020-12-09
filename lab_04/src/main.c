#include <stdio.h>
#include "array_stack.h"

int main_menu(void);
int arr_menu(void);
int list_menu(void);

int main(void)
{
    int main_cmd, cmd;
    while ((main_cmd = main_menu()))
        switch (main_cmd)
        {
            case 1:
                while((cmd = arr_menu()))
                    switch (cmd)
                    {
                        case 1:
                            puts("create");
                            break;
                        case 2:
                            puts("add 1");
                            break;
                        case 3:
                            puts("add 2");
                            break;
                        case 4:
                            puts("pop 1");
                            break;
                        case 5:
                            puts("pop 2");
                            break;
                        case 6:
                            puts("empty 1");
                            break;
                        case 7:
                            puts("empty 2");
                            break;
                        case 8:
                            puts("out");
                            break;
                        default:
                            puts("unknown");
                            break;
                    }
                break;
            case 2:
                while((cmd = list_menu()))
                    switch (cmd)
                    {
                        case 1:
                            puts("create");
                            break;
                        case 2:
                            puts("add 1");
                            break;
                        case 3:
                            puts("add 2");
                            break;
                        case 4:
                            puts("pop 1");
                            break;
                        case 5:
                            puts("pop 2");
                            break;
                        case 6:
                            puts("empty 1");
                            break;
                        case 7:
                            puts("empty 2");
                            break;
                        case 8:
                            puts("out");
                            break;                        
                        case 9:
                            puts("free");
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
    char buf[64];
    puts("\n\tWelcome to Stack Playground.");
    puts("\tEnter a number to choose stack type:");
    puts("1. Array stack.");
    puts("2. List stack.");
    puts("0. Exit program.");
    if (scanf("%d", &cmd) != 1)
    {
        fgets(buf, 64, stdin);
        return -1;
    }
    return cmd;
}

int arr_menu(void)
{
    int cmd;
    char buf[64];
    puts("\n\tArray stack menu.");
    puts("\tEnter a number to choose command:");
    puts("1. Create an array stack.");
    puts("2. Add a number to the 1st stack.");
    puts("3. Add a number to the 2nd stack.");
    puts("4. Pop a number from the 1st stack.");
    puts("5. Pop a number from the 2nd stack.");
    puts("6. Empty the 1st stack.");
    puts("7. Empty the 2nd stack.");
    puts("8. Output stacks.");
    puts("0. Exit this menu.");
    if (scanf("%d", &cmd) != 1)
    {
        fgets(buf, 64, stdin);
        return -1;
    }
    return cmd;
}

int list_menu(void)
{
    int cmd;
    char buf[64];
    puts("\n\tList stack menu.");
    puts("\n\tEnter a number to choose command:");
    puts("1. Create an array stack.");
    puts("2. Add a number to the 1st stack.");
    puts("3. Add a number to the 2nd stack.");
    puts("4. Pop a number from the 1st stack.");
    puts("5. Pop a number from the 2nd stack.");
    puts("6. Empty the 1st stack.");
    puts("7. Empty the 2nd stack.");
    puts("8. Output stacks.");
    puts("9. Output free adresses");
    puts("0. Exit this menu.");
    if (scanf("%d", &cmd) != 1)
    {
        fgets(buf, 64, stdin);
        return -1;
    }
    return cmd;
}
