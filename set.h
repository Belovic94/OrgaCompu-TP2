#ifndef ORGACOMPU_TP2_QUEUE_H
#define ORGACOMPU_TP2_QUEUE_H

#include "way.h"

typedef struct {
    way_t* ways[8];
    unsigned int index: 5;
}set_t;

int set_create(set_t* self);

void set_destroy(set_t* self);

int set_get_oldest();

int set_write_byte(set_t *self, unsigned int address, unsigned char value);

int set_read_byte(set_t* self, unsigned int address, unsigned char* byte_to_read);

unsigned int set_get_free_way(set_t* self);

void set_save_block(set_t* self, unsigned int way, unsigned  char* block, unsigned int address);

#endif //ORGACOMPU_TP2_QUEUE_H
