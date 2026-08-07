/****************************************

File: vec3.c

Author: Connor Fletcher

Date: July 30, 2026

Brief: Functions performing fundamental 3D vector operations

****************************************/

#include "vec3.h"

Vec3 vec3_add(Vec3 vec1, Vec3 vec2) {
    Vec3 sum = {
        .x = vec1.x + vec2.x,
        .y = vec1.y + vec2.y,
        .z = vec1.z + vec2.z
    };
    return sum;
}

Vec3 vec3_subtract(Vec3 vec1, Vec3 vec2) {
    Vec3 difference = {
        .x = vec1.x - vec2.x,
        .y = vec1.y - vec2.y,
        .z = vec1.z - vec2.z
    };
    return difference;
}

scalar_t vec3_dot(Vec3 vec1, Vec3 vec2) {
    return (vec1.x * vec2.x) +
           (vec1.y * vec2.y) +
           (vec1.z * vec2.z);
}

Vec3 vec3_cross(Vec3 vec1, Vec3 vec2) {
    Vec3 product = {
        .x = (vec1.y * vec2.z) - (vec1.z * vec2.y),
        .y = (vec1.z * vec2.x) - (vec1.x * vec2.z),
        .z = (vec1.x * vec2.y) - (vec1.y * vec2.x)
    };
    return product;
}

scalar_t vec3_mag(Vec3 vec) {
    scalar_t radicand =
        (vec.x * vec.x) +
        (vec.y * vec.y) +
        (vec.z * vec.z);

    return sqrt(radicand);
}

Vec3 vec3_proj(Vec3 vec1, Vec3 vec2) {
    if (vec3_mag(vec1) == 0 || vec3_mag(vec2) == 0) {
        return (Vec3){0};
    }

    scalar_t scalar =
        vec3_dot(vec1, vec2) /
        (vec3_mag(vec2) * vec3_mag(vec2));

    Vec3 projection = {
        .x = scalar * vec2.x,
        .y = scalar * vec2.y,
        .z = scalar * vec2.z
    };

    return projection;
}

Vec3 vec3_norm(Vec3 vec) {
    scalar_t magnitude = vec3_mag(vec);

    if (magnitude == 0)
        return (Vec3){0};

    Vec3 normalized = {
        .x = vec.x / magnitude,
        .y = vec.y / magnitude,
        .z = vec.z / magnitude
    };

    return normalized;
}

Vec3 vec3_scale(Vec3 vec, scalar_t scalar) {
    Vec3 scaled = {
        .x = vec.x * scalar,
        .y = vec.y * scalar,
        .z = vec.z * scalar
    };

    return scaled;
}

scalar_t vec3_distance(Vec3 vec1, Vec3 vec2) {
    scalar_t radicand =
        (vec1.x - vec2.x) * (vec1.x - vec2.x) +
        (vec1.y - vec2.y) * (vec1.y - vec2.y) +
        (vec1.z - vec2.z) * (vec1.z - vec2.z);

    return sqrt(radicand);
}

int vec3_are_orthogonal(Vec3 vec1, Vec3 vec2) {
    return fabs(vec3_dot(vec1, vec2)) < EPSILON;
}

int vec3_is_zero(Vec3 vec) {
    return fabs(vec3_mag(vec)) < EPSILON;
}

int vec3_are_parallel(Vec3 vec1, Vec3 vec2) {
    return vec3_is_zero(vec3_cross(vec1, vec2));
}

Vec3 vec3_input(void) {
    Vec3 input;
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

scalar_t vec3_angle(Vec3 vec1, Vec3 vec2) {
    if (vec3_mag(vec1) == 0 || vec3_mag(vec2) == 0)
        return NAN;

    scalar_t phi =
        vec3_dot(vec1, vec2) /
        (vec3_mag(vec1) * vec3_mag(vec2));

    if (phi > 1)
        phi = 1;
    if (phi < -1)
        phi = -1;

    return acos(phi);
}

scalar_t vec3_scalar_triple(Vec3 vec1, Vec3 vec2, Vec3 vec3) {
    return vec3_dot(vec1, vec3_cross(vec2, vec3));
}

Vec3 vec3_vector_triple(Vec3 vec1, Vec3 vec2, Vec3 vec3) {
    return vec3_cross(vec1, vec3_cross(vec2, vec3));
}

double rand_double(double min, double max) {
    return min + ((double)rand() / RAND_MAX) * (max - min);
}
