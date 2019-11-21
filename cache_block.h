#ifndef ORGACOMPU_TP2_CACHE_BLOCK_H
#define ORGACOMPU_TP2_CACHE_BLOCK_H

typedef struct {
}cache_block_t;

int cache_block_create(cache_block_t* self, char* command);

void cache_block_destroy(cache_block_t* self);

char cache_block_execute(cache_block_t* self);


#endif //ORGACOMPU_TP2_CACHE_BLOCK_H
