#include <zconf.h>
#include "cache.h"

int cache_create(cache_t *self) {
    self->access_counter = 0;
    self->miss_counter = 0;
}

void cache_destroy(cache_t *self) {}

char cache_execute(cache_t *self);

unsigned int find_set(unsigned int address) {
    unsigned int mba = address / BLOCK_SIZE;
    return mba % BLOCKS_NUMBER;
}

unsigned int get_offset(unsigned int address){
    return address % BLOCK_SIZE;
}

unsigned int select_oldest(cache_t* self, unsigned int setnum) {
    set_t *selected_set = self->set[setnum];
    return set_get_oldest(selected_set);
}

void read_tocache(unsigned int blocknum, unsigned int way, unsigned int set) {
}

write_tomem(unsigned int blocknum, unsigned int way, unsigned int set) {
}

void write_byte(unsigned int address, unsigned char value) {
}

float cache_get_miss_rate(cache_t* self) {
    return self->miss_counter / self->access_counter;
}

int cache_read_byte(cache_t *self, unsigned int address, unsigned char* byte_to_read) {
    self->access_counter++;
    set_t* selected_set = self->set[find_set(address)];
    if (set_read_byte(selected_set, address) == 0) {
        byte_to_read = selected_set
    }
    return 0;

}
