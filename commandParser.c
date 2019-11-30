#include <stdlib.h>
#include <stdio.h>
#include "commandParser.h"
#include "string.h"
#include "strutil.h"

unsigned int _get_address(char **split_line, int array_size){
    if(array_size > 1){
        char* address = split_line[1];
        if(split_line[0][0] == 'W'){
            strncpy(address, split_line[1], strlen(split_line[1])-1);
        }
        return atoi(address);
    }
    return -1;
}

unsigned char _get_value(char **split_line, int array_size){
    if(array_size > 2) {
        return atoi(split_line[2]);

    }
}

int empty_line(char *str) {
    int aux = strcmp(str, "\n") == 0 || strcmp(str,"\r\n") == 0;
    return aux;
}

int _validate_address(char address) {
    return 0;
}

int _validate_value(char* value) {
    return 0;
}

int parse(char *line, command_t *command){
    int ret = 0;
    int array_size;
    char **split_line = split(line, ' ', &array_size);
    char operation = split_line[0][0];
    command->operation = operation;
    switch (operation) {
        case 'F':
            break;
        case 'M':
            break;
        case 'R':
            command->address = _get_address(split_line, array_size);
            break;
        case 'W':
            command->address = _get_address(split_line, array_size);
            command->value = _get_value(split_line, array_size);
            break;

        default:
            ret = -1;
            break;
    }
    return ret;
}

