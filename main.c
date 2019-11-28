#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileReader.h"
#include "commandParser.h"
#include "cache.h"
#include "mainMemory.h"
#include "commandExecutor.h"

cache_t* cache;
main_memory_t* mainMemory;

int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen(argv[1], "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    filereader_t file;
    filereader_create(&file, fp);
    cache_create();
    main_memory_create();
    char *line = NULL;
    while (filereader_next(&file, line) == EXIT_SUCCESS) {
        command_t command;
        if (command_create(&command, line) != 0) {
            fprintf(stdout, "Invalid command");
            continue;
        }
        command_executor_execute(&command);
        command_destroy(&command);
        printf("%s", line);
    }
    exit(EXIT_SUCCESS);
}