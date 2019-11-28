#include "addressHelper.h"

unsigned int find_set(unsigned int address) {
    unsigned int mba = address / BLOCK_SIZE;
    return mba % BLOCKS_NUMBER;
}

unsigned int get_offset(unsigned int address) {
    return address % BLOCK_SIZE;
}

unsigned int get_tag(unsigned int address) {
    return address >> 11;
}