#include "commandExecutor.h"
#include "addressHelper.h"
#include "stdio.h"



void init();
float get_miss_rate();
unsigned char read_byte(unsigned int address);
void write_byte(unsigned int address, unsigned char value);
void read_tocache(unsigned int way, unsigned int address);

void command_executor_execute(command_t *command) {
    switch (command->operation) {
        case 'F':
            init();
            break;
        case 'M':
            printf("El miss rate es: %.3f \n", get_miss_rate());
            break;
        case 'R':
            printf("Se leyó el valor: %u en la dirección: %u \n", read_byte(command->address), command->address);
            break;
        case 'W':
            write_byte(command->address, command->value);
            break;
    }
}

void init() {
    cache_init();
}

float get_miss_rate() {
    return cache_get_miss_rate();
}

unsigned char read_byte(unsigned int address) {
    unsigned char byte_to_read;
    if(cache_read_byte(address, &byte_to_read) != 0) {
        read_tocache(cache_get_free_way(find_set(address)), address);
        cache_read_byte(address, &byte_to_read);
    }
    return byte_to_read;
}
void write_byte(unsigned int address, unsigned char value) {
    if (cache_write_byte(address, value) != 0) {
        read_tocache(cache_get_free_way(find_set(address)), address);
        cache_write_byte(address, value);
    }
}

void read_tocache(unsigned int way, unsigned int address) {
    unsigned char block[BLOCK_SIZE];
    main_memory_read_tocache(address / BLOCK_SIZE, block);
    cache_save_block(block, way, address);
}

