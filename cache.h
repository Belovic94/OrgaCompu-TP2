#ifndef ORGACOMPU_TP2_CACHE_H
#define ORGACOMPU_TP2_CACHE_H

#include "queue.h"
#define BLOCKS_NUMBER 32
#define BLOCK_SIZE 64

typedef struct {
    int access_counter;
    int miss_counter;
    queue_t* ways;

} cache_t;

int cache_create(cache_t *self);

void cache_destroy(cache_t *self);

char cache_execute(cache_t *self);

void cache_init(cache_t* self);

void init();
void read();
void write();
unsigned int get_offset(unsigned int address);

unsigned int select_oldest(unsigned int setnum);
void read_tocache(unsigned int blocknum, unsigned int way, unsigned int set);
write_tomem (unsigned int blocknum, unsigned int way, unsigned int set);
unsigned char read_byte(unsigned int address);
void write_byte(unsigned int address, unsigned char value);
float get_miss_rate();

#endif //ORGACOMPU_TP2_CACHE_H
