/*****************************

File: vector.c

Author: Connor Fletcher

Date: July 30, 2026

Brief: Functions performing fundamental vector operations

******************************/

#include "vector.h"

Vector add(Vector vec1, Vector vec2) {
    Vector sum = {
        .x = vec1.x + vec2.x,
        .y = vec1.y + vec2.y,
        .z = vec1.z + vec2.z
    };
    return sum;
}

Vector subtract(Vector vec1, Vector vec2) {
    Vector difference = {
        .x = vec1.x - vec2.x,
        .y = vec1.y - vec2.y,
        .z = vec1.z - vec2.z
    };
    return difference;
}

scalar_t dot(Vector vec1, Vector vec2) {
    return (vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z);
}

Vector cross(Vector vec1, Vector vec2) {
    Vector product = {
        .x = (vec1.y * vec2.z) - (vec1.z * vec2.y),
        .y = (vec1.z * vec2.x) - (vec1.x * vec2.z),
        .z = (vec1.x * vec2.y) - (vec1.y * vec2.x)
    };
    return product;
}

scalar_t mag(Vector vec) {
    scalar_t radicand = (vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z);
    return sqrt(radicand);
}

Vector proj(Vector vec1, Vector vec2) {
    if (mag(vec1) == 0 || mag(vec2) == 0) {
        Vector err = {0};
        return err;
    }

    scalar_t scalar = dot(vec1, vec2) / (mag(vec2) * mag(vec2));

    Vector projection = {
        .x = scalar * vec2.x,
        .y = scalar * vec2.y,
        .z = scalar * vec2.z
    };

    return projection;
}

Vector norm(Vector vec) {
    scalar_t magnitude = mag(vec);

    if (magnitude == 0) return (Vector){0};

    Vector normalized = {
        .x = vec.x / magnitude,
        .y = vec.y / magnitude,
        .z = vec.z / magnitude
    };

    return normalized;
}

Vector scale(Vector vec, scalar_t scalar) {
    Vector scaled = {
        .x = vec.x * scalar,
        .y = vec.y * scalar,
        .z = vec.z * scalar
    };
    return scaled;
}

scalar_t distance(Vector vec1, Vector vec2) {
    scalar_t radicand =
        (vec1.x - vec2.x) * (vec1.x - vec2.x)
      + (vec1.y - vec2.y) * (vec1.y - vec2.y)
      + (vec1.z - vec2.z) * (vec1.z - vec2.z);

    return sqrt(radicand);
}

int are_orthogonal(Vector vec1, Vector vec2) {
    if (fabs(dot(vec1, vec2)) < EPSILON)
        return 1;
    return 0;
}

int is_zero(Vector vec) {
    if (fabs(mag(vec)) < EPSILON)
        return 1;
    return 0;
}

int are_parallel(Vector vec1, Vector vec2) {
    if (is_zero(cross(vec1, vec2)) == 1)
        return 1;
    return 0;
}

Vector input_vector(void) {
    Vector input;
    int c;
    scalar_t x, y, z;

    printf("Enter a vector <A, B, C>: ");

    while (scanf(" %lf,%lf,%lf", &x, &y, &z) != 3) {
        printf("Invalid input, please try again\n");
        while ((c = getchar()) != '\n' && c != EOF);
    }

    printf("<%.3lf, %.3lf, %.3lf>\n", x, y, z);

    input.x = x;
    input.y = y;
    input.z = z;

    return input;
}

scalar_t angle(Vector vec1, Vector vec2) {
    if (mag(vec1) == 0 || mag(vec2) == 0)
        return NAN;

    scalar_t phi = dot(vec1, vec2) / (mag(vec1) * mag(vec2));

    if (phi > 1) phi = 1;
    if (phi < -1) phi = -1;

    return acos(phi);
}

scalar_t scalar_triple(Vector vec1, Vector vec2, Vector vec3) {
    return dot(vec1, cross(vec2, vec3));
}

Vector vector_triple(Vector vec1, Vector vec2, Vector vec3) {
    return cross(vec1, cross(vec2, vec3));
}
