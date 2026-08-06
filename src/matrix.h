#ifndef MATRIX_H
#define MATRIX_H
#include <time.h>
#include "vector.h"

typedef struct {
    unsigned int num_rows;
    unsigned int num_cols;
    double **data;
    int is_square;
} Matrix;

/**
 * @brief Allocates memory to create a new matrix
 *
 * @param num_rows Number of rows to allocate
 * @param num_cols Number of columns to allocate
 *
 * @return Created matrix
 */
Matrix *new_matrix(unsigned int num_rows, unsigned int num_cols);

/**
 * @brief Free up memory allocated to a matrix
 *
 * @param *mat Matrix whose memory to free
 */
void free_matrix(Matrix *mat);

/**
 * @brief Creates an identity matrix of a given size
 *
 * @param size Number of rows and columns of identity matrix
 *
 * @return Created identity matrix
 */
Matrix *new_identity_matrix(unsigned int size);

/**
 * @brief Creates a matrix of given size and populates it with random
 *        floating point values within a given range
 *
 * @param num_rows Number of rows in matrix
 * @param num_cols Number of columns in matrix
 * @param min Minimum range of random numbers
 * @param max Maximum range of random numbers
 *
 * @return Matrix with randomly generated values
 */
Matrix *rand_matrix(unsigned int num_rows, unsigned int num_cols, double min, double max);

/**
 * @brief Prints the entries of a matrix to a given precision
 *
 * @param *mat Matrix to be printed to terminal
 * @param precision Number of decimal places to print values to
 */
void print_matrix(Matrix *mat, int precision);

/**
 * @brief Adds two matrices together
 *
 * @param *mat1 First matrix
 * @param *mat2 Second matrix
 *
 * @return Matrix with summed entries
 */
Matrix *add_matrices(const Matrix *mat1, const Matrix *mat2);

/**
 * @brief Subtracts one matrix from another
 *
 * @param *mat1 First matrix
 * @param *mat2 Second matrix
 *
 * @return Matrix with substracted entries
 */
Matrix *subtract_matrices(const Matrix *mat1, const Matrix *mat2);

#endif
