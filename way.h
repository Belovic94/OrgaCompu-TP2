#ifndef ORGACOMPU_TP2_CACHE_BLOCK_H
#define ORGACOMPU_TP2_CACHE_BLOCK_H

typedef struct {
    unsigned int tag: 5;
    unsigned int valid : 1;
    unsigned int old;
    char block[64];
}way_t;

void way_create(way_t* self);

void way_destroy(way_t* self);

char way_read_byte(way_t* self, unsigned int offset);


#endif //ORGACOMPU_TP2_CACHE_BLOCK_H
