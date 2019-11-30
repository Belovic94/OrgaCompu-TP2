#ifndef ORGACOMPU_TP2_COMMANDPARSER_H
#define ORGACOMPU_TP2_COMMANDPARSER_H

#include "command.h"

int parse(char *split_line, command_t *command);
int empty_line(char *str);

#endif //ORGACOMPU_TP2_COMMANDPARSER_H
