#ifndef ORGACOMPU_TP2_CACHE_BLOCK_H
#define ORGACOMPU_TP2_CACHE_BLOCK_H

typedef struct {
    unsigned int tag: 5;
    unsigned int valid : 1;
    unsigned int old: 3;
    unsigned int dirty: 1;
    unsigned char block[64];
}way_t;

void way_create(way_t* self);

void way_destroy(way_t* self);

unsigned char way_read_byte(way_t* self, unsigned int offset);

void way_write_byte(way_t* self, unsigned int offset, unsigned char value);

void way_save_block(way_t*, unsigned char* block, unsigned int address);

void way_write_back(way_t* self, unsigned int index);

void way_init(way_t* self);


#endif //ORGACOMPU_TP2_CACHE_BLOCK_H
