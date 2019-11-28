#ifndef ORGACOMPU_TP2_CACHE_H
#define ORGACOMPU_TP2_CACHE_H

#include "set.h"
#define BLOCKS_NUMBER 32
#define BLOCK_SIZE 64

typedef struct {
    int access_counter;
    int miss_counter;
    set_t* set[BLOCKS_NUMBER];

} cache_t;

int cache_create(cache_t *self);

void cache_destroy(cache_t *self);

char cache_execute(cache_t *self);

void cache_init(cache_t* self);

float cache_get_miss_rate(cache_t* self);

unsigned char cache_read_byte(cache_t* self, unsigned int address);

unsigned int get_offset(unsigned int address);
//unsigned int select_oldest(unsigned int setnum);
void read_tocache(unsigned int blocknum, unsigned int way, unsigned int set);
write_tomem(unsigned int blocknum, unsigned int way, unsigned int set);
//unsigned char read_byte(unsigned int address);
//void write_byte(unsigned int address, unsigned char value);

#endif //ORGACOMPU_TP2_CACHE_H
