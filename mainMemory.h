#ifndef ORGACOMPU_TP2_MAINMEMORY_H
#define ORGACOMPU_TP2_MAINMEMORY_H

typedef struct {
    char* memoryTable;
}main_memory_t;

void main_memory_create(main_memory_t* self);

void main_memory_destroy(main_memory_t* self);

void main_memory_init(main_memory_t* self);

#endif //ORGACOMPU_TP2_MAINMEMORY_H
