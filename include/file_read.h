#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "list.h"

int read_file(char* filename, list_t **list_one, list_t **list_two);
int get_number_from_string(char *string);