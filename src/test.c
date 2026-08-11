#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "vector.h"
#include "matrix.h"

#define MAX 10
#define MIN 1

int main(void) {

    srand(time(NULL));

    Matrix *matrix1 = matrix_random(3, 3, MIN, MAX);

    printf("\n\n===== MATRIX =====\n\n");
    matrix_print(matrix1, 0);

    Matrix *matrix2 = remove_row(matrix1, 1);

    printf("\n\n===== REMOVE ROW =====\n\n");
    matrix_print(matrix2, 0);

    matrix_destroy(matrix1);
    matrix_destroy(matrix2);

    return 0;
}
