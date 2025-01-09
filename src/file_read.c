#include "file_read.h"

int read_file(char* filename, list_t **list_one, list_t **list_two) 
{
    FILE *file;
    char line[128];
    list_t *l1 = NULL;
    list_t *l2 = NULL;

    file = fopen(filename, "r");
    if (file == NULL) 
    {
        fprintf(stderr, "Error opening file %s\n", filename);
        return EXIT_FAILURE;
    }

    while (fgets(line, 128, file))
    {
        char *first_number = strtok(line, " \t");
        char *second_number = strtok(NULL, " \t");
        int i1 = get_number_from_string(first_number);
        int i2 = get_number_from_string(second_number);

        if (l1 == NULL)
        {
            l1 = create_list(i1);
        }
        else
        {
            insert(&l1, i1, 0);
        }
        if (l2 == NULL)
        {
            l2 = create_list(i2);
        }
        else
        {
            insert(&l2, i2, 0);
        }
    }

    putchar('\n');

    fclose(file);

    (*list_one) = l1;
    (*list_two) = l2;

    return EXIT_SUCCESS;
}

int get_number_from_string(char *string)
{
    int number = 0;
    int i = 0;

    for (i = 0; string[i] != '\0'; i++)
    {
        if (string[i] >= '0' && string[i] <= '9')
        {
            number = number * 10 + (string[i] - '0');
        }
    }

    return number;
}