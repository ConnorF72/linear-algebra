/****************************************

  File: vector.c

  Author: Connor Fletcher

  Date: August 06, 2026

  Brief: Functions performing fundamental vector operations

 ****************************************/

#include "vector.h"

Vector *vector_create(unsigned int size) {
    if (size == 0) {
        printf("ERROR: Cannot create a vector with no dimensions\tvector_create\n");
        return NULL;
    }

    Vector *new_vector = calloc(1, sizeof(*new_vector));

    if (new_vector == NULL) {
        printf("ERROR: Vector allocation failed\tvector_create\n");
        return NULL;
    }

    new_vector->size = size;

    new_vector->data = calloc(size, sizeof(scalar_t));

    if (new_vector->data == NULL) {
        printf("ERROR: Vector data allocation failed\tvector_create\n");
        free(new_vector);
        return NULL;
    }

    return new_vector;
}


void vector_destroy(Vector *vector) {
    if (vector == NULL) {
        printf("ERROR: NULL vector passed\tvector_destroy\n");
        return;
    }

    free(vector->data);
    free(vector);
}


Vector *vector_copy(const Vector *vector) {
    if (vector == NULL) {
        printf("ERROR: NULL vector passed\tvector_copy\n");
        return NULL;
    }

    Vector *copy = vector_create(vector->size);

    if (copy == NULL) {
        printf("ERROR: Vector allocation failed\tvector_copy\n");
        return NULL;
    }

    for (unsigned int i = 0; i < copy->size; i++) {
        copy->data[i] = vector->data[i];
    }

    return copy;
}


Vector *vector_add(const Vector *first_vector, const Vector *second_vector) {
    if (first_vector == NULL || second_vector == NULL) {
        printf("ERROR: NULL vector passed\tvector_add\n");
        return NULL;
    }

    if (first_vector->size != second_vector->size) {
        printf("ERROR: Vector dimensions must match\tvector_add\n");
        return NULL;
    }

    Vector *sum = vector_create(first_vector->size);

    if (sum == NULL) {
        printf("ERROR: Vector allocation failed\tvector_add\n");
        return NULL;
    }

    for (unsigned int i = 0; i < sum->size; i++) {
        sum->data[i] =
            first_vector->data[i] +
            second_vector->data[i];
    }

    return sum;
}


Vector *vector_subtract(const Vector *first_vector, const Vector *second_vector) {
    if (first_vector == NULL || second_vector == NULL) {
        printf("ERROR: NULL vector passed\tvector_subtract\n");
        return NULL;
    }

    if (first_vector->size != second_vector->size) {
        printf("ERROR: Vector dimensions must match\tvector_subtract\n");
        return NULL;
    }

    Vector *difference = vector_create(first_vector->size);

    if (difference == NULL) {
        printf("ERROR: Vector allocation failed\tvector_subtract\n");
        return NULL;
    }

    for (unsigned int i = 0; i < difference->size; i++) {
        difference->data[i] =
            first_vector->data[i] -
            second_vector->data[i];
    }

    return difference;
}


scalar_t dot(const Vector *first_vector, const Vector *second_vector) {
    if (first_vector == NULL || second_vector == NULL) {
        printf("ERROR: NULL vector passed\tdot\n");
        return NAN;
    }

    if (first_vector->size != second_vector->size) {
        printf("ERROR: Vector dimensions must match\tdot\n");
        return DIMENSION_ERROR;
    }

    scalar_t dot_product = 0;

    for (unsigned int i = 0; i < first_vector->size; i++) {
        dot_product +=
            first_vector->data[i] *
            second_vector->data[i];
    }

    return dot_product;
}


Vector *cross(const Vector *lhs, const Vector *rhs) {
    if (lhs == NULL || rhs == NULL) {
        printf("ERROR: NULL vector passed\tcross\n");
        return NULL;
    }

    if (lhs->size != 3 || rhs->size != 3) {
        printf("ERROR: Cross product requires 3D vectors\tcross\n");
        return NULL;
    }

    Vector *cross_product = vector_create(VECTOR_3D);

    if (cross_product == NULL) {
        printf("ERROR: Vector allocation failed\tcross\n");
        return NULL;
    }

    cross_product->data[0] =
        lhs->data[1] * rhs->data[2] -
        lhs->data[2] * rhs->data[1];

    cross_product->data[1] =
        lhs->data[2] * rhs->data[0] -
        lhs->data[0] * rhs->data[2];

    cross_product->data[2] =
        lhs->data[0] * rhs->data[1] -
        lhs->data[1] * rhs->data[0];

    return cross_product;
}


scalar_t mag(const Vector *vector) {
    if (vector == NULL) {
        printf("ERROR: NULL vector passed\tmag\n");
        return NAN;
    }

    scalar_t magnitude_squared = 0;

    for (unsigned int i = 0; i < vector->size; i++) {
        magnitude_squared +=
            vector->data[i] *
            vector->data[i];
    }

    return sqrt(magnitude_squared);
}


