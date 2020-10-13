#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void merge(flat_t *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    flat_t left[n1], right[n2];

    for (i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (left[i].area <= right[j].area)
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(flat_t *arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int merge_sort_no_keys(FILE *f_in, FILE *f_out)
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
    merge_sort(flats, 0, count - 1);
    write_in_file(f_out, flats, count);
    free(flats);
    return FLT_SUCCESS;
}
