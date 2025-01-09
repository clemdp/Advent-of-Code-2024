#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list_struct {
    struct list_struct *next;
    int value;
    int index;
} list_t;

// list_t *list_one = NULL;
// list_t *list_two = NULL;

list_t *create_list(int value);
void insert(list_t **list, int value, int index);
list_t *pop(list_t **list);
list_t *get_min(list_t *list);
int occurences(list_t *list, int value);
void print_list(list_t *list, bool print_index);
void free_list(list_t **list);