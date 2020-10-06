#include "flat.h"

int input_flat(flat_t *flat)
{
    char buf[3];
    printf("Enter flat address: ");
    if (!fgets(flat->adr, MAXN, stdin))
        return FLT_FAILURE;
    printf("Enter area of the flat: ");
    if (scanf("%f", &flat->area) != 1)
        return FLT_FAILURE;
    printf("Enter room count: ");
    if (scanf("%d", &flat->room_cnt) != 1)
        return FLT_FAILURE;
    printf("Enter price per square meter: ");
    if (scanf("%d%c", &flat->price_per_m2, buf) != 2)
        return FLT_FAILURE;
    printf("Is it a new flat? (y/n)\n");
    if (!fgets(buf, sizeof buf, stdin))
        return FLT_FAILURE;
    if (*buf == 'y')
    {
        flat->is_new = 1;
        printf("Is it trimmed? (y/n)\n");
        if (!fgets(buf, sizeof buf, stdin))
            return FLT_FAILURE;
        if (*buf == 'y')
            flat->type.is_trim = 1;
        else if (*buf == 'n')
            flat->type.is_trim = 0;
        else
            return FLT_FAILURE;
    }
    else if (*buf == 'n')
    {
        flat->is_new = 0;
        printf("Enter year of construction: ");
        if (scanf("%d", &flat->type.old.year) != 1)
            return FLT_FAILURE;
        printf("Enter number of last owners: ");
        if (scanf("%d", &flat->type.old.owner_cnt) != 1)
            return FLT_FAILURE;
        printf("Enter number of last residents: ");
        if (scanf("%d", &flat->type.old.lst_rsdnt_cnt) != 1)
            return FLT_FAILURE;
        printf("Did they have any enimals? (y/n)\n");
        if (!fgets(buf, sizeof buf, stdin))
            return FLT_FAILURE;
        if (*buf == 'y')
            flat->type.old.were_anmls = 1;
        else if (*buf == 'n')
            flat->type.old.were_anmls = 0;
        else
            return FLT_FAILURE;
    }
    else
        return FLT_FAILURE;
    return FLT_SUCCESS;
}
