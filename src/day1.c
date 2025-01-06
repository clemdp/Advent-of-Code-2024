#include "day1.h"

int part_one(list_t *list_one, list_t *list_two) 
{

    int result = 0;
    int min1 = 0;
    int min2 = 0;

    while (list_one != NULL && list_two != NULL) 
    {
        min1 = pop(&list_one)->value;
        min2 = pop(&list_two)->value;
        printf("min1: %d, min2: %d\n", min1, min2);

        int dist = abs(min1 - min2);
        printf("dist: %d\n", dist);

        result = result + dist;
    }

    return result;
}

int part_two(list_t *list_one, list_t *list_two) 
{

    int result = 0;
    
    list_t *new_list = create_list(0);

    while (list_one != NULL) 
    {
        list_t *tmp = pop(&list_one);
        int value = tmp->value;
        int count = 0;

        if (new_list == NULL || new_list->value != value) 
        {
            insert(&new_list, value, 0);
        }

        while (list_two != NULL) 
        {
            if (list_two->value == value) 
            {
                count++;
                pop(&list_two);
                // insert(&new_list, value, 0);
            }
            else
            {
                break;
            }
        }

        insert(&new_list, value, count);
    }

    return result;
}
