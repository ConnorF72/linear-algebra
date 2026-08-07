#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "vector.h"
#include "matrix.h"

#define MAX 10
#define MIN 1

int main(void) {

    srand(time(NULL));

    /*
    Matrix *matrix1 = matrix_random(3, 3, MIN, MAX);
    Matrix *matrix2 = matrix_random(3, 3, MIN, MAX);

    printf("\n======== MATRIX 1 ========\n\n");
    matrix_print(matrix1, 6);

    printf("\n======== MATRIX 2 ========\n\n");
    matrix_print(matrix2, 6);

    Matrix *product = matrix_multiply(matrix1, matrix2);

    printf("\n======== PRODUCT ========\n\n");
    matrix_print(product, 6);


    matrix_destroy(matrix1);
    matrix_destroy(matrix2);
    matrix_destroy(product);
*/

    Matrix *i = matrix_identity(5);
    matrix_print(i, 0);
    return 0;
}
