#ifndef ORGACOMPU_TP2_CACHE_BLOCK_H
#define ORGACOMPU_TP2_CACHE_BLOCK_H


#include <zconf.h>

typedef struct {
    u_int8_t tag;
    u_int8_t valid;
    int oldest;
    u_int64_t block;
}cache_block_t;

void cache_block_create(cache_block_t* self);

void cache_block_destroy(cache_block_t* self);

char cache_block_execute(cache_block_t* self);


#endif //ORGACOMPU_TP2_CACHE_BLOCK_H
