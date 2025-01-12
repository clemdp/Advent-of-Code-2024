#include <regex.h>

#include "day3.h"

static void find_mult(char *line);

static unsigned long long sum;
static unsigned long tmp;
static bool check_enable;

int day3(char *filename, int part)
{
    sum = 0;
    if (part == 1)
    {
        check_enable = false;
    }
    else 
    {
        check_enable = true;
    }

    read_file(filename, find_mult);
    return sum;
}

void find_mult(char *line)
{
    printf("line: %s\n", line);
    regex_t regex;
    regmatch_t matches[3];
    int a, b, mult;
    char *cursor = line;
    bool enabled = true;
    tmp = 0;

    // Compile the regular expression
    if (regcomp(&regex, "don't\\(\\)|do\\(\\)|mul\\(([0-9]{1,3}),([0-9]{1,3})\\)", REG_EXTENDED) != 0)
    {
        printf("Could not compile regex\n");
        return;
    }

    // Execute the regular expression
    while (regexec(&regex, cursor, 3, matches, 0) == 0)
    {
        // Extract the matched numbers
        char num1[10], num2[10];
        // char substring[10];

        // snprintf(substring, matches[0].rm_eo - matches[0].rm_so + 1, "%s", cursor + matches[0].rm_so);
        // printf("substring: %s\n", substring);
        
        if (strncmp(cursor + matches[0].rm_so, "don't()", matches[0].rm_eo - matches[0].rm_so) == 0)
        {
            printf("Disabled\n");
            enabled = false;
        }
        else if (strncmp(cursor + matches[0].rm_so, "do()", matches[0].rm_eo - matches[0].rm_so) == 0)
        {
            printf("Enabled\n");
            enabled = true;
        }

        snprintf(num1, matches[1].rm_eo - matches[1].rm_so + 1, "%s", cursor + matches[1].rm_so);
        snprintf(num2, matches[2].rm_eo - matches[2].rm_so + 1, "%s", cursor + matches[2].rm_so);
        a = atoi(num1);
        b = atoi(num2);

        if (!check_enable || enabled)
        {
            mult = a * b;
            tmp = tmp + mult;
            printf("Found multiplication: %d * %d = %d\n", a, b, mult);
            printf("tmp = %lu\n", tmp);
        }
        
        
        // Move the cursor forward
        cursor += matches[0].rm_eo;
    }
    sum += tmp;
    printf(" -- SUM : %llu --\n", sum);

    // Free the compiled regular expression
    regfree(&regex);
}