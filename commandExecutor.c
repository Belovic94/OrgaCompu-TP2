#include "commandExecutor.h"


void init(command_executor_t *self);
float get_miss_rate(command_executor_t *self);
unsigned char read_byte(command_executor_t *self, unsigned int address);
void write_byte(command_executor_t *self, unsigned int address, unsigned char value);


void command_executor_create(command_executor_t *self, cache_t *cache, main_memory_t *mainMemory) {
    self->cache = cache;
    self->mainMemory = mainMemory;
}

void command_executor_destroy(command_executor_t *self) {

}

void command_executor_execute(command_executor_t *self, command_t *command) {
    switch (command->operation) {
        case 'F':
            init(self);
            break;
        case 'M':
            get_miss_rate(self);
            break;
        case 'R':
            read_byte(self, command->address);
            break;
        case 'W':
            write_byte(self, command->address, command->value);
            break;
    }
}

void init(command_executor_t *self) {

    main_memory_init(self->mainMemory);
    cache_init(self->cache);
}

float get_miss_rate(command_executor_t *self) {
    return cache_get_miss_rate(self->cache);
}

unsigned char read_byte(command_executor_t *self, unsigned int address) {
    unsigned char byte_to_read;
    if(cache_read_byte(self->cache, address, &byte_to_read) == 0) {
        
    }
}
void write_byte(command_executor_t *self, unsigned int address, unsigned char value) {
    cache_write_byte(self->cache, address, value);
}


//unsigned int get_offset(unsigned int address);
//void read_tocache(unsigned int blocknum, unsigned int way, unsigned int set);
//write_tomem (unsigned int blocknum, unsigned int way, unsigned int set);
//unsigned char read_byte(unsigned int address);
//void write_byte(unsigned int address, unsigned char value);
//float get_miss_rate();

