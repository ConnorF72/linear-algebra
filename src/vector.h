#ifndef VECTOR_H
#define VECTOR_H
#include "vec3.h"

typedef struct {
    unsigned int size;
    scalar_t *data;
} Vector;

/**
 * @brief Allocates memory for a new vector of given size
 *
 * @param size Size of created vector;
 *
 * @return Created vector
 */
Vector *vector_create(unsigned int size);

/**
 * @brief Frees the memory allocated to a vector
 *
 * @param *vector Vector to be destroyed
 */
void vector_destroy(Vector *vector);

#endif
