#include <stdio.h>
#include <stdlib.h>

#include "main.h"

int main(int argc, char* argv[]) {
    char *filename;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    } else {
        filename = argv[1];
    }
    
    read_file(filename);
    return 0;
}