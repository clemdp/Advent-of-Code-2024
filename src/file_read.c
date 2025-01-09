#include "file_read.h"

int read_file(char *filename, void (*my_func)(char *line))
{
    FILE *file;
    char line[128];

    file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file %s\n", filename);
        return EXIT_FAILURE;
    }

    while (fgets(line, 128, file))
    {
        if (my_func != NULL)
        {
            my_func(line);
        }
    }

    fclose(file);
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