#ifndef VECTOR_H
#define VECTOR_H
#include "vec3.h"
#define NUMBER_ERROR -1
#define VECTOR_3D 3

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

/**
 * @brief Adds two vectors together
 *
 * @param first_vector
 * @param second_vector
 *
 * @return Vector which is the component-wise sum of the given vectors
 */
Vector *vector_add(const Vector *first_vector, const Vector *second_vector);

/**
 * @brief Subtracts one vector from another
 *
 * @param first_vector Vector that is subtracted from
 * @param second_vector Vector that subtracts
 *
 * @return Vector which is the component-wise difference of the given vectors
 */
Vector *vector_subtract(const Vector *first_vector, const Vector *second_vector);

/**
 * @brief Computes the dot product of two vectors
 *
 * @param first_vector
 * @param second_vector
 *
 * @return Scalar dot product
 */
scalar_t vector_dot(const Vector *first_vector, const Vector *second_vector);

/**
 * @brief Computes the cross product of two 3D vectors
 *
 * @param lhs Left hand vector
 * @param rhs Right hand vector
 *
 * @return Vector cross product
 */
Vector *vector_cross(const Vector *lhs, const Vector *rhs);

/**
 * @brief Computes the magnitude of a given vector
 *
 * @param *vector Vector whose magnitude will be computed
 *
 * @return Magnitude of vector
 */
scalar_t mag(const Vector *vector);

/**
 * @brief Computes the norm of a vector
 *
 * @param vector Vector whose norm is computed
 *
 * @return Norm of given vector
 */
Vector *norm(const Vector *vector);

#endif
