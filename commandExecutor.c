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

unsigned int get_offset(unsigned int address);
void read_tocache(unsigned int blocknum, unsigned int way, unsigned int set);
write_tomem (unsigned int blocknum, unsigned int way, unsigned int set);
unsigned char read_byte(unsigned int address);
void write_byte(unsigned int address, unsigned char value);
float get_miss_rate();
