#ifndef ORGACOMPU_TP2_CACHE_H
#define ORGACOMPU_TP2_CACHE_H

#include "set.h"
#include "addressHelper.h"

typedef struct {
    int access_counter;
    int miss_counter;
    set_t* set[BLOCKS_NUMBER];
} cache_t;

int cache_create();

void cache_destroy();

void cache_init();

float cache_get_miss_rate();

int cache_read_byte(unsigned int address, unsigned char* byte_to_read);

void cache_write_byte(unsigned int address, unsigned char value);

unsigned int cache_get_free_way(unsigned int set);

void cache_save_block(unsigned char* block, unsigned int way, unsigned int set);

write_tomem(unsigned int blocknum, unsigned int way, unsigned int set);


#endif //ORGACOMPU_TP2_CACHE_H
