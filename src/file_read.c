// File: file_read.c
#include <stdio.h>
#include <stdlib.h>

#include "file_read.h"

int read_file(char* filename) {
    FILE *file;
    char ch;

    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return EXIT_FAILURE;
    }

    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    putchar('\n');

    fclose(file);
    return EXIT_SUCCESS;
}