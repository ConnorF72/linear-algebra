#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "vector.h"
#include "matrix.h"

#define MAX 10
#define MIN 1

int main(void) {

    srand(time(NULL));

    Matrix *matrix = matrix_random(3, 3, MIN, MAX);

    printf("\n==== MATRIX ====\n\n");
    matrix_print(matrix, 0);


    matrix_destroy(matrix);

    return 0;
}
