#include "way.h"

void cache_block_create(way_t* self) {
    self->valid = 1;
    self->tag = 0;
}

void cache_block_destroy(way_t* self) {}

char cache_block_execute(way_t* self);