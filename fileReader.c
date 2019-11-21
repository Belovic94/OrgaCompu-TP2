#include <stdlib.h>
#include "fileReader.h"

void filereader_create(filereader_t *self, FILE *fp) {
    self->fp = fp;
}

void filereader_destroy(filereader_t *self) {
    fclose(self->fp);
}

int filereader_next(filereader_t *self, char* line) {
    //    char *line = NULL;
//    size_t len = 0;
//    size_t read;
    //    while ((read = getline(&line, &len, fp)) != -1)
}
