#include "mainMemory.h"

void main_memory_create(main_memory_t *self) {}

void main_memory_destroy(main_memory_t *self);

char *read_block_num(main_memory_t *self, unsigned int blocknum)
{
    return self->memoryTable[blocknum]; //adjust blocknum
}
