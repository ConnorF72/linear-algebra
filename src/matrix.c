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
