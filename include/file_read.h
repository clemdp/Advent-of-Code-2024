#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int read_file(char *filename, void (*my_fun)(char *line));
int get_number_from_string(char *string);