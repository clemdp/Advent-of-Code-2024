#include <stdio.h>
#include <stdlib.h>

#include "day1.h"
#include "day2.h"

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
    else if (day == 2)
    {
        res = day2(filename, part);
    }

    printf("\nResult: %d\n", res);

    return EXIT_SUCCESS;
}
