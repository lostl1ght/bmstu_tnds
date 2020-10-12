#include "flat.h"

int get_from_stream(flat_t *flat)
{
    size_t len;
    char buf[3];
    printf("Enter flat address: ");
    if (!fgets(flat->adr, MAXN, stdin))
        return FLT_FAILURE;
    len = strlen(flat->adr);
    if (flat->adr[len - 1] == '\n')
        flat->adr[len - 1] = '\0';
    printf("Enter area of the flat: ");
    if (scanf("%d", &flat->area) != 1)
        return FLT_FAILURE;
    printf("Enter room count: ");
    if (scanf("%d", &flat->room_cnt) != 1)
        return FLT_FAILURE;
    printf("Enter price per square meter: ");
    if (scanf("%d%c", &flat->price_per_m2, buf) != 2)
        return FLT_FAILURE;
    printf("Is it a new flat? (y/n): ");
    if (!fgets(buf, sizeof buf, stdin))
        return FLT_FAILURE;
    if (*buf == 'y')
    {
        flat->is_new = true;
        printf("Is it trimmed? (y/n): ");
        if (!fgets(buf, sizeof buf, stdin))
            return FLT_FAILURE;
        if (*buf == 'y')
            flat->type.is_trim = true;
        else if (*buf == 'n')
            flat->type.is_trim = false;
        else
            return FLT_FAILURE;
    }
    else if (*buf == 'n')
    {
        flat->is_new = false;
        printf("Enter year of construction: ");
        if (scanf("%d", &flat->type.old.year) != 1)
            return FLT_FAILURE;
        printf("Enter number of owners: ");
        if (scanf("%d", &flat->type.old.owner_cnt) != 1)
            return FLT_FAILURE;
        printf("Enter number of last residents: ");
        if (scanf("%d%c", &flat->type.old.lst_rsdnt_cnt, buf) != 2)
            return FLT_FAILURE;
        printf("Did they have any animals? (y/n): ");
        if (!fgets(buf, sizeof buf, stdin))
            return FLT_FAILURE;
        if (*buf == 'y')
            flat->type.old.were_anmls = true;
        else if (*buf == 'n')
            flat->type.old.were_anmls = false;
        else
            return FLT_FAILURE;
    }
    else
        return FLT_FAILURE;
    flat->price = flat->price_per_m2 * flat->area;
    puts("");
    return FLT_SUCCESS;
}

void readable_output(flat_t *flat)
{
    printf("Flat address is %s.\n", flat->adr);
    printf("Area of the flat is %d m2.\n", flat->area);
    printf("Price per square meter is %d.\n", flat->price_per_m2);
    printf("Room count is %d.\n", flat->room_cnt);
    printf("This flat is %s.\n", flat->is_new ? "new" : "old");
    if (flat->is_new)
        printf("The flat is%s trimmed.\n", flat->type.is_trim ? "" : "n't");
    else
    {
        printf("Year of construction is %d.\n", flat->type.old.year);
        printf("Number of owners is %d.\n", flat->type.old.owner_cnt);
        printf("Number of last residents is %d.\n", flat->type.old.lst_rsdnt_cnt);
        printf("They %s animals.\n", flat->type.old.were_anmls ? "had" : "didn't have");
    }
}

int get_array_from_stream(flat_t *flats, int count)
{
    flat_t flat;
    if (!count)
        return FLT_FAILURE;
    if (!flats)
        return FLT_FAILURE;
    for (int i = 0; i < count; i++)
    {
        if (get_from_stream(&flat))
            return FLT_FAILURE;
        *(flats + i) = flat;
    }
    return FLT_SUCCESS;
}

int input_to_file(FILE *f)
{
    char buf[3];
    int count;
    flat_t *flats;
    printf("Enter flat count: ");
    if (scanf("%d%c", &count, buf) != 2 || count < 1)
        return FLT_FAILURE;
    flats = malloc(count * sizeof(flat_t));
    if (!flats)
        return FLT_FAILURE;
    if (get_array_from_stream(flats, count))
    {
        free(flats);
        return FLT_FAILURE;
    }
    write_in_file(f, flats, count);
    free(flats);
    return FLT_SUCCESS;
}

void write_in_file(FILE *f, flat_t *flats, int count)
{
    fprintf(f, "%d\n", count);
    for (int i = 0; i < count; i++)
        simple_output(f, flats + i);
}

void simple_output(FILE *f, flat_t *flat)
{
    fprintf(f, "%s\n", flat->adr);
    fprintf(f, "%d\n", flat->area);
    fprintf(f, "%d\n", flat->price_per_m2);
    fprintf(f, "%d\n", flat->room_cnt);
    fprintf(f, "%d\n", flat->is_new);
    if (flat->is_new)
        fprintf(f, "%d\n", flat->type.is_trim);
    else
    {
        fprintf(f, "%d\n", flat->type.old.year);
        fprintf(f, "%d\n", flat->type.old.owner_cnt);
        fprintf(f, "%d\n", flat->type.old.lst_rsdnt_cnt);
        fprintf(f, "%d\n", flat->type.old.were_anmls);
    }
}

