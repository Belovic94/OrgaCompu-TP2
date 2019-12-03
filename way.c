#include "way.h"
#include "stdlib.h"
#include "addressHelper.h"
#include "mainMemory.h"

unsigned char way_read_byte(way_t *self, unsigned int offset) {
    return self->block[offset];
}

void way_create(way_t *self) {
    self->valid = 0;
    self->tag = 0;
    self->dirty = 0;
    self->old = 0;
}

void way_destroy(way_t *self) {

}

void way_save_block(way_t * self, unsigned char *block, unsigned int address) {
    for (int i = 0; i < BLOCK_SIZE; ++i) {
        self->block[i] = block[i];
    }
    self->valid = 1;
    self->tag = get_tag(address);
    self->old++;
    self->dirty = 0;
}

void way_write_back(way_t *self, unsigned int index) {
    if (self->dirty == 1) {
        unsigned int pos = (self->tag << 11) | (index << 6);
        main_memory_save_block(self->block, pos);
    }
}

void way_write_byte(way_t *self, unsigned int offset, unsigned char value) {
    self->dirty = 1;
    self->block[offset] = value;
}

void way_init(way_t *self) {
    for (int i = 0; i < BLOCK_SIZE; ++i) {
        self->block[i] = 0;
    }
    self->dirty = 0;
    self->old = 0;
    self->tag = 0;
    self->valid = 0;
}
