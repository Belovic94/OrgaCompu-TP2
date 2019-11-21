#include "cache_block.h"

void cache_block_create(cache_block_t* self) {
    self->valid = 1;
    self->oldest = 0;
}


void cache_block_destroy(cache_block_t* self) {}

char cache_block_execute(cache_block_t* self);