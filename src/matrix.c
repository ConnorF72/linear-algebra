/****************************************

  File: matrix.c

  Author: Connor Fletcher

  Date: August 5, 2026

  Brief: A collection of functions for performing matrix operations

****************************************/

#include "matrix.h"

Matrix *matrix_create(unsigned int rows, unsigned int cols) {
    if (rows == 0 || cols == 0) {
        printf("ERROR: Cannot create matrix withouts rows/cols\n");
        return NULL;
    }

    Matrix *matrix = calloc(1, sizeof(*matrix));
    if (matrix == NULL) {
        printf("ERROR: Matrix allocation failed!\tmatrix_create\n");
        return NULL;
    }

    matrix->rows = rows;
    matrix->cols = cols;
    matrix->is_square = (rows == cols) ? 1 : 0;

    matrix->data = calloc(matrix->rows, sizeof(*matrix->data));
    if (matrix->data == NULL) {
        free(matrix);
        printf("ERROR: Data allocation failed!\tmatrix_create\n");
        return NULL;
    }

    for (int row = 0; row < matrix->rows; row++) {
        matrix->data[row] = calloc(matrix->cols, sizeof(**matrix->data));

        if (matrix->data[row] == NULL) {
            free(matrix->data);
            free(matrix);

            printf("ERROR: Row allocation failed!\tmatrix_create\n");
            return NULL;
        }
    }

    return matrix;
}

void matrix_destroy(Matrix *matrix) {
    if (matrix == NULL) return;

    for (int row = 0; row < matrix->rows; row++) {
        free(matrix->data[row]);
    }

    free(matrix->data);

    free(matrix);
}

Matrix *eye(unsigned int size) {
    Matrix *matrix = matrix_create(size, size);
    if (matrix == NULL) return NULL;

    for (int row = 0; row < matrix->rows; row++) {
        matrix->data[row][row] = 1.0;
    }

    return matrix;
}

Matrix *matrix_random(unsigned int rows, unsigned int cols, scalar_t min, scalar_t max) {
    Matrix *matrix = matrix_create(rows, cols);

    for (int row = 0; row < matrix->rows; row++) {
        for (int col = 0; col < matrix->cols; col++) {
            matrix->data[row][col] = rand_scalar(min, max);
        }
    }

    return matrix;
}

void matrix_print(const Matrix *matrix, unsigned int precision) {
    if (matrix == NULL) {
        printf("ERROR: NULL matrix passed\tmatrix_print\n");
        return;
    }
    for (int row = 0; row < matrix->rows; row++) {
        for (int col = 0; col < matrix->cols; col++) {
            printf("%.*lf\t", precision, matrix->data[row][col]);
        }
        printf("\n\n\n");
    }
}

Matrix *matrix_add(const Matrix *lhs, const Matrix *rhs) {
    if (lhs == NULL || rhs == NULL) {
        printf("ERROR: NULL matrix passed\tmatrix_add\n");
        return NULL;
    }
    if (lhs->rows != rhs->rows || lhs->cols != rhs->cols) return NULL;

    Matrix *result = matrix_create(lhs->rows, lhs->cols);

    for (int row = 0; row < result->rows; row++) {
        for (int col = 0; col < result->cols; col++) {
            result->data[row][col] = lhs->data[row][col] + rhs->data[row][col];
        }
    }

    return result;
}

Matrix *matrix_subtract(const Matrix *lhs, const Matrix *rhs) {
    if (lhs == NULL || rhs == NULL) {
        printf("ERROR: NULL matrix passed\tmatrix_subtract\n");
        return NULL;
    }
    if (lhs->rows != rhs->rows || lhs->cols != rhs->cols) return NULL;

    Matrix *result = matrix_create(lhs->rows, lhs->cols);

    for (int row = 0; row < result->rows; row++) {
        for (int col = 0; col < result->cols; col++) {
            result->data[row][col] = lhs->data[row][col] - rhs->data[row][col];
        }
    }

    return result;
}

Matrix *matrix_copy(const Matrix *matrix) {
    if (matrix == NULL) {
        printf("ERROR: NULL matrix passed\tmatrix_copy\n");
        return NULL;
    }
    Matrix *copy = matrix_create(matrix->rows, matrix->cols);

    for (int row = 0; row < matrix->rows; row++) {
        for (int col = 0; col < matrix->cols; col++) {
            copy->data[row][col] = matrix->data[row][col];
        }
    }

    return copy;
}

