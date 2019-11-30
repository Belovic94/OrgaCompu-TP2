#include "mainMemory.h"
#include "stdlib.h"
#include "addressHelper.h"

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
    for (int i = 0; i < BLOCK_SIZE; ++i) {
        block[i] = mainMemory.memoryTable[blockNum + i];
    }
}

void main_memory_save_block(unsigned char *block, unsigned int pos) {

}

void main_memory_destroy() {
    free(mainMemory.memoryTable);
}


