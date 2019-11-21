#ifndef ORGACOMPU_TP2_COMMAND_H
#define ORGACOMPU_TP2_COMMAND_H
typedef struct {
    char* operation;
    unsigned int first_argument;
    char second_argument;
}command_t;

int command_create(command_t* self, char* line);

void command_destroy(command_t* self);

char command_execute(command_t* self);

#endif //ORGACOMPU_TP2_COMMAND_H
