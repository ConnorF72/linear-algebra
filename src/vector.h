#ifndef VECTORS_H
#define VECTORS_H
#define EPSILON 1e-9

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef double scalar_t;

typedef struct {
    double x;
    double y;
    double z;
} Vector;

/**
 * @brief Adds two vectors component-wise
 *
 * @param vec1 Vector 1
 * @param vec2 Vector 2
 *
 * @return Sum of vec1 and vec2
 */
Vector add(Vector vec1, Vector vec2);

/**
 * @brief Subtracts two vectors component-wise
 *
 * @param vec1 Vector 1
 * @param vec2 Vector 2
 *
 * @return Difference of vec1 and vec2
 */
Vector subtract(Vector vec1, Vector vec2);

/**
 * @brief Computes the dot product of two vectors
 *
 * @param vec1 Vector 1
 * @param vec2 Vector 2
 *
 * @return Scalar dot product
 */
scalar_t dot(Vector vec1, Vector vec2);

/**
 * @brief Computes the cross product of two vectors
 *
 * @param vec1 Vector 1
 * @param vec2 Vector 2
 *
 * @return Cross produce of two vectors
 */
Vector cross(Vector vec1, Vector vec2);

/**
 * @brief Computes the magnitude of a vector
 *
 * @param vec Vector whose magnitude is computed
 *
 * @return Magnitude of vector
 */
scalar_t mag(Vector vec);

/**
 * @brief Finds the projection of one vector onto another.
 *        Returns the zero vector if either input is zero.
 *
 * @param vec1 Vector to project
 * @param vec2 Vector defining projection direction
 *
 * @return Projection of vec1 onto vec2
 */
Vector proj(Vector vec1, Vector vec2);

/**
 * @brief Normalizes a vector.
 *        Returns zero vector if magnitude is zero.
 *
 * @param vec Vector which is normalized
 *
 * @return Normalized vector
 */
Vector norm(Vector vec);

/**
 * @brief Scales a vector by a given value
 *
 * @param vec Vector to be scaled
 * @param scalar Value to scale vector by
 *
 * @return Scaled vector
 */
Vector scale(Vector vec, scalar_t scalar);

/**
 * @brief Computes the shortest distance between two vectors
 *
 * @param vec1 Vector 1
 * @param vec2 Vector 2
 *
 * @return Distance between vectors
 */
scalar_t distance(Vector vec1, Vector vec2);

/**
 * @brief Determines if two vectors are orthogonal to each other.
 *        Permits a margin of error of EPSILON.
 *
 * @param vec1 Vector 1
 * @param vec2 Vector 2
 *
 * @return 1 if vectors are orthogonal, 0 if they are not
 */
int are_orthogonal(Vector vec1, Vector vec2);

/**
 * @brief Determines if a vector is a zero vector.
 *        Permits a margin of error of EPSILON.
 *
 * @param vec Vector
 *
 * @return 1 if vector is zero vector, 0 otherwise
 */
int is_zero(Vector vec);

/**
 * @brief Determines if two vectors are parallel.
 *        Permits a margin of error of EPSILON.
 *
 * @param vec1 Vector 1
 * @param vec2 Vector 2
 *
 * @return 1 if vectors are parallel, 0 otherwise
 */
int are_parallel(Vector vec1, Vector vec2);

/**
 * @brief Takes comma-separated user input, and checks if correct number of arguments are passed.
 *        Repeatedly asks user for input until a valid 3D vector is entered.
 *
 * @return Vector inputted by user
 */
Vector input_vector(void);

/**
 * @brief Computes the angle in radians between two vectors
 *
 * @param vec1 Vector 1
 * @param vec2 Vector 2
 *
 * @return Angle in radians
 */
scalar_t angle(Vector vec1, Vector vec2);

/**
 * @brief Computes the scalar triple product of three vectors
 *
 * @param vec1 Vector 1
 * @param vec2 Vector 2
 * @param vec3 Vector 3
 *
 * @return Scalar triple product
 */
scalar_t scalar_triple(Vector vec1, Vector vec2, Vector vec3);

/**
 * @brief Computes the vector triple product of three vectors
 *
 * @param vec1 Vector 1
 * @param vec2 Vector 2
 * @param vec3 Vector 3
 *
 * @return Vector triple product
 */
Vector vector_triple(Vector vec1, Vector vec2, Vector vec3);

/**
 * @brief Generates a random floating point number within a given range
 *
 * @param min Minimum value in range
 * @param max Maximum value in range
 *
 * @return Random floating point value
 */
double rand_double(double min, double max);

#endif
