#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileReader.h"
#include "commandParser.h"

int init()
{
    return 0;
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
    fp = fopen(argv[1], "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    filereader_t file;
    filereader_create(&file, fp);
    char *line = NULL;

    while (filereader_next(&file, line) == EXIT_SUCCESS) {
        command_t command;
        if (command_create(&command, line) != 0) {
            fprintf(stdout, "Invalid command");
        }
        printf("%s", line);
    }
    exit(EXIT_SUCCESS);
}