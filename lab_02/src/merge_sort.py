import random as rd

a = []
for i in range(20):
    x = rd.randint(-100, 100)
    a += [x]


def my_merge_sort(a):
    d = [0] * len(a)
    if len(a) > 2:
        b = merge_sort(a[: len(a) // 2])
        c = merge_sort(a[len(a) // 2 :])
        i_b = 0
        i_c = 0
        i_d = 0
        while i_b < len(b) and i_c < len(c):
            if b[i_b] < c[i_c]:
                d[i_d] = b[i_b]
                i_b += 1
            else:
                d[i_d] = c[i_c]
                i_c += 1
            i_d += 1
        if i_b == len(b):
            for i in range(i_d, len(d)):
                d[i] = c[i_c]
                i_c += 1
        else:
            for i in range(i_d, len(d)):
                d[i] = b[i_b]
                i_b += 1
        return d
    elif len(a) == 2:
        if a[0] > a[1]:
            a[0], a[1] = a[1], a[0]
        return a
    else:
        return a

# Python program for implementation of MergeSort
def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2  # Finding the mid of the array
        l = arr[:mid]  # Dividing the array elements
        r = arr[mid:]  # into 2 halves

        merge_sort(l)  # Sorting the first half
        merge_sort(r)  # Sorting the second half

        i = j = k = 0

        # Copy data to temp arrays L[] and R[]
        while i < len(l) and j < len(r):
            if l[i] < r[j]:
                arr[k] = l[i]
                i += 1
            else:
                arr[k] = r[j]
                j += 1
            k += 1

        # Checking if any element was left
        while i < len(l):
            arr[k] = l[i]
            i += 1
            k += 1

        while j < len(r):
            arr[k] = r[j]
            j += 1
            k += 1


print(a)
merge_sort(a)
print(a)