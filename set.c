#include "set.h"
#include "addressHelper.h"

unsigned int _get_free_way_index(set_t* self);

int set_get_oldest(set_t *self) {
    return 0;
}

void set_destroy(set_t *self) {

}

int set_create(set_t *self) {
}

int _find_way(set_t *self, unsigned int address) {
    int way = -1;
    unsigned int tag = get_tag(address);
    for (int i = 0; i < 8; ++i) {
        if (self->ways[i]->valid != 1 && self->ways[i]->tag == tag) {
            way = i;
            break;
        }
    }
    return way;
}

int set_read_byte(set_t *self, unsigned int address, unsigned char *byte_to_read) {
    unsigned int tag = get_tag(address);
    for (int i = 0; i < 8; ++i) {
        if (self->ways[i]->valid == 1 && self->ways[i]->tag == tag) {
            *byte_to_read = way_read_byte(self->ways[i], get_offset(address));
            return 0;
        }
    }
    return -1;
}

unsigned int set_get_free_way(set_t* self) {
    unsigned int way_index = _get_free_way_index(self);
    if (way_index != -1) {
        way_index = set_get_oldest(self);
        way_write_back(self->ways[way_index], self->index);
    }
    return way_index;
}

void set_save_block(set_t *self, unsigned int way, unsigned char *block, unsigned int address) {
    way_save_block(self->ways[way], block, address);
}

unsigned int _get_free_way_index(set_t* self) {
    for (int i = 0; i < 8; ++i) {
        if (self->ways[i]->valid == 0) {
            return i;
        }
    }
    return -1;
}
