#ifndef SEARCH_H
#define SEARCH_H

#include <stdio.h>

#include "macro.h"
#include "tree_utils.h"
#include "list_utils.h"
#include "hash_utils.h"
#include "tick.h"

// #include "macro.h"

// #include "tree_utils.h"
// #include "list_utils.h"
// #include "hash_utils.h"
// #include "tick.h"

char **fill_words(FILE *f);

void free_words(char **words, unsigned long flen);

int search_tree(char *to_find, tree_node root);

double search_tree_av(tree_node root, char **words, unsigned long flen);

int search_hashtable(char *to_find, list_t *hash_list, int n, int (*hash)(char *, int));

double search_hashtable_av(list_t *hash_list, int n, int (*hash)(char *, int), char **words, unsigned long flen);

int search_file(char *to_find, FILE *f);

double search_file_av(FILE *f, char **words, unsigned long flen);

#endif