Matrix *transpose(const Matrix *matrix) {
    if (matrix == NULL) {
        printf("ERROR: NULL matrix passed\ttranspose\n");
        return NULL;
    }
    Matrix *transpose = matrix_create(matrix->cols, matrix->rows);

    for (int row = 0; row < transpose->rows; row++) {
        for (int col = 0; col < transpose->cols; col++) {
            transpose->data[row][col] = matrix->data[col][row];
        }
    }

    return transpose;
}

Matrix *matrix_multiply(const Matrix *lhs, const Matrix *rhs) {
    if (lhs->cols != rhs->rows) {
        printf("ERROR: NULL matrix passed.\tmatrix_multiply");
        return NULL;
    }
    Matrix *product = matrix_create(lhs->rows, rhs->cols);

    for (int i = 0; i < lhs->rows; i++) {
        for (int j = 0; j < rhs->cols; j++) {
            product->data[i][j] = 0;
            for (int k = 0; k < lhs->cols; k++) {
                product->data[i][j] += lhs->data[i][k] * rhs->data[k][j];
            }
        }
    }
    return product;
}

Matrix *create_augmented(const Matrix *lhs, const Matrix *rhs) {
    if (lhs->rows != rhs->rows) {
        printf("ERROR: Augmentation failed\n");
        return NULL;
    }

    Matrix *augmented = matrix_create(lhs->rows, (lhs->cols)+(rhs->cols));
    if (augmented == NULL) return NULL;

    for (int row = 0; row < lhs->rows; row++) {
        for (int lhs_col = 0; lhs_col < lhs->cols; lhs_col++) {
            augmented->data[row][lhs_col] = lhs->data[row][lhs_col];
        }
    }

    for (int row = 0; row < rhs->rows; row++) {
        for (int rhs_col = 0; rhs_col < rhs->cols; rhs_col++) {
            augmented->data[row][lhs->cols + rhs_col] = rhs->data[row][rhs_col];
        }
    }

    return augmented;
}

void matrix_row_add(Matrix *matrix, unsigned int row, scalar_t num) { //pass actual row index, not array index position
    if (matrix == NULL) {
        printf("ERROR: NULL matrix passed\tmatrix_row_add\n");
        return;
    }
    if (row > matrix->rows || row == 0) {
        printf("ERROR: Invalid number of rows\tmatrix_row_add\n");
        return;
    }

    if (isnan(num)) {
        printf("ERROR: NAN passed\tmatrix_row_add\n");
        return;
    }

    unsigned int row_index = row - 1; //for proper array indexing

    for (int i = 0; i < matrix->cols; i++) {
        matrix->data[row_index][i] += num;
    }
}

void scale_row(Matrix *matrix, unsigned int row, scalar_t scalar) {
    if (matrix == NULL) {
        printf("ERROR: NULL matrix passed\tmatrix_row_add\n");
        return;
    }
    if (row > matrix->rows || row == 0) {
        printf("ERROR: Invalid number of rows\tmatrix_row_add\n");
        return;
    }

    if (isnan(scalar)) {
        printf("ERROR: NAN passed\tmatrix_row_add\n");
        return;
    }

    unsigned int row_index = row - 1;

    for (int i = 0; i < matrix->cols; i++) {
        matrix->data[row_index][i] *= scalar;
    }
}

void swap_rows(Matrix *matrix, unsigned int row1, unsigned int row2) {
    if (matrix == NULL) {
        printf("ERROR: NULL matrix passed\tswap_rows\n");
        return;
    }

    if (matrix->data == NULL) {
        printf("ERROR: NULL data passed\tswap_rows\n");
        return;
    }

    if (row1 > matrix->rows || row2 > matrix->rows) {
        printf("ERROR: Invalid row index\t\tswap_rows\n");
        return;
    }

    if (row1 == row2) {
        printf("ERROR: Cannot swap rows:\t\tswap_rows\n");
        return;
    }

    if (row1 == 0 || row2 == 0) {
        return;
    }

    unsigned int row1_index = row1 - 1;
    unsigned int row2_index = row2 - 1;

    scalar_t *temp = matrix->data[row1_index];
    matrix->data[row1_index] = matrix->data[row2_index];
    matrix->data[row2_index] = temp;
}

//to do
Matrix *rref(const Matrix *matrix) {
    if (matrix == NULL) {
        printf("ERROR: NULL matrix passed\trref\n");
        return NULL;
    }
    Matrix *reduced = matrix_copy(matrix);
    if (reduced == NULL) {
        printf("ERROR: Matrix allocation failed\trref\n");
        return NULL;
    }


    return reduced;
}
