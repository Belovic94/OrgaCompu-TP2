#include "cache.h"

void cache_create(cache_t *self, queue_t *ways)
{
    self->access_counter = 0;
    self->miss_counter = 0;
    self->ways = ways;
}

void cache_destroy(cache_t *self) {}

char cache_execute(cache_t *self);

unsigned int get_offset(unsigned int address)
{
    return address % BLOCK_SIZE;
}

unsigned int find_set(unsigned int address)
{
    int mba = address / BLOCK_SIZE;
    return mba % BLOCKS_NUMBER;
}

unsigned int select_oldest(unsigned int setnum)
{
    queue_t *selected_way = self->ways[setnum];
    selected_way.select_oldest();
}

void read_tocache(unsigned int blocknum, unsigned int way, unsigned int set)
{
}

write_tomem(unsigned int blocknum, unsigned int way, unsigned int set)
{
}

unsigned char read_byte(unsigned int address)
{
}

void write_byte(unsigned int address, unsigned char value)
{
}

float get_miss_rate()
{
    return self->miss_counter / self->access_counter;