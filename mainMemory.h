#ifndef ORGACOMPU_TP2_MAINMEMORY_H
#define ORGACOMPU_TP2_MAINMEMORY_H

typedef struct {
    unsigned char* memoryTable;
}main_memory_t;

int main_memory_create();

void main_memory_destroy();

void main_memory_read_tocache(unsigned int blockNum, unsigned char *block);

void main_memory_write_toMem(const unsigned char* block, unsigned int address);

#endif //ORGACOMPU_TP2_MAINMEMORY_H
