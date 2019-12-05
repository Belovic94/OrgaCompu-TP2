#ifndef ORGACOMPU_TP2_FILEREADER_H
#define ORGACOMPU_TP2_FILEREADER_H

#include <stdio.h>

typedef struct {
    FILE *fp;
}filereader_t;

void filereader_create(filereader_t* self, FILE* fp);

void filereader_destroy(filereader_t* self);

int filereader_next(filereader_t* self, char** line);



#endif //ORGACOMPU_TP2_FILEREADER_H
