#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "vector.h"
#include "matrix.h"

#define MAX 10
#define MIN 1

int main(void) {

    srand(time(NULL));

    Matrix *square = matrix_random(3, 3, MIN, MAX);

    printf("\n======== SQUARE MATRIX ========\n\n");
    matrix_print(square, 0);

    Matrix *square_transpose = matrix_transpose(square);

    printf("\n======== TRANSPOSE ========\n\n");
    matrix_print(square_transpose, 0);

    Matrix *rectangular = matrix_random(2, 3, MIN, MAX);

    printf("\n======== 2 x 3 MATRIX ========\n\n");
    matrix_print(rectangular, 0);

    Matrix *rectangular_transpose = matrix_transpose(rectangular);

    printf("\n======== TRANSPOSE ========\n\n");
    matrix_print(rectangular_transpose, 0);

    matrix_destroy(square);
    matrix_destroy(square_transpose);
    matrix_destroy(rectangular);
    matrix_destroy(rectangular_transpose);

    return 0;
}
