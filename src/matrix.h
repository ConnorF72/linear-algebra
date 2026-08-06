#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int num_rows;
    unsigned int num_cols;
    double **data;
    int is_square;
} Matrix;

#endif

Matrix *new_matrix(unsigned int num_rows, unsigned int num_cols);
void free_matrix(Matrix *mat);
Matrix *new_identity_matrix(unsigned int size);
