#include "day5.h"
#include "file_read.h"
#include "list.h"

static int part_one(char *filename);
static int part_two(char *filename);
static void default_method(char *line);

int day5(char *filename, int part)
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

static int part_one(char *filename)
{
    int result = 0;

    read_file(filename, default_method);

    return result;
}

static int part_two(char *filename) 
{
    int result = 0;

    read_file(filename, default_method);

    return result;
}

static void default_method(char *line)
{
    printf("%s\n", line);
}
