/****************************************

File: vector.c

Author: Connor Fletcher

Date: August 06, 2026

Brief: Functions performing fundamental vector operations

****************************************/

#include "vector.h"

Vector *vector_create(unsigned int size) {
    if (size == 0) return NULL;
    Vector *new_vector = calloc(1, sizeof(new_vector->data));

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

scalar_t vector_dot(const Vector *first_vector, const Vector *second_vector) {
    if (first_vector->size != second_vector->size) return NUMBER_ERROR;
    scalar_t dot_product = 0;
    for (int i = 0; i < first_vector->size; i++) {
        dot_product += first_vector->data[i] * second_vector->data[i];
    }
    return dot_product;
}

Vector *vector_cross(const Vector *lhs, const Vector *rhs) {
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
