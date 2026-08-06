#include <stdio.h>
#include "vector.h"
#include "matrix.h"


int main(void) {
    Matrix *m = new_identity_matrix(3);

    for (int i = 0; i < m->num_rows; i++) {
        for (int j = 0; j < m->num_cols; j++) {
            printf("%.0lf\t", m->data[i][j]);
        }
        printf("\n");
    }

    return 0;
}
