#include <stdio.h>
#include "vector.h"
#include "matrix.h"
#define MAX 10
#define MIN 1


int main(void) {

    srand(time(NULL));

    Matrix *m1 = rand_matrix(3, 3, MAX, MIN);
    Matrix *m2 = rand_matrix(3, 3, MAX, MIN);

    printf("\n=====MATRIX 1=====\n\n");
    print_matrix(m1, 3);
    printf("\n\n=====MATRIX 2=====\n\n");
    print_matrix(m2, 3);

    Matrix *m3 = add_matrices(m1, m2);

    printf("\n\n=====SUMMED MATRIX=====\n\n");
    print_matrix(m3, 3);

    Matrix *m4 = subtract_matrices(m1, m2);

    printf("\n\n=====SUBTRACTED MATRIX=====\n\n");
    print_matrix(m4, 0);

    return 0;
}