Vector *norm(const Vector *vector) {
    if (vector == NULL) {
        printf("ERROR: NULL vector passed\tnorm\n");
        return NULL;
    }

    scalar_t magnitude = mag(vector);

    if (magnitude == 0) {
        printf("ERROR: Cannot normalize a zero vector\tnorm\n");
        return NULL;
    }

    Vector *norm = vector_create(vector->size);

    if (norm == NULL) {
        printf("ERROR: Vector allocation failed\tnorm\n");
        return NULL;
    }

    for (unsigned int i = 0; i < norm->size; i++) {
        norm->data[i] =
            vector->data[i] / magnitude;
    }

    return norm;
}


Vector *proj(const Vector *vec1, const Vector *vec2) {
    if (vec1 == NULL || vec2 == NULL) {
        printf("ERROR: NULL vector passed\tproj\n");
        return NULL;
    }

    if (vec1->size != vec2->size) {
        printf("ERROR: Vector dimensions must match\tproj\n");
        return NULL;
    }

    scalar_t mag2 = mag(vec2);

    if (mag2 == 0) {
        printf("ERROR: Cannot project onto a zero vector\tproj\n");
        return NULL;
    }

    Vector *projection = vector_create(vec1->size);

    if (projection == NULL) {
        printf("ERROR: Vector allocation failed\tproj\n");
        return NULL;
    }

    scalar_t scalar =
        dot(vec1, vec2) /
        (mag2 * mag2);

    for (unsigned int i = 0; i < projection->size; i++) {
        projection->data[i] =
            scalar * vec2->data[i];
    }

    return projection;
}


void vector_scale(Vector *vector, scalar_t scalar) {
    if (vector == NULL) {
        printf("ERROR: NULL vector passed\tvector_scale\n");
        return;
    }

    for (unsigned int i = 0; i < vector->size; i++) {
        vector->data[i] *= scalar;
    }
}


scalar_t rand_scalar(scalar_t min, scalar_t max) {
    return min +
        ((scalar_t)rand() / RAND_MAX) *
        (max - min);
}

unsigned int rand_uint(unsigned int min, unsigned int max) {
    return (rand() % (max - min + 1)) + min; // don't know if needed yet; might delete
}

bool are_parallel(const Vector *vec1, const Vector *vec2) {
    if (vec1 == NULL || vec2 == NULL) {
        printf("ERROR: NULL vector passed\tare_parallel\n");
        return false;
    }

    if (vec1->size != 3 || vec2->size != 3) {
        printf("ERROR: Parallel check requires 3D vectors\tare_parallel\n");
        return false;
    }

    Vector *cross_product = cross(vec1, vec2);

    if (cross_product == NULL) {
        return false;
    }

    for (unsigned int i = 0; i < cross_product->size; i++) {
        if (fabs(cross_product->data[i]) > EPSILON) {
            vector_destroy(cross_product);
            return false;
        }
    }

    vector_destroy(cross_product);
    return true;
}


bool are_orthogonal(const Vector *vec1, const Vector *vec2) {
    if (vec1 == NULL || vec2 == NULL) {
        printf("ERROR: NULL vector passed\tare_orthogonal\n");
        return false;
    }

    if (vec1->size != vec2->size) {
        printf("ERROR: Vector dimensions must match\tare_orthogonal\n");
        return false;
    }

    scalar_t dot_product = dot(vec1, vec2);

    return fabs(dot_product) < EPSILON;
}


bool is_zero(const Vector *vector) {
    if (vector == NULL) {
        printf("ERROR: NULL vector passed\tis_zero\n");
        return false;
    }

    return mag(vector) < EPSILON;
}


scalar_t angle(const Vector *vec1, const Vector *vec2) {
    if (vec1 == NULL || vec2 == NULL) {
        printf("ERROR: NULL vector passed\tangle\n");
        return NAN;
    }

    if (vec1->size != vec2->size) {
        printf("ERROR: Vector dimensions must match\tangle\n");
        return DIMENSION_ERROR;
    }

    scalar_t mag1 = mag(vec1);
    scalar_t mag2 = mag(vec2);

    if (mag1 == 0 || mag2 == 0) {
        printf("ERROR: Cannot calculate angle with zero vector\tangle\n");
        return NAN;
    }

    scalar_t phi =
        dot(vec1, vec2) /
        (mag1 * mag2);

    if (phi > 1) {
        phi = 1;
    }

    if (phi < -1) {
        phi = -1;
    }

    return acos(phi);
}


scalar_t distance(const Vector *vec1, const Vector *vec2) {
    if (vec1 == NULL || vec2 == NULL) {
        printf("ERROR: NULL vector passed\tdistance\n");
        return NAN;
    }

    if (vec1->size != vec2->size) {
        printf("ERROR: Vector dimensions must match\tdistance\n");
        return DIMENSION_ERROR;
    }

    scalar_t distance_squared = 0;

    for (unsigned int i = 0; i < vec1->size; i++) {
        scalar_t difference =
            vec1->data[i] -
            vec2->data[i];

        distance_squared += difference * difference;
    }

    return sqrt(distance_squared);
}


void vector_set(Vector *vector, const scalar_t *values) {
    if (vector == NULL) {
        printf("ERROR: NULL vector passed\tvector_set\n");
        return;
    }

    if (values == NULL) {
        printf("ERROR: NULL values passed\tvector_set\n");
        return;
    }

    for (unsigned int i = 0; i < vector->size; i++) {
        vector->data[i] = values[i];
    }
}
