/*****************************

File: matrix.c

Author: Connor Fletcher

Date: August 5, 2026

Brief: A collection of functions for performing matrix operations

 *****************************/

#include "matrix.h"

Matrix *new_matrix(unsigned int num_rows, unsigned int num_cols) {
    if (num_rows == 0 || num_cols == 0) {
        return NULL;
    }

    Matrix *m = calloc(1, sizeof(*m));

    m->num_rows = num_rows;
    m->num_cols = num_cols;
    m->is_square = (num_rows == num_cols) ? 1 : 0;

    m->data = calloc(m->num_rows, sizeof(*m->data));

    for (int i = 0; i < m->num_rows; i++) {
        m->data[i] = calloc(m->num_cols, sizeof(**m->data));
    }

    return m;
}

void free_matrix(Matrix *m) {
    if (m == NULL) return;

    for (int i = 0; i < m->num_rows; i++) {
        free(m->data[i]);
    }

    free(m->data);

    free(m);
}

Matrix *new_identity_matrix(unsigned int size) {
    Matrix *m = new_matrix(size, size);
    if (m == NULL) return NULL;

    for (int i = 0; i < m->num_rows; i++) {
        m->data[i][i] = 1.0;
    }
    return m;
}

Matrix *rand_matrix(unsigned int num_rows, unsigned int num_cols, double min, double max) {

    Matrix *m = new_matrix(num_rows, num_cols);
    for (int i = 0; i < m->num_rows; i++) {
        for (int j = 0; j < m-> num_cols; j++) {
            m->data[i][j] = rand_double(min, max);
        }
    }
    return m;
}

void print_matrix(Matrix *mat, int precision) {
    for (int i = 0; i < mat->num_rows; i++) {
        for (int j = 0; j < mat->num_cols; j++) {
            printf("%.*lf\t", precision, mat->data[i][j]);
        }
        printf("\n");
    }
}

Matrix *add_matrices(const Matrix *mat1, const Matrix *mat2){
    if (mat1 == NULL || mat2 == NULL) return NULL;
    if (mat1->num_rows != mat2->num_rows || mat1->num_cols != mat2->num_cols) return NULL;

    Matrix *m = new_matrix(mat1->num_rows, mat1->num_cols);

    for (int i = 0; i < m->num_rows; i++) {
        for (int j = 0; j < m->num_cols; j++) {
            m->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }
    return m;
}

Matrix *subtract_matrices(const Matrix *mat1, const Matrix *mat2){
    if (mat1 == NULL || mat2 == NULL) return NULL;
    if (mat1->num_rows != mat2->num_rows || mat1->num_cols != mat2->num_cols) return NULL;

    Matrix *m = new_matrix(mat1->num_rows, mat1->num_cols);

    for (int i = 0; i < m->num_rows; i++) {
        for (int j = 0; j < m->num_cols; j++) {
            m->data[i][j] = mat1->data[i][j] - mat2->data[i][j];
        }
    }
    return m;
}