int output_table(FILE *f)
{
    int count;
    flat_t *flats;
    if (fscanf(f, "%d\n", &count) != 1 || count < 1)
        return FLT_FAILURE;
    flats = malloc(count * sizeof(flat_t));
    if (get_array_from_file(f, flats, count))
    {
        free(flats);
        return FLT_FAILURE;
    }
    draw_table(flats, count);
    free(flats);
    return FLT_SUCCESS;
}

int get_array_from_file(FILE *f, flat_t *flats, int count)
{
    for (int i = 0; i < count; i++)
        if (get_from_file(f, flats + i))
            return FLT_FAILURE;
    return FLT_SUCCESS;
}

int get_from_file(FILE *f, flat_t *flat)
{
    size_t len;
    if (!fgets(flat->adr, MAXN, f))
        return FLT_FAILURE;
    len = strlen(flat->adr);
    if (flat->adr[len - 1] == '\n')
        flat->adr[len - 1] = '\0';
    if (fscanf(f, "%d", &flat->area) != 1)
        return FLT_FAILURE;
    if (fscanf(f, "%d", &flat->price_per_m2) != 1)
        return FLT_FAILURE;
    if (fscanf(f, "%d", &flat->room_cnt) != 1)
        return FLT_FAILURE;
    if (fscanf(f, "%d", (int *)&flat->is_new) != 1)
        return FLT_FAILURE;
    if (flat->is_new)
    {
        if (fscanf(f, "%d\n", (int *)&flat->type.is_trim) != 1)
            return FLT_FAILURE;
    }
    else
    {
        if (fscanf(f, "%d", &flat->type.old.year) != 1)
            return FLT_FAILURE;
        if (fscanf(f, "%d", &flat->type.old.owner_cnt) != 1)
            return FLT_FAILURE;
        if (fscanf(f, "%d", &flat->type.old.lst_rsdnt_cnt) != 1)
            return FLT_FAILURE;
        if (fscanf(f, "%d\n", (int *)&flat->type.old.were_anmls) != 1)
            return FLT_FAILURE;
    }
    flat->price = flat->price_per_m2 * flat->area;
    return FLT_SUCCESS;
}

void draw_table(flat_t *flats, int count)
{
    printf("_______________________________________________"
           "____________________________________________\n");
    printf("|%16s|%5s|%8s|%5s|%4s|%7s|%8s|%6s|%14s|%7s|\n",
           "adress", "area", "$ per m2", "rooms", "new", "trimmed",
           "year", "owners", "last residents", "animals");
    printf("|________________|_____|________|_____|____|_______"
           "|________|______|______________|_______|\n");
    for (int i = 0; i < count; i++)
        output_line(flats + i);
    printf("|________________|_____|________|_____|____|_______"
           "|________|______|______________|_______|\n");
}

void output_line(flat_t *flat)
{
    printf("|%16s|%5d|%8d|%5d|",
           flat->adr, flat->area, flat->price_per_m2,
           flat->room_cnt);
    if (flat->is_new)
        printf("%4s|%7s|       -|     -|             -|      -|\n", "yes",
               flat->type.is_trim ? "yes" : "no");
    else
        printf("%4s|      -|%8d|%6d|%14d|%7s|\n", "no",
               flat->type.old.year, flat->type.old.owner_cnt,
               flat->type.old.lst_rsdnt_cnt,
               flat->type.old.were_anmls ? "yes" : "no");
}

int delete_by_index(FILE *f_in, FILE *f_out, int index)
{
    int count;
    flat_t *flats;
    if (fscanf(f_in, "%d\n", &count) != 1 || count < 1)
        return FLT_FAILURE;
    if (index >= count)
        return FLT_FAILURE;
    flats = malloc(count * sizeof(flat_t));
    if (get_array_from_file(f_in, flats, count))
    {
        free(flats);
        return FLT_FAILURE;
    }
    memmove(flats + index, flats + index + 1, count - index - 1);
    write_in_file(f_out, flats, count - 1);
    free(flats);
    return FLT_SUCCESS;
}

int append_to_file(FILE *f_in, FILE *f_out)
{
    int count;
    flat_t *flats;
    if (fscanf(f_in, "%d\n", &count) != 1 || count < 1)
        return FLT_FAILURE;
    flats = malloc((count + 1) * sizeof(flat_t));
    if (get_array_from_file(f_in, flats, count))
    {
        free(flats);
        return FLT_FAILURE;
    }
    if (append_to_array(flats, count))
    {
        free(flats);
        return FLT_FAILURE;
    }
    write_in_file(f_out, flats, count + 1);
    free(flats);
    return FLT_SUCCESS;
}
int append_to_array(flat_t *flats, int count)
{
    if (get_from_stream(flats + count))
        return FLT_FAILURE;
    return FLT_SUCCESS;
}
