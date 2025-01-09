#include <stdbool.h>

#include "day2.h"

static int part_one(char *filename);
static int part_two(char *filename);
static void line_callback(char *line);
static bool is_safe(char *line);

static int count_safe = 0;
static int tolerance = 1;

int day2(char *filename, int part)
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
    // int count = 0;
    count_safe = 0;
    tolerance = 0;

    read_file(filename, line_callback);

    return count_safe;
}

static int part_two(char *filename)
{
    count_safe = 0;
    tolerance = 1;

    read_file(filename, line_callback);
    
    return count_safe;
}

static void print_line(char *line)
{
    char *str = "%s";
    if (line[strlen(line) - 1] != '\n')
    {
        str = "%s\n";
    }
    printf(str, line);

}

static void line_callback(char *line)
{
    print_line(line);
    
    if (is_safe(line))
    {
        count_safe += 1;
        printf("### IS SAFE ###\n");
    }
    else
    {
        printf("### UNSAFE ###\n");
    }
}

static bool is_safe(char *line)
{
    int i1, i2, diff, last_diff;
    int sign_diff, sign_last;
    int error = 0;
    char *nb = strtok(line, " ");
    bool first = true;

    i1 = get_number_from_string(nb);
    nb = strtok(NULL, " ");

    while (nb != NULL)
    {
        i2 = get_number_from_string(nb);
        diff = i2 - i1;
        printf("i1 = %d, i2 = %d, diff = %d\n", i1, i2, diff);

        sign_diff = (diff > 0) ? 1 : 0;
        sign_last = (last_diff > 0) ? 1 : 0;

        if (abs(diff) > 3 || diff == 0)
        {
            // if (error >= tolerance)
            // {
                // return false;
            // }
            // else
            // {
                // error += 1;
            // }
            error += 1;
        }
        else if ((!first && sign_diff != sign_last))
        {
            error += 1;
        }
        else
        {
            i1 = i2;
            last_diff = diff;
        }

        if (error > tolerance)
        {
            return false;
        }

        #if 0
        else if (!first && sign_diff != sign_last)
        {
            if (error >= tolerance)
            {
                return false;
            }
            else
            {
                error += 1;
            }
        }

        i1 = i2;
        #endif
        nb = strtok(NULL, " ");
        first = false;
    }

    return true;
}