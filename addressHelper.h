#ifndef ORGACOMPU_TP2_ADDRESSHELPER_H
#define ORGACOMPU_TP2_ADDRESSHELPER_H

#define BLOCKS_NUMBER 32
#define BLOCK_SIZE 64

unsigned int find_set(unsigned int address);
unsigned int get_offset(unsigned int address);
unsigned int get_tag(unsigned int address);
#endif //ORGACOMPU_TP2_ADDRESSHELPER_H
