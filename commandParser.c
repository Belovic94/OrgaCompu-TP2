#include <stdlib.h>
#include "commandParser.h"
#include "string.h"
#include "strutil.h"

char _get_operation(char* op);
unsigned  int _get_address(char** address, int array_size, int pos);
char _get_value(char** value, int array_size, int pos);

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

int parse(char *line, command_t *command) {
    int ret = 0;
    size_t array_size;
    char** split_line = split(line, ' ', &array_size);
    char operation = _get_operation(split_line[0]);
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

