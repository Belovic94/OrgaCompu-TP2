#include <stdlib.h>
#include <stdio.h>
#include "commandParser.h"
#include "string.h"
#include "strutil.h"

#define INVALID_ADDRESS 65536

int _validate_value(int value) {
    if (value < 256 && value >= 0) {
        return 0;
    }
    return -1;
}

int _validate_address(int address) {
    if (address < INVALID_ADDRESS && address >= 0) {
        return 0;
    }
    fprintf(stdout, "Invalid address\n");
    return -1;
}

int _assign_address(char **split_line, int array_size, unsigned int* address) {
    if (array_size > 1) {
        char *address_line = split_line[1];
        if (split_line[0][0] == 'W') {
            strncpy(address_line, split_line[1], strlen(split_line[1]) - 1);
        }
        int address_aux = atoi(address_line);
        if (_validate_address(address_aux) == 0) {
            *address = (unsigned int) address_aux;
            return 0;
        }
    }
    return -1;
}

int _assign_value(char **split_line, int array_size, unsigned char* value){
    if(array_size > 2) {
        int value_aux = atoi(split_line[2]);
        if (_validate_value(value_aux) == 0) {
            *value = (unsigned  char) value_aux;
            return 0;
        }
    }
    return -1;
}

int empty_line(char *str) {
    return strcmp(str, "\n") == 0 || strcmp(str,"\r\n") == 0;
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
            if (_assign_address(split_line, array_size, &command->address) != 0) {
                ret = -1;
            }
            break;
        case 'W':
            if (_assign_address(split_line, array_size, &command->address) != 0
            || _assign_value(split_line, array_size, &command->value) != 0) {
                ret = -1;
            }
            break;

        default:
            ret = -1;
            break;
    }
    free_split(split_line);
    return ret;
}

