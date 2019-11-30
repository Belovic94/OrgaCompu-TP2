#include <zconf.h>
#include "cache.h"

cache_t cache;

int cache_create() {
    cache.access_counter = 0;
    cache.miss_counter = 0;
    for (int i = 0; i < BLOCKS_NUMBER; ++i) {
        set_create(&cache.set[i], i);
    }
    return 0;
}

void cache_destroy() {}

int cache_write_byte(unsigned int address, unsigned char value) {
    cache.access_counter++;
    if (set_write_byte(&cache.set[find_set(address)], address, value) != 0) {
        cache.miss_counter++;
        return -1;
    }
    return 0;
}

float cache_get_miss_rate() {
    if (cache.access_counter == 0) {
        return 0;
    }
    return (float) cache.miss_counter / cache.access_counter;
}

int cache_read_byte(unsigned int address, unsigned char* byte_to_read) {
    cache.access_counter++;
    if (set_read_byte(&cache.set[find_set(address)], address, byte_to_read) == -1) {
        cache.miss_counter++;
        return -1;
    }
    return 0;
}

unsigned int cache_get_free_way(unsigned int set) {
    return set_get_free_way(&cache.set[set]);
}

void cache_save_block(unsigned char *block, unsigned int way, unsigned int address) {
    set_save_block(&cache.set[find_set(address)], way, block, address);
}

void cache_init() {

}

