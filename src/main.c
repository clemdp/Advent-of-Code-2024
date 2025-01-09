#include "main.h"

int main(int argc, char* argv[]) {
    char *filename;
    int day = 0;
    int part = 0;
    int res = 0;

    if (argc < 4) {
        fprintf(stderr, "Usage: %s <filename> <day> <part>\n", argv[0]);
        return EXIT_FAILURE;
    } else {
        filename = argv[1];
        day = atoi(argv[2]);
        part = atoi(argv[3]);
    }
    
    if (day == 1)
    {
        res = day1(filename, part);
    }

    printf("Result: %d\n", res);

    return EXIT_SUCCESS;
}

int day1(char *filename, int part)
{
    list_t *list_one = NULL;
    list_t *list_two = NULL;
    int result = 0;

    read_file(filename, &list_one, &list_two);

    if (part == 1)
    {
        result = part_one(list_one, list_two);
    }
    else
    {
        result = part_two(list_one, list_two);
    }

    free_list(&list_one);
    free_list(&list_two);

    return result;
}