#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "vector.h"
#include "matrix.h"

#define MAX 10
#define MIN 1

int main(void) {
    /*
    FILE *file = fopen("matrix_from_file.txt", "r");

    if (file == NULL) {
        printf("ERROR ACCESSING FILE\n");
        exit(1);
    }
    */

    srand(time(NULL));

    Matrix *m1 = random_matrix(3, 3, MIN, MAX);
    Matrix *m2 = random_matrix(3, 3, MIN, MAX);

    Matrix *arr[64] = {m1, m2};

    Matrix *m3 = vertical_concat(2, arr);

    print_matrix(m3, 0);

    destroy_matrix(m1);
    destroy_matrix(m2);
    destroy_matrix(m3);
    return 0;
}
