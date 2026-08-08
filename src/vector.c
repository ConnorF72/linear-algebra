/****************************************

File: vector.c

Author: Connor Fletcher

Date: August 06, 2026

Brief: Functions performing fundamental vector operations

****************************************/

#include "vector.h"

Vector *vector_create(unsigned int size) {
    if (size == 0) return NULL;
    Vector *new_vector = calloc(1, sizeof(*new_vector));

    new_vector->size = size;

    new_vector->data = calloc(size, sizeof(scalar_t));
    if (new_vector->data == NULL) {
        free(new_vector);
        return NULL;
    }

    return new_vector;
}

void vector_destroy(Vector *vector) {
    if (vector == NULL) return;

    free(vector->data);
    free(vector);
}

Vector *vector_copy(const Vector *vector) {
    if (vector == NULL) return NULL;

    Vector *copy = vector_create(vector->size);
    if (copy == NULL) return NULL;

    for (int i = 0; i < copy->size; i++) {
        copy->data[i] = vector->data[i];
    }

    return copy;
}

Vector *vector_add(const Vector *first_vector, const Vector *second_vector) {
    if (first_vector->size != second_vector->size) return NULL;

    Vector *sum = vector_create(first_vector->size);

    if (sum == NULL) return NULL;

    for (int i = 0; i < sum->size; i++) {
        sum->data[i] = first_vector->data[i] + second_vector->data[i];
    }

    return sum;
}

Vector *vector_subtract(const Vector *first_vector, const Vector *second_vector) {
    if (first_vector->size != second_vector->size) return NULL;

    Vector *difference = vector_create(first_vector->size);

    if (difference == NULL) return NULL;

    for (int i = 0; i < difference->size; i++) {
        difference->data[i] = first_vector->data[i] - second_vector->data[i];
    }

    return difference;
}

scalar_t dot(const Vector *first_vector, const Vector *second_vector) {
    if (first_vector->size != second_vector->size) return DIMENSION_ERROR;
    scalar_t dot_product = 0;
    for (int i = 0; i < first_vector->size; i++) {
        dot_product += first_vector->data[i] * second_vector->data[i];
    }
    return dot_product;
}

Vector *cross(const Vector *lhs, const Vector *rhs) {
    if (lhs->size != 3) return NULL;
    if (rhs->size != 3) return NULL;

    Vector *cross_product = vector_create(VECTOR_3D);

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
    scalar_t mag = 0;

    for (int i = 0; i < vector->size; i++) {
        mag += vector->data[i] * vector->data[i];
    }

    return sqrt(mag);
}

Vector *norm(const Vector *vector) {
    if (vector == NULL) return NULL;

    scalar_t magnitude = mag(vector);
    if (magnitude == 0) return NULL;

    Vector *norm = vector_create(vector->size);
    if (norm == NULL) return NULL;

    for (int i = 0; i < norm->size; i++) {
        norm->data[i] = vector->data[i] / magnitude;
    }

    return norm;
}

Vector *proj(const Vector *vec1, const Vector *vec2) {
    if (vec1->size != vec2->size) return NULL;

    scalar_t mag2 = mag(vec2);
    if (mag2 == 0) return NULL;

    Vector *projection = vector_create(vec1->size);
    if (projection == NULL) return NULL;

    scalar_t scalar =
        dot(vec1, vec2) / (mag2 * mag2);

    for (int i = 0; i < projection->size; i++) {
        projection->data[i] = scalar * vec2->data[i];
    }

    return projection;
}

void vector_scale(Vector *vector, scalar_t scalar) {
    for (int i = 0; i < vector->size; i++) {
        vector->data[i] *= scalar;
    }
}

scalar_t rand_scalar(scalar_t min, scalar_t max) {
    return min + ((scalar_t)rand() / RAND_MAX) * (max - min);
}

bool are_parallel(const Vector *vec1, const Vector *vec2) {
    Vector *cross_product = cross(vec1, vec2);

    if (cross_product == NULL) return NULL;

    for (int i = 0; i < cross_product->size; i++) {
        if (cross_product->data[i] != 0) {
            free(cross_product);
            return false;
        }
    }

    free(cross_product);
    return true;
}

bool are_orthogonal(const Vector *vec1, const Vector *vec2) {
    scalar_t dot_product = dot(vec1, vec2);
    if (fabs(dot_product) < EPSILON) return true;

    return false;
}

bool is_zero (const Vector *vector) {
    if (mag(vector) < EPSILON) return true;

    return false;
}

scalar_t angle(const Vector *vec1, const Vector *vec2) {
    if (vec1->size != vec2->size) return DIMENSION_ERROR;

    scalar_t mag1 = mag(vec1);
    scalar_t mag2 = mag(vec2);

    if (mag1 == 0 || mag2 == 0) return NAN;

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
    if (vec1->size != vec2->size) return DIMENSION_ERROR;
    scalar_t distance_squared = 0;

    for (int i = 0; i < vec1->size; i++) {
        distance_squared += (vec1->data[i] - vec2->data[i]) * (vec1->data[i] - vec2->data[i]);
    }

    return sqrt(distance_squared);
}

void vector_set(Vector *vector, const scalar_t *values) {
    for (int i = 0; i < vector->size; i++) {
        vector->data[i] = values[i]; // to do: consider what to do if wrong number of values passed
    }
}
