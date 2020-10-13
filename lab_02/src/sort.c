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

void insertion_sort(flat_t *arr, int count)
{
    for (int i = 1; i < count; i++)
    {
        int cur = i;
        while (cur > 0 && arr[cur - 1].area > arr[cur].area)
        {
            flat_t tmp = arr[cur - 1];
            arr[cur - 1] = arr[cur];
            arr[cur] = tmp;
            cur--;
        }
    }
}

int insert_sort_no_keys(FILE *f_in, FILE *f_out)
{
    int count;
    flat_t *flats;
    if (fscanf(f_in, "%d\n", &count) != 1 || count < 1)
        return FLT_FAILURE;
    flats = malloc(count * sizeof(flat_t));
    if (get_array_from_file(f_in, flats, count))
    {
        free(flats);
        return FLT_FAILURE;
    }
    insertion_sort(flats, count);
    write_in_file(f_out, flats, count);
    free(flats);
    return FLT_SUCCESS;
}

int merge_sort_no_keys(FILE *f_in, FILE *f_out)
{
    int count;
    flat_t *flats;
    if (fscanf(f_in, "%d\n", &count) != 1 || count < 1)
        return FLT_FAILURE;
    flats = malloc(count * sizeof(flat_t));
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

void merge_keys(key_t *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    key_t left[n1], right[n2];

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

void merge_sort_keys(key_t *arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        merge_sort_keys(arr, l, m);
        merge_sort_keys(arr, m + 1, r);

        merge_keys(arr, l, m, r);
    }
}

void insertion_sort_keys(key_t *arr, int count)
{
    for (int i = 1; i < count; i++)
    {
        int cur = i;
        while (cur > 0 && arr[cur - 1].area > arr[cur].area)
        {
            key_t tmp = arr[cur - 1];
            arr[cur - 1] = arr[cur];
            arr[cur] = tmp;
            cur--;
        }
    }
}

int merge_sort_with_keys(FILE *f_in, FILE *f_out)
{
    int count;
    flat_t *flats;
    key_t *keys;
    if (fscanf(f_in, "%d\n", &count) != 1 || count < 1)
        return FLT_FAILURE;
    flats = malloc(count * sizeof(flat_t));
    keys = malloc(count * sizeof(key_t));
    if (get_array_from_file(f_in, flats, count))
    {
        free(flats);
        free(keys);
        return FLT_FAILURE;
    }
    get_key_array(flats, keys, count);
    merge_sort_keys(keys, 0, count - 1);
    write_in_file_by_keys(f_out, flats, keys, count);
    free(flats);
    free(keys);
    return FLT_SUCCESS;
}

void get_key_array(flat_t *flats, key_t *keys, int count)
{
    for (int i = 0; i < count; i++)
    {
        keys[i].index = i;
        keys[i].area = flats[i].area;
    }
}

int insert_sort_with_keys(FILE *f_in, FILE *f_out)
{
    int count;
    flat_t *flats;
    key_t *keys;
    if (fscanf(f_in, "%d\n", &count) != 1 || count < 1)
        return FLT_FAILURE;
    flats = malloc(count * sizeof(flat_t));
    keys = malloc(count * sizeof(key_t));
    if (get_array_from_file(f_in, flats, count))
    {
        free(flats);
        free(keys);
        return FLT_FAILURE;
    }
    get_key_array(flats, keys, count);
    insertion_sort_keys(keys, count);
    write_in_file_by_keys(f_out, flats, keys, count);
    free(flats);
    free(keys);
    return FLT_SUCCESS;
}
