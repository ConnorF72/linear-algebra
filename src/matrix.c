/****************************************
File: matrix.c

Author: Connor Fletcher

Date: August 5, 2026

Brief: A collection of functions for performing matrix operations

****************************************/

#include "matrix.h"

Matrix *matrix_create(unsigned int rows, unsigned int cols) {
    if (rows == 0 || cols == 0) {
        return NULL;
    }

    Matrix *matrix = calloc(1, sizeof(*matrix));

    matrix->rows = rows;
    matrix->cols = cols;
    matrix->is_square = (rows == cols) ? 1 : 0;

    matrix->data = calloc(matrix->rows, sizeof(*matrix->data));

    for (int row = 0; row < matrix->rows; row++) {
        matrix->data[row] = calloc(matrix->cols, sizeof(**matrix->data));
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

Matrix *matrix_identity(unsigned int size) {
    Matrix *matrix = matrix_create(size, size);
    if (matrix == NULL) return NULL;

    for (int row = 0; row < matrix->rows; row++) {
        matrix->data[row][row] = 1.0;
    }

    return matrix;
}

Matrix *matrix_random(unsigned int rows, unsigned int cols, double min, double max) {

    Matrix *matrix = matrix_create(rows, cols);

    for (int row = 0; row < matrix->rows; row++) {
        for (int col = 0; col < matrix->cols; col++) {
            matrix->data[row][col] = rand_double(min, max);
        }
    }

    return matrix;
}

void matrix_print(const Matrix *matrix, int precision) {
    for (int row = 0; row < matrix->rows; row++) {
        for (int col = 0; col < matrix->cols; col++) {
            printf("%.*lf\t", precision, matrix->data[row][col]);
        }
        printf("\n");
    }
}

Matrix *matrix_add(const Matrix *lhs, const Matrix *rhs) {
    if (lhs == NULL || rhs == NULL) return NULL;
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
    if (lhs == NULL || rhs == NULL) return NULL;
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
    Matrix *copy = matrix_create(matrix->rows, matrix->cols);

    for (int row = 0; row < matrix->rows; row++) {
        for (int col = 0; col < matrix->cols; col++) {
            copy->data[row][col] = matrix->data[row][col];
        }
    }

    return copy;
}

Matrix *matrix_transpose(const Matrix *matrix) {
    Matrix *transpose = matrix_create(matrix->cols, matrix->rows);

    for (int row = 0; row < transpose->rows; row++) {
        for (int col = 0; col < transpose->cols; col++) {
            transpose->data[row][col] = matrix->data[col][row];
        }
    }

    return transpose;
}

Matrix *matrix_multiply(const Matrix *lhs, const Matrix *rhs) {
    Matrix *product = matrix_create(lhs->rows, rhs->cols);


    return product;
}
