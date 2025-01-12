#include "main.h"
#include "day3.h"

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
    else if (day == 3)
    {
        res = day3(filename, part);
    }

    printf("Result: %d\n", res);

    return EXIT_SUCCESS;
}

int day1(char *filename, int part)
{
    int result = 0;

    if (part == 1)
    {
        result = part_one(filename);
    }
    else
    {
        result = part_two(filename);
    }

    return result;
}