#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int init()
{
    return 0;
}

int empty_line(char *str)
{
    return 0;
}

int valid_command(char *str)
{
    return 0;
}

int validate_line(char *str)
{
    int ret = 0;
    if (!(empty_line(str) || valid_command(str)))
    {
        fprintf(stderr, "Invalid command\n");
        ret = 1;
    }
    return ret;
}

int read_byte(unsigned int ddddd)
{
    return 0;
}

int write_byte(unsigned int ddddd, char vvv)
{
    return 0;
}

int main(int argc, char *argv[])
{

    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    size_t read;

    fp = fopen("tests/prueba1.mem", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1)
    {
        validate_line(line);
        get_command(line);
        printf("%s", line);
    }

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);

    return 0;
}