#include <stdlib.h>
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

int _empty_line(char *str) {
    return strlen(str) == 0;
}

int _valid_command(char *str) {
    return 0;
}

int _validate_operation(char *str) {
    int ret = 0;
    if (!(_empty_line(str) || _valid_command(str))) {
        ret = 1;
    }
    return ret;
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
            command->address = _get_address(split_line, array_size, 1);
            break;
        case 'W':
            command->address = _get_address(split_line, array_size, 1);
            command->value = _get_value(split_line, array_size, 2);
            break;

        default:
            ret = -1;
            break;
    }
    return ret;
}

