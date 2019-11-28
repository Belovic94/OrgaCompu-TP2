#ifndef ORGACOMPU_TP2_MAINMEMORY_H
#define ORGACOMPU_TP2_MAINMEMORY_H

typedef struct {
    char* memoryTable;
}main_memory_t;

void main_memory_create();

void main_memory_destroy();

void main_memory_init();

unsigned char* main_memory_get_block(unsigned int address);

void main_memory_save_block(unsigned char* block, unsigned int pos);

#endif //ORGACOMPU_TP2_MAINMEMORY_H
