#include "commandExecutor.h"

void command_executor_create(command_executor_t *self, cache_t *cache, main_memory_t *mainMemory) {
    self->cache = cache;
    self->mainMemory = mainMemory;
}

void command_executor_destroy(command_executor_t *self) {

}

void command_executor_execute(command_executor_t *self, command_t *command) {
//    TODO Hacer un switch segun el tipo de operación.
}
