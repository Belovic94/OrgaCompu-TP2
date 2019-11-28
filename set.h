#ifndef ORGACOMPU_TP2_QUEUE_H
#define ORGACOMPU_TP2_QUEUE_H

#include "way.h"

typedef struct {
    way_t* ways[8];
}set_t;

int set_create(set_t* self);

void set_destroy(set_t* self);

int set_get_oldest();

int set_read_byte(set_t* self, unsigned int address, unsigned char* byte_to_read);

#endif //ORGACOMPU_TP2_QUEUE_H
