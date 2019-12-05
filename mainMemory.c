#include "mainMemory.h"
#include "stdlib.h"
#include "addressHelper.h"
#include "stdio.h"

main_memory_t mainMemory;

int main_memory_create() {
    unsigned char* aTable = calloc(65536, sizeof(unsigned char));
    if (aTable == NULL) {
        return -1;
    }
    mainMemory.memoryTable = aTable;
    return 0;
}

void main_memory_destroy() {
    free(mainMemory.memoryTable);
}

void main_memory_read_tocache(unsigned int blockNum, unsigned char *block) {
    printf("Se produjo un acceso a memoria principal para cargar el bloque correspondiente "
           "a la dirección: %d  en memoria cache \n", blockNum * BLOCK_SIZE);
    for (int i = 0; i < BLOCK_SIZE; ++i) {
        block[i] = mainMemory.memoryTable[(blockNum * BLOCK_SIZE) + i];
    }
}

void main_memory_write_toMem(const unsigned char *block, unsigned int address) {
    printf("Se produjo un acceso a memoria principal para guardar el bloque correspondiente "
           "a la dirección: %d \n", address);
    for (int i = 0; i < BLOCK_SIZE; ++i) {
        mainMemory.memoryTable[address + i] = block[i];
    }
}


