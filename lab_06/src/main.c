#include "tree_utils.h"
#include "list_utils.h"
#include "hash_utils.h"
#include "search_utils.h"
#include "tick.h"

int main(int argc, char *argv[])
{
    printf("Trees, hash and whatever...\n");

    FILE *f = fopen(argv[1], "r");

    if (f == NULL || argc != 2)
    {
        printf("Wrong file.\n");
        return FILE_ERROR;
    }

    if (fgetc(f) == EOF)
    {
        printf("File is empty\n");
        return FILE_ERROR;
    }

    rewind(f);

    char **words = fill_words(f);
    unsigned long flen = file_len(f);
    tree_node *root = NULL;

    uint64_t time = tick();
    fill_tree(&root, f);
    time = tick() - time;

    printf("Binary tree from files:\n");
    print_tree(root, 0);
    printf("Tree building time: %ld\n\n", time);

    int unique;
    time = tick();
    root = balance_tree(root, &unique);
    time = tick() - time;
    printf("Balanced binary tree:\n");
    print_tree(root, 0);
    printf("Tree balancing time: %ld\n\n", time);

    int n = next_prime(file_len(f));
    list_t *hash_list = calloc(n, sizeof(list_t));
    int cmpr, desired_cmpr;

    int (*hash)(char *, int);

    time = tick();
    unsafe_hash("chill", 10);
    time = tick() - time;
    printf("Simple hash generating time: %ld.\n", time);

    time = tick();
    safe_hash("chill", 10);
    time = tick() - time;
    printf("Better hash generating time: %ld\n", time);

    hash = &unsafe_hash;
    time = tick();
    cmpr = build_hash_table(&hash_list, n, f, hash);
    time = tick() - time;

    printf("\nSimple hash table:");
    print_hash_table(hash_list, n);
    printf("Max clash count: %d\n", cmpr);
    printf("Hash table building time: %ld\n\n", time);

    printf("\nEnter max clash count: ");
    int ec = scanf("%d", &desired_cmpr);
    if (ec != 1 || desired_cmpr < 1)
    {
        printf("Wrong number.\n");
        return VAL_ERROR;
    }

    if (cmpr > desired_cmpr)
    {
        while (cmpr != desired_cmpr)
        {
            free_list_arr(hash_list, n);
            n = next_prime(n);
            hash_list = calloc(n, sizeof(list_t));

            hash = &safe_hash;
            time = tick();
            cmpr = build_hash_table(&hash_list, n, f, hash);
            time = tick() - time;
        }
        printf(
            "\nBetter hash table:");
        print_hash_table(hash_list, n);
        printf("Max clash count: %d\n", cmpr);
        printf("Hash table building time: %ld\n\n", time);
    }
    else
    {
        printf("No need to remake the table.");
    }

    char to_find[STR_SIZE];
    printf("\nEnter a word to find: ");
    scanf("%s", to_find);

    int depth = 0;
    int vrtxs = 0;
    int cmprs = 0;
    tree_node *root2 = NULL;
    fill_tree(&root2, f);
    time = tick();
    ec = search_tree(to_find, *root2);
    time = tick() - time;
    tree_depth(root2, &vrtxs, &cmprs, depth);
    if (ec > 0)
    {
        printf("\nBinary tree search\n");
        printf("Word \"%s\" searching time: %ld\n"
               "Average searching time: %lf\n"
               "Memory size: %ld\n"
               "Comapres count: %d\n"
               "Average comapres count: %f.\n",
               to_find, time, search_tree_av(*root2, words, flen),
               unique * sizeof(tree_node), ec,
               (double)cmprs / vrtxs);
    }
    else
    {
        printf("Word \"%s\" wasn't found.\n", to_find);
        return VAL_ERROR;
    }
    free_tree(root2);

    depth = 0;
    vrtxs = 0;
    cmprs = 0;
    time = tick();
    ec = search_tree(to_find, *root);
    time = tick() - time;
    tree_depth(root, &vrtxs, &cmprs, depth);
    if (ec > 0)
    {
        printf("\nBalanced binaty tree search\n");
        printf("Word \"%s\" searching time: %ld\n"
               "Average searching time: %lf\n"
               "Memory size: %ld\n"
               "Comapres count: %d\n"
               "Average comapres count: %f.\n",
               to_find, time, search_tree_av(*root, words, flen),
               unique * sizeof(tree_node), ec,
               (double)cmprs / vrtxs);
    }
    else
    {
        printf("Word \"%s\" wasn't found.\n", to_find);
        return VAL_ERROR;
    }
    free_tree(root);

    time = tick();
    ec = search_hashtable(to_find, hash_list, n, hash);
    time = tick() - time;
    if (ec > 0)
    {
        printf("\nHash table search\n");
        printf("Word \"%s\" searching time: %ld\n"
               "Average searching time: %lf\n"
               "Memory size: %ld\n"
               "Comapres count: %d\n"
               "Average comapres count: %f.\n",
               to_find, time / 4, search_hashtable_av(hash_list, n, hash, words, flen),
               (n + unique - list_occupation(hash_list, n)) * sizeof(list_t) + sizeof(list_t *), ec,
               (double)(1 + desired_cmpr) / 2);
    }
    else
    {
        printf("Word \"%s\" wasn't found.\n", to_find);
        return VAL_ERROR;
    }
    free_list_arr(hash_list, n);

    time = tick();
    ec = search_file(to_find, f);
    time = tick() - time;
    if (ec > 0)
    {
        printf("\nFile search\n");
        printf("Word \"%s\" searching time: %ld\n"
               "Average searching time: %lf\n"
               "Memory size: %u\n"
               "Comapres count: %d\n"
               "Average comapres count: %f.\n",
               to_find, time, search_file_av(f, words, flen),
               fbytes(f), ec, (double)file_len(f) / 2);
    }
    else
    {
        printf("Word \"%s\" wasn't found.\n", to_find);
        return VAL_ERROR;
    }

    fclose(f);

    return OK;
}