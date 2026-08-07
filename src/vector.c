/****************************************

File: vector.c

Author: Connor Fletcher

Date: August 06, 2026

Brief: Functions performing fundamental vector operations

****************************************/

#include "vector.h"

Vector *vector_create(unsigned int size) {
    if (size == 0) return NULL;
    Vector *new_vector = calloc(1, sizeof(*new_vector));

    new_vector->size = size;

    new_vector->data = calloc(size, sizeof(new_vector->data));
    if (new_vector->data == NULL) {
        free(new_vector);
        return NULL;
    }

    return new_vector;
}

void vector_destroy(Vector *vector) {
    if (vector == NULL) return;

    free(vector->data);
    free(vector);
}
