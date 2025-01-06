#include "main.h"

int main(int argc, char* argv[]) {
    char *filename;
    list_t *list_one = NULL;
    list_t *list_two = NULL;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    } else {
        filename = argv[1];
    }
    
    read_file(filename, &list_one, &list_two);
    
    // printf("(In main.c) List 1: ");
    // print_list(list_one, false);
    // printf("\n(In main.c) List 2: ");
    // print_list(list_two, false);
    // printf("\n");

    int result = part_one(list_one, list_two);
    printf("Result: %d\n", result);

    free_list(&list_one);
    free_list(&list_two);

    return 0;
}