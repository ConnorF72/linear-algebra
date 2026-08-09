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

/**
 * @brief Add a number to every element of a row in a matrix
 *
 * @param *matrix Matrix to be added to
 * @param row Row to be added to; index position starting at 1
 * @param num Number to add to row
 */
void matrix_row_add(Matrix *matrix, unsigned int row, scalar_t num);

/**
 * @brief Scale every element in a row of a matrix by a given value
 *
 * @param *matrix Matrix with row being scaled
 * @param row Row to be scaled; index position starting at 1
 * @param scalar Number to scale row by
 */
void scale_row(Matrix *matrix, unsigned int row, scalar_t scalar);

/**
 * @brief Swap two rows of a matrix
 *
 * @param *matrix Matrix whose rows are being swapped
 * @param row1 First row; index position starting at 1
 * @param row2 Second row; index position starting at 1
 */
void swap_rows(Matrix *matrix, unsigned int row1, unsigned int row2);

Matrix *rref(const Matrix *matrix);

#endif
