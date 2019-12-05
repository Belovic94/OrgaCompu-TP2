#include "set.h"
#include "stdio.h"

unsigned int _get_free_way_index(set_t* self);

int set_get_oldest(set_t *self) {
    int oldest = -1;
    unsigned int oldest_index = 0;
    for (int i = 0; i < WAYS_NUMBER; ++i) {
        if (self->ways[i].old > oldest) {
            oldest_index = i;
            oldest = self->ways[i].old;
        }
    }
    return oldest_index;
}

void set_destroy(set_t *self) {
    for (int i = 0; i < WAYS_NUMBER ; ++i) {
        way_destroy(&self->ways[i]);
    }
}

int set_create(set_t *self, int index) {
    self->index = index;
    for (int i = 0; i < WAYS_NUMBER; ++i) {
        way_create(&self->ways[i]);
    }
    return 0;
}

int set_write_byte(set_t *self, unsigned int address, unsigned char value) {
    unsigned int tag = get_tag(address);
    for (int i = 0; i < WAYS_NUMBER; ++i) {
        if (self->ways[i].valid == 1 && self->ways[i].tag == tag) {
            way_write_byte(&self->ways[i], get_offset(address), value);
            return 0;
        }
    }
    return -1;

}

int set_read_byte(set_t *self, unsigned int address, unsigned char *byte_to_read) {
    unsigned int tag = get_tag(address);
    for (int i = 0; i < WAYS_NUMBER; ++i) {
        if (self->ways[i].valid == 1 && self->ways[i].tag == tag) {
            *byte_to_read = way_read_byte(&self->ways[i], get_offset(address));
            return 0;
        }
    }
    return -1;
}

unsigned int set_get_free_way(set_t* self) {
    unsigned int way_index = _get_free_way_index(self);
    if (way_index == -1) {
        printf("Todas las vias están llenas, se procede a aplicar la politica de reemplazo\n");
        way_index = set_get_oldest(self);
        way_write_back(&self->ways[way_index], self->index);
    }
    return way_index;
}

void set_save_block(set_t *self, unsigned int way, unsigned char *block, unsigned int address) {
    way_save_block(&self->ways[way], block, address);
}

void set_init(set_t *self) {
    for (int i = 0; i < WAYS_NUMBER; ++i) {
        way_init(&self->ways[i]);
    }
}

unsigned int _get_free_way_index(set_t* self) {
    for (int i = 0; i < WAYS_NUMBER; ++i) {
        if (self->ways[i].valid == 0) {
            return i;
        }
        if (self->ways[i].old < 7) {
            self->ways[i].old++;
        }
    }
    return -1;
}
