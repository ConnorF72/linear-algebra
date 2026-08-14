/****************************************

  File: matrix.c

  Author: Connor Fletcher

  Date: August 5, 2026

  Brief: A collection of functions for performing matrix operations

****************************************/

#include "matrix.h"

Matrix *create_matrix(unsigned int rows, unsigned int cols) {
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

void destroy_matrix(Matrix *matrix) {
    if (matrix == NULL) return;

    for (int row = 0; row < matrix->rows; row++) {
        free(matrix->data[row]);
    }

    free(matrix->data);

    free(matrix);
}

Matrix *eye(unsigned int size) {
    Matrix *matrix = create_matrix(size, size);
    if (matrix == NULL) return NULL;

    for (int row = 0; row < matrix->rows; row++) {
        matrix->data[row][row] = 1.0;
    }

    return matrix;
}

Matrix *random_matrix(unsigned int rows, unsigned int cols, scalar_t min, scalar_t max) {
    Matrix *matrix = create_matrix(rows, cols);

    for (int row = 0; row < matrix->rows; row++) {
        for (int col = 0; col < matrix->cols; col++) {
            matrix->data[row][col] = rand_scalar(min, max);
        }
    }

    return matrix;
}

void print_matrix(const Matrix *matrix, unsigned int precision) {
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

Matrix *add_matrices(const Matrix *lhs, const Matrix *rhs) {
    if (lhs == NULL || rhs == NULL) {
        printf("ERROR: NULL matrix passed\tmatrix_add\n");
        return NULL;
    }
    if (lhs->rows != rhs->rows || lhs->cols != rhs->cols) return NULL;

    Matrix *result = create_matrix(lhs->rows, lhs->cols);

    for (int row = 0; row < result->rows; row++) {
        for (int col = 0; col < result->cols; col++) {
            result->data[row][col] = lhs->data[row][col] + rhs->data[row][col];
        }
    }

    return result;
}

Matrix *subtract_matrices(const Matrix *lhs, const Matrix *rhs) {
    if (lhs == NULL || rhs == NULL) {
        printf("ERROR: NULL matrix passed\tmatrix_subtract\n");
        return NULL;
    }
    if (lhs->rows != rhs->rows || lhs->cols != rhs->cols) return NULL;

    Matrix *result = create_matrix(lhs->rows, lhs->cols);

    for (int row = 0; row < result->rows; row++) {
        for (int col = 0; col < result->cols; col++) {
            result->data[row][col] = lhs->data[row][col] - rhs->data[row][col];
        }
    }

    return result;
}

Matrix *copy_matrix(const Matrix *matrix) {
    if (matrix == NULL) {
        printf("ERROR: NULL matrix passed\tmatrix_copy\n");
        return NULL;
    }
    Matrix *copy = create_matrix(matrix->rows, matrix->cols);

    for (int row = 0; row < matrix->rows; row++) {
        for (int col = 0; col < matrix->cols; col++) {
            copy->data[row][col] = matrix->data[row][col];
        }
    }

    return copy;
}

void matcopy(const Matrix *source_matrix, Matrix *copy) {

}

Matrix *transpose(const Matrix *matrix) {
    if (matrix == NULL) {
        printf("ERROR: NULL matrix passed\ttranspose\n");
        return NULL;
    }
    Matrix *transpose = create_matrix(matrix->cols, matrix->rows);

    for (int row = 0; row < transpose->rows; row++) {
        for (int col = 0; col < transpose->cols; col++) {
            transpose->data[row][col] = matrix->data[col][row];
        }
    }

    return transpose;
}

Matrix *multiply_matrices(const Matrix *lhs, const Matrix *rhs) {
    if (lhs->cols != rhs->rows) {
        printf("ERROR: NULL matrix passed.\tmatrix_multiply");
        return NULL;
    }
    Matrix *product = create_matrix(lhs->rows, rhs->cols);

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

    Matrix *augmented = create_matrix(lhs->rows, (lhs->cols)+(rhs->cols));
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
int add_matrix_rows(Matrix *matrix, unsigned int target_row, unsigned int source_row, scalar_t multiplier) {
    if (target_row >= matrix->rows || source_row >= matrix->rows) {
        return 0;
    }

    for (int i = 0; i < matrix->cols; i++) {
        matrix->data[target_row][i] += matrix->data[source_row][i] * multiplier;
    }
    return 1;
}

int scale_matrix(Matrix *matrix, scalar_t scalar) {
    if (matrix == NULL) return 0;

    for (int row = 0; row < matrix->rows; row++) {
        for (int col = 0; col < matrix->cols; col++) {
            matrix->data[row][col] *= scalar;
        }
    }
    return 1;
}

Matrix *remove_column(Matrix *matrix, unsigned int column) {
    if (column >= matrix->cols) return NULL;

    Matrix *removed = create_matrix(matrix->rows, matrix->cols - 1);
    if (removed == NULL) return NULL;

    for (int row = 0; row < matrix->rows; row++) {
        for (int col = 0; col < matrix->cols; col++) {
            if (col != column) {
                removed->data[row][col] = matrix->data[row][col];
            }
        }
    }
   return removed;
}

Matrix *remove_row(Matrix *matrix, unsigned int target_row) {
    if (target_row >= matrix->rows) return NULL;

    Matrix *removed = create_matrix(matrix->rows - 1, matrix->cols);
    if (removed == NULL) return NULL;

    for (int row = 0, dest = 0; row < matrix->rows; row++) {
        if (row != target_row) {
            for (int col = 0; col < matrix->cols; col++) {
                removed->data[dest][col] = matrix->data[row][col];
            }
            dest++;
        }
    }
    return removed;
}

void scale_row(Matrix *matrix, unsigned int row, scalar_t scalar) { //To do: figure out standard error procedure
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

    for (int i = 0; i < matrix->cols; i++) {
        matrix->data[row][i] *= scalar;
    }
}

int swap_rows(Matrix *matrix, unsigned int row1, unsigned int row2) {
    if (row1 >= matrix->rows || row2 >= matrix->rows) return 0;

    scalar_t *temp = matrix->data[row1];
    matrix->data[row1] = matrix->data[row2];
    matrix->data[row2] = temp;

    return 1;
}

int swap_cols(Matrix *matrix, unsigned int col1, unsigned int col2) {
    if (col1 >= matrix->cols || col2 >= matrix->cols) return 0;

    scalar_t temp;
    for (int row = 0; row < matrix->rows; row++) {
        temp = matrix->data[row][col1];
        matrix->data[row][col1] = matrix->data[row][col2];
        matrix->data[row][col2] = temp;
    }
    return 1;
}

int find_pivot(const Matrix *matrix, unsigned int row, unsigned int col){
    for (int i = 0; i < matrix->rows; i++) {
        if (fabs(matrix->data[i][col]) > EPSILON) {
            return i;
        }
    }
    return -1;
}

int find_pivot_max(const Matrix *matrix, unsigned int row, unsigned int col) {
    int max_index = row;
    scalar_t max_value = fabs(matrix->data[row][col]);

    for (int i = row + 1; i < matrix->rows; i++) {
        scalar_t current_value = fabs(matrix->data[i][col]);
        if (current_value > max_value) {
            max_value = current_value;
            max_index = i;
        }
    }
    return (max_value > EPSILON) ? max_index: -1;
}

Matrix *matrix_fromfile(FILE *f) {
    unsigned int num_rows = 0, num_cols = 0;

    if (fscanf(f, "%u %u", &num_rows, &num_cols) != 2) {
        printf("ERROR: Improper dimensions in file\n");
        return NULL;
    }

    Matrix *read = create_matrix(num_rows, num_cols);
    if (read == NULL) return NULL;

    for (int row = 0; row < num_rows; row++) {
        for (int col = 0; col < num_cols; col++) {
            if (fscanf(f, "%lf", &read->data[row][col]) != 1) {
                printf("ERROR: Format error in file\n");
                destroy_matrix(read);
                return NULL;
            }
        }
    }
    return read;
}

Matrix *vertical_concat(unsigned int matrix_num, Matrix **matrix_array) {
    if (matrix_num == 0) return NULL;
    if (matrix_num == 1) return copy_matrix(matrix_array[0]);

    unsigned int total_rows = 0;
    unsigned int total_cols = matrix_array[0]->cols;

    for (int i = 0; i < matrix_num; i++) {
        if (matrix_array[i] == NULL) return NULL;
        if (total_cols != matrix_array[i]->cols) return NULL;
        total_rows += matrix_array[i]->rows;
    }

    Matrix *concat = create_matrix(total_rows, total_cols);
    if (concat == NULL) return NULL;

    unsigned int current_row = 0;
    for (int i = 0; i < matrix_num; i++) {
        for (int j = 0; j < matrix_array[i]->rows; j++) {
            //implement once new memcopy() is running
            current_row++;
        }
    }

    return concat;
}
