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
Matrix *create_matrix(unsigned int rows, unsigned int cols);

/**
 * @brief Frees the memory allocated to a matrix
 *
 * @param matrix Matrix whose memory to free
 */
void destroy_matrix(Matrix *matrix);

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
Matrix *random_matrix(unsigned int rows, unsigned int cols, scalar_t min, scalar_t max);

/**
 * @brief Prints the entries of a matrix to a given precision
 *
 * @param matrix Matrix to be printed to terminal
 * @param precision Number of decimal places to print values to
 */
void print_matrix(const Matrix *matrix, unsigned int precision);

/**
 * @brief Adds two matrices together
 *
 * @param lhs Left-hand matrix
 * @param rhs Right-hand matrix
 *
 * @return Matrix with summed entries
 */
Matrix *add_matrices(const Matrix *lhs, const Matrix *rhs);

/**
 * @brief Subtracts one matrix from another
 *
 * @param lhs Left-hand matrix
 * @param rhs Right-hand matrix
 *
 * @return Matrix with subtracted entries
 */
Matrix *subtract_matrices(const Matrix *lhs, const Matrix *rhs);

/**
 * @brief Creates a copy of an existing matrix
 *
 * @param matrix Matrix to be copied
 *
 * @return Copy of given matrix
 */
Matrix *copy_matrix(const Matrix *matrix);

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
Matrix *multiply_matrices(const Matrix *lhs, const Matrix *rhs);

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
 * @brief Add a scale of one row to another in a matrix
 *
 * @param *matrix Matrix to be added to
 * @param target_row Row to be added to
 * @param source_row Row providing values to be added to target row
 * @param multiplier Scalar applied to added row
 *
 * @return 1 for successful operation, 0 for failure
 */
int add_matrix_rows(Matrix *matrix, unsigned int target_row, unsigned int source_row, scalar_t multiplier);

/**
 * @brief Scales a matrix
 *
 * @param *matrix Matrix to be scaled
 * @param scalar Value by which to scale matrix by
 *
 * @return 1 if function succeeds, 0 if it fails
 */
int scale_matrix(Matrix *matrix, scalar_t scalar);

/**
 * @brief Remove column of a matrix
 *
 * @param *matrix Source matrix
 * @param column Column to be removed
 *
 * @return Matrix with removed column
 */
Matrix *remove_column(Matrix *matrix, unsigned int column);

/**
 * @brief Remove a row of a matrix
 *
 * @param *matrix Source Matrix
 * @param target_row
 *
 * @return Matrix with row removed
 */
Matrix *remove_row(Matrix *matrix, unsigned int target_row);

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
 *
 * @param 1 for success, 0 for failure
 */
int swap_rows(Matrix *matrix, unsigned int row1, unsigned int row2);

/**
 * @brief Swap two columns of a matrix
 *
 * @param *matrix Matrix whose columns will be swapped
 * @param col1 First column
 * @param col2 Second column
 *
 * @return 1 if successful, 0 if failure
 */
int swap_cols(Matrix *matrix, unsigned int col1, unsigned int col2);

/**
 * @brief Finds first non-zero element in column, working down from a given row
 *
 * @param *matrix Matrix to be checked
 * @param row Starting row
 * @param col Column to check
 *
 * @return Pivot row
 */
int find_pivot(const Matrix *matrix, unsigned int row, unsigned int col);

/**
 * @brief Finds the largest absolute value in column under given row
 *
 * @param *matrix
 * @param row
 * @param col
 *
 * @return Row of largest value
 */
int find_pivot_max(const Matrix *matrix, unsigned int row, unsigned int col);

/**
 * @brief Creates a new matrix from a file
 *
 * @param *f File to be read from. Formatting should be two unsigned ints for rows and columns
 *           followed by the appropriate number of elements for the matrix of the given dimensions
 *
 * @return Created matrix
 */
Matrix *matrix_fromfile(FILE *f);


Matrix *vertical_concat(unsigned int matrix_num, Matrix **matrix_array);

#endif
