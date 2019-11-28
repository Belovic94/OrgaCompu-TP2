#ifndef ORGACOMPU_TP2_QUEUE_H
#define ORGACOMPU_TP2_QUEUE_H

#include "cache_block.h"

typedef struct {
    cache_block_t* cache_block;
}queue_t;

int queue_create(queue_t* self);

void queue_destroy(queue_t* self);

char queue_execute(queue_t* self);


#endif //ORGACOMPU_TP2_QUEUE_H
