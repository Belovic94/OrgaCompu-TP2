#ifndef ORGACOMPU_TP2_COMMANDEXECUTOR_H
#define ORGACOMPU_TP2_COMMANDEXECUTOR_H

#include "cache.h"
#include "mainMemory.h"
#include "command.h"

typedef struct {
    cache_t* cache;
    main_memory_t* mainMemory;
}command_executor_t;

void command_executor_create(command_executor_t* self, cache_t* cache, main_memory_t* mainMemory);

void command_executor_destroy(command_executor_t* self);

void command_executor_execute(command_executor_t* self, command_t* command);

#endif //ORGACOMPU_TP2_COMMANDEXECUTOR_H
