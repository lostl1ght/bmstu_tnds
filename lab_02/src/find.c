#include "find.h"

int find_in_file(FILE *f_in, FILE *f_out)
{
    int count;
    flat_t *flats;
    int *ind;
    int min, max, count_val;
    printf("Enter minimum price: ");
    if (scanf("%d", &min) != 1 || min < 0)
        return FLT_FAILURE;
    printf("Enter maximum price: ");
    if (scanf("%d", &max) != 1 || max < 0 || max < min)
        return FLT_FAILURE;
    if (fscanf(f_in, "%d\n", &count) != 1 || count < 1)
        return FLT_FAILURE;
    flats = malloc(count * sizeof(flat_t));
    ind = malloc(count * sizeof(int));
    if (get_array_from_file(f_in, flats, count))
    {
        free(ind);
        free(flats);
        return FLT_FAILURE;
    }
    count_val = get_ind(flats, ind, count, min, max);
    if (!count_val)
    {
        free(flats);
        free(ind);
        return -1;
    }
    else
    {
        write_in_file_by_ind(f_out, flats, ind, count_val);
    }
    free(flats);
    free(ind);
    return FLT_SUCCESS;
}

int get_ind(flat_t *flats, int *ind, int count, int min, int max)
{
    int count_val = 0;
    for (int i = 0; i < count; i++)
        if (!flats[i].is_new && !flats[i].type.old.were_anmls && flats[i].room_cnt == 2)
            if (flats[i].price >= min && flats[i].price <= max)
            {
                ind[count_val] = i;
                count_val++;
            }
    return count_val;
}
