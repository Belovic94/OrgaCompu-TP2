#include "commandParser.h"
#include "string.h"
#include "strutil.h"

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

int _validate_address(int address) {
    return 0;
}

int _validate_data(char* data) {
    return 0;
}

int parse(char *line, command_t *command) {
    char** split_line = split(line, ' ');
    return 0;
}
