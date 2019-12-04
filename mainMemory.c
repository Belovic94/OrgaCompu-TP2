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

void main_memory_get_block(unsigned int blockNum, unsigned char* block) {
    printf("Se produjo un acceso a memoria principal y se cargo el bloque: %d  en memoria cache \n", blockNum);
    for (int i = 0; i < BLOCK_SIZE; ++i) {
        block[i] = mainMemory.memoryTable[blockNum + i];
    }
}

void main_memory_save_block(unsigned char *block, unsigned int blockNum) {
    printf("Se produjo un acceso a memoria principal para modificar el bloque: %d \n", blockNum);
    for (int i = 0; i < BLOCK_SIZE; ++i) {
        mainMemory.memoryTable[blockNum + i] = block[i];
    }
}

void main_memory_destroy() {
    free(mainMemory.memoryTable);
}


