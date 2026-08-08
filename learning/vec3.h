#ifndef VEC3_H
#define VEC3_H

#define EPSILON 1e-9

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef double scalar_t;

typedef union {
    struct {
        scalar_t x;
        scalar_t y;
        scalar_t z;
    };
    scalar_t data[3];
} Vec3;

/**
 * @brief Adds two vectors component-wise.
 *
 * @param vec1 Vector 1
 * @param vec2 Vector 2
 *
 * @return Sum of vec1 and vec2
 */
Vec3 vec3_add(Vec3 vec1, Vec3 vec2);

/**
 * @brief Subtracts two vectors component-wise.
 *
 * @param vec1 Vector 1
 * @param vec2 Vector 2
 *
 * @return Difference of vec1 and vec2
 */
Vec3 vec3_subtract(Vec3 vec1, Vec3 vec2);

/**
 * @brief Computes the dot product of two vectors.
 *
 * @param vec1 Vector 1
 * @param vec2 Vector 2
 *
 * @return Scalar dot product
 */
scalar_t vec3_dot(Vec3 vec1, Vec3 vec2);

/**
 * @brief Computes the cross product of two vectors.
 *
 * @param vec1 Vector 1
 * @param vec2 Vector 2
 *
 * @return Cross product of the two vectors
 */
Vec3 vec3_cross(Vec3 vec1, Vec3 vec2);

/**
 * @brief Computes the magnitude of a vector.
 *
 * @param vec Vector whose magnitude is computed
 *
 * @return Magnitude of vector
 */
scalar_t vec3_mag(Vec3 vec);

/**
 * @brief Finds the projection of one vector onto another.
 *
 * Returns the zero vector if either input is zero.
 *
 * @param vec1 Vector to project
 * @param vec2 Vector defining projection direction
 *
 * @return Projection of vec1 onto vec2
 */
Vec3 vec3_proj(Vec3 vec1, Vec3 vec2);

/**
 * @brief Normalizes a vector.
 *
 * Returns the zero vector if the magnitude is zero.
 *
 * @param vec Vector to normalize
 *
 * @return Normalized vector
 */
Vec3 vec3_norm(Vec3 vec);

/**
 * @brief Scales a vector by a given value.
 *
 * @param vec Vector to scale
 * @param scalar Scale factor
 *
 * @return Scaled vector
 */
Vec3 vec3_scale(Vec3 vec, scalar_t scalar);

/**
 * @brief Computes the distance between two vectors.
 *
 * @param vec1 Vector 1
 * @param vec2 Vector 2
 *
 * @return Distance between vectors
 */
scalar_t vec3_distance(Vec3 vec1, Vec3 vec2);

/**
 * @brief Determines if two vectors are orthogonal.
 *
 * Permits a margin of error of EPSILON.
 *
 * @param vec1 Vector 1
 * @param vec2 Vector 2
 *
 * @return 1 if orthogonal, 0 otherwise
 */
int vec3_are_orthogonal(Vec3 vec1, Vec3 vec2);

/**
 * @brief Determines if a vector is the zero vector.
 *
 * Permits a margin of error of EPSILON.
 *
 * @param vec Vector
 *
 * @return 1 if zero vector, 0 otherwise
 */
int vec3_is_zero(Vec3 vec);

/**
 * @brief Determines if two vectors are parallel.
 *
 * Permits a margin of error of EPSILON.
 *
 * @param vec1 Vector 1
 * @param vec2 Vector 2
 *
 * @return 1 if parallel, 0 otherwise
 */
int vec3_are_parallel(Vec3 vec1, Vec3 vec2);

/**
 * @brief Reads a 3D vector from standard input.
 *
 * Repeatedly prompts until a valid vector is entered.
 *
 * Expected format:
 * A,B,C
 *
 * @return Input vector
 */
Vec3 vec3_input(void);

/**
 * @brief Computes the angle in radians between two vectors.
 *
 * @param vec1 Vector 1
 * @param vec2 Vector 2
 *
 * @return Angle in radians
 */
scalar_t vec3_angle(Vec3 vec1, Vec3 vec2);

/**
 * @brief Computes the scalar triple product.
 *
 * @param vec1 Vector 1
 * @param vec2 Vector 2
 * @param vec3 Vector 3
 *
 * @return Scalar triple product
 */
scalar_t vec3_scalar_triple(Vec3 vec1, Vec3 vec2, Vec3 vec3);

/**
 * @brief Computes the vector triple product.
 *
 * @param vec1 Vector 1
 * @param vec2 Vector 2
 * @param vec3 Vector 3
 *
 * @return Vector triple product
 */
Vec3 vec3_vector_triple(Vec3 vec1, Vec3 vec2, Vec3 vec3);

/**
 * @brief Generates a random floating-point number within a range.
 *
 * @param min Minimum value
 * @param max Maximum value
 *
 * @return Random floating-point value
 */
double rand_double(double min, double max);

#endif
