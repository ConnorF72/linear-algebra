#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "vector.h"
#include "matrix.h"

#define MAX 10
#define MIN 1

int main(void) {

    srand(time(NULL));

    Matrix *matrix1 = matrix_random(3, 2, MIN, MAX);
    Matrix *matrix2 = matrix_random(2, 3, MIN, MAX);

    printf("\n==== MATRIX 1 ====\n\n");
    matrix_print(matrix1, 0);

    printf("\n==== MATRIX 2 ====\n\n");
    matrix_print(matrix2, 0);

    Matrix *aug = create_augmented(matrix1, matrix2);

    printf("\n======== AUGMENTED ========\n\n");
    matrix_print(aug, 0);


    matrix_destroy(matrix1);
    matrix_destroy(matrix2);
    matrix_destroy(aug);

    return 0;
}
