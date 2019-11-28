#include "strutil.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* add_string(const char* str, size_t indice){
    char* str_aux = malloc(indice + 1);
    if (!str_aux) {
        return NULL;
    }
    strncpy(str_aux, str, indice);
    str_aux[indice] = '\0';
    return str_aux;
}

char** split(const char* str, char sep, size_t* size){
    char* vector[strlen(str)];
    char *pal_aux = strchr(str, sep);
    size_t i = 0;
    while (pal_aux != NULL) {
        vector[i] = add_string(str, strlen(str) - strlen(pal_aux));
        str = pal_aux + 1;
        pal_aux = strchr(str, sep);
        i++;
    }
    vector[i] = add_string(str, strlen(str));
    i++;
    vector[i] = NULL;
    //paso claves del vector local al vector hecho con malloc.
    char **strv = malloc((i + 1) * sizeof(char*));
    if (!strv) {
        return NULL;
    }

    for (int j = 0; j <= i ; j++){
        strv[j] = vector[j];
    }
    size = i;
    return strv;
}

void free_split(char **strv){
    if (!strv) {
        return;
    }
    for (int i = 0; strv[i]; i++){
        free(strv[i]);
    }
    free(strv);
}
