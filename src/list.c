#include "list.h"

list_t *create_list(int value) 
{
    list_t *list = malloc(sizeof(list_t));
    list->value = value;
    list->next = NULL;
    return list;
}

void insert(list_t **list, int value, int index) 
{
    list_t *new_list = malloc(sizeof(list_t));
    if (!new_list) exit(EXIT_FAILURE);
    list_t *tmp = NULL;
    list_t *current = *list;
    list_t *elem = malloc(sizeof(list_t));
    if (!elem) exit(EXIT_FAILURE);
    elem->value = value;
    elem->index = index;
    while(current && current->value < value) 
    {
        tmp = current;
        current = current->next;
    }
    elem->next = current;
    if (tmp)
    {
        tmp->next = elem;
    }
    else
    {
        *list = elem;
    }
}

list_t *pop(list_t **list) 
{
    list_t *value = (*list);
    list_t *tmp = (*list)->next;
    *list = tmp;
    return value;
}

void print_list(list_t *list, bool print_index) 
{
    while (list != NULL) {
        printf("%d ", list->value);
        if (print_index) {
            printf("(%d) ", list->index);
        }
        list = list->next;
    }
}

void free_list(list_t **list)
{
    list_t *tmp;
    while(*list)
    {
        tmp = (*list)->next;
        free(*list);
        *list = tmp;
    }
}