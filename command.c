#include "command.h"
#include "commandParser.h"

int command_create(command_t* self, char* line){
    return parse(line, self);
}

void command_destroy(command_t* self){

}
