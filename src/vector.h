#ifndef VECTOR_H
#define VECTOR_H

#define DIMENSION_ERROR -1
#define VECTOR_3D 3
#define PI 3.141592653
#define EPSILON 1e-9

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef double scalar_t;

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
 * @brief Creates a copy of a vector
 *
 * @param vector Vector to be copied
 *
 * @return Copy of vector
 */
Vector *vector_copy(const Vector *vector);

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
scalar_t dot(const Vector *first_vector, const Vector *second_vector);

/**
 * @brief Computes the cross product of two 3D vectors
 *
 * @param lhs Left hand vector
 * @param rhs Right hand vector
 *
 * @return Vector cross product
 */
Vector *cross(const Vector *lhs, const Vector *rhs);

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

/**
 * @brief Computes the projection of one vector onto another
 *
 * @param vec1 Vector to project
 * @param vec2 Vector defining projection direction
 *
 * @return Projection
 */
Vector *proj(const Vector *vec1, const Vector *vec2);

/**
 * @brief Scales a vector by a given floating point value
 *
 * @param *vector Vector to be scaled
 */
void vector_scale(Vector *vector, scalar_t scalar);

/**
 * @brief Generates a random floating-point number within a range.
 *
 * @param min Minimum value
 * @param max Maximum value
 *
 * @return Random floating-point value
 */
scalar_t rand_scalar(scalar_t min, scalar_t max);

/**
 * @brief Generates a random unsigned integer
 *
 * @param min Minimum value
 * @param max Maximum value
 *
 * @return Random unsigned integer
 */
unsigned int rand_uint(unsigned int min, unsigned int max);

/**
 * @brief Determines if two are parallel
 *
 * @param *vec1 First vector
 * @param *vec2 Second vector
 */
bool are_parallel(const Vector *vec1, const Vector *vec2);

/**
 * @brief Determines if two vectors are orthogonal to one another
 *
 * @param *vec1 First Vector
 * @param *vec2 Second Vector
 */
bool are_orthogonal(const Vector *vec1, const Vector *vec2);

/**
 * @brief Determines if given vector is zero vector
 *
 * @param *vector Vector to be checked
 */
bool is_zero(const Vector *vector);

/**
 * @brief Computes the angle between two vectors
 *
 * @param vec1 First Vector
 * @param vec2 Second Vector
 *
 * @return Angle between vectors
 */
scalar_t angle(const Vector *vec1, const Vector *vec2);

/**
 * @brief Computes the distance between two vectors
 *
 * @param vec1 First vector
 * @param vec2 Second Vector
 *
 * @return Shortest distance between vectors
 */
scalar_t distance(const Vector *vec1, const Vector *vec2);

/**
 * @brief Sets the values of a vector
 *
 * @param *vector Vector to be assigned values
 * @param *values Array of values to be assigned
 */
void vector_set(Vector *vector, const scalar_t *values);
#endif
