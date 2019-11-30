#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileReader.h"
#include "commandParser.h"
#include "cache.h"
#include "mainMemory.h"
#include "commandExecutor.h"

int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen(argv[1], "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    filereader_t file;
    filereader_create(&file, fp);
    if (cache_create() != 0 || main_memory_create() != 0) {
        filereader_destroy(&file);
        exit(EXIT_SUCCESS);
    }
    char *line = NULL;
    while (filereader_next(&file, &line) != -1) {
        line[strlen(line) -1] = '\0';
        command_t command;
        if (command_create(&command, line) != 0) {
            fprintf(stdout, "Invalid command");
            continue;
        }
        command_executor_execute(&command);
        printf("%s \n", line);
    }
    cache_destroy();
    main_memory_destroy();
    filereader_destroy(&file);
    exit(EXIT_SUCCESS);
}