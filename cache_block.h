#ifndef ORGACOMPU_TP2_CACHE_BLOCK_H
#define ORGACOMPU_TP2_CACHE_BLOCK_H

typedef struct {
    int tag;
    int valid;
    int oldest;
}cache_block_t;

void cache_block_create(cache_block_t* self);

void cache_block_destroy(cache_block_t* self);

char cache_block_execute(cache_block_t* self);


#endif //ORGACOMPU_TP2_CACHE_BLOCK_H
