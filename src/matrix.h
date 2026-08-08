#ifndef MATRIX_H
#define MATRIX_H

#include <time.h>
#include "vector.h"

typedef struct {
    unsigned int rows;
    unsigned int cols;
    double **data;
    bool is_square;
} Matrix;

/**
 * @brief Allocates memory to create a new matrix
 *
 * @param rows Number of rows to allocate
 * @param cols Number of columns to allocate
 *
 * @return Created matrix
 */
Matrix *matrix_create(unsigned int rows, unsigned int cols);

/**
 * @brief Frees the memory allocated to a matrix
 *
 * @param matrix Matrix whose memory to free
 */
void matrix_destroy(Matrix *matrix);

/**
 * @brief Creates an identity matrix of a given size
 *
 * @param size Number of rows and columns of identity matrix
 *
 * @return Created identity matrix
 */
Matrix *eye(unsigned int size);

/**
 * @brief Creates a matrix of given size and populates it with random
 *        floating point values within a given range
 *
 * @param rows Number of rows in matrix
 * @param cols Number of columns in matrix
 * @param min Minimum range of random numbers
 * @param max Maximum range of random numbers
 *
 * @return Matrix with randomly generated values
 */
Matrix *matrix_random(unsigned int rows, unsigned int cols, scalar_t min, scalar_t max);

/**
 * @brief Prints the entries of a matrix to a given precision
 *
 * @param matrix Matrix to be printed to terminal
 * @param precision Number of decimal places to print values to
 */
void matrix_print(const Matrix *matrix, unsigned int precision);

/**
 * @brief Adds two matrices together
 *
 * @param lhs Left-hand matrix
 * @param rhs Right-hand matrix
 *
 * @return Matrix with summed entries
 */
Matrix *matrix_add(const Matrix *lhs, const Matrix *rhs);

/**
 * @brief Subtracts one matrix from another
 *
 * @param lhs Left-hand matrix
 * @param rhs Right-hand matrix
 *
 * @return Matrix with subtracted entries
 */
Matrix *matrix_subtract(const Matrix *lhs, const Matrix *rhs);

/**
 * @brief Creates a copy of an existing matrix
 *
 * @param matrix Matrix to be copied
 *
 * @return Copy of given matrix
 */
Matrix *matrix_copy(const Matrix *matrix);

/**
 * @brief Creates the transpose of a given matrix
 *
 * @param matrix Matrix to be transposed
 *
 * @return Transpose of original matrix
 */
Matrix *transpose(const Matrix *matrix);

/**
 * @brief Multiplies two matrices
 *
 * @param lhs Left-hand matrix
 * @param rhs Right-hand matrix
 *
 * @return Product of the two matrices
 */
Matrix *matrix_multiply(const Matrix *lhs, const Matrix *rhs);

/**
 * @brief Creates an augmented matrix
 *
 * @param *lhs Left hand matrix
 * @param *rhs Right hand matrix
 *
 * @return Augemented matrix
 */
Matrix *create_augmented(const Matrix *lhs, const Matrix *rhs);
#endif
