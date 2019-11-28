#include "set.h"

unsigned int _get_tag(unsigned int address);
unsigned int _get_offset(unsigned int address);

int set_get_oldest() {
    return 0;
}

void set_destroy(set_t *self) {

}

int set_create(set_t *self) {
}

int _get_way(set_t *self, unsigned int address) {
    int way = -1;
    unsigned int tag = _get_tag(address);
    for (int i = 0; i < 8; ++i) {
        if (self->ways[i]->valid != 1 && self->ways[i]->tag == tag) {
            way = i;
            break;
        }
    }
    return way;
}

int set_read_byte(set_t *self, unsigned int address, unsigned char *byte_to_read) {
    int way_index = _get_way(self, address);
    if ( way_index != -1) {
        way_t* selected_way = self->ways[way_index];
        way_read_byte(selected_way,  )
    }
}

unsigned int _get_tag(unsigned int address) {
    return address >> 11;
}

unsigned int _get_offset(unsigned int address) {
    return
}
