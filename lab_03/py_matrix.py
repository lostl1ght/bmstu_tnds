import random


def gen_sparese_matrix(a, rows, cols):
    for i in range(rows):
        for j in range(cols):
            if random.randint(0, 3) == 0:
                a[i][j] = random.randint(-15, 15)


def print_matrix(a):
    for i in range(len(a)):
        for j in range(len(a[0])):
            print("{:3d}".format(a[i][j]), end=" ")
        print()


def sum_matrices(sum, a, b, rows, cols):
    for i in range(rows):
        for j in range(cols):
            sum[i][j] = a[i][j] + b[i][j]


def gen_vectors(m, a, ia, ja, rows, cols, non_zero):
    len_a = 0
    for j in range(cols):
        flg = False
        for i in range(rows):
            if m[i][j] != 0:
                if flg == False:
                    flg = True
                    ja[j] = len_a
                a[len_a] = m[i][j]
                ia[len_a] = i
                len_a += 1
        if flg == False:
            ja[j] = len_a
    ja[cols] = non_zero


def count_non_zero(m, rows, cols):
    count = 0
    for i in range(rows):
        for j in range(cols):
            if m[i][j] != 0:
                count += 1
    return count


rows = 5
cols = 5
m1 = [[0, 0, -15, 0, 0], [0, 8, 0, 14, 0], [-4, 0, 0, -2, 0],[-14, 0, 0, 7, 0], [0, 0, 0, 0, 0,]]

non_zero1 = count_non_zero(m1, rows, cols)
a1 = [0] * non_zero1
ia1 = [0] * non_zero1
ja1 = [0] * (cols + 1)

gen_vectors(m1, a1, ia1, ja1, rows, cols, non_zero1)


