/****************************

File: math_util.c

Author: Connor Fletcher

Date: July 30, 2026

Brief: Functions performing essential mathematics operations

*****************************/

#include "math_util.h"

double squarert(double num){
    if (num < 0) return MATH_ERROR;
    if (num == 0) return 0;

    double new_guess;
    double guess = num / 3;
    for (int i = 0; i < 10; i++){
        new_guess = 0.5 * (guess + (num/guess));
        guess = new_guess;
    }
    return guess;
}

double factorial(unsigned int n) {
    double fac = 1;
    for (int i = n; i >= 1; i--) {
        fac *= i;
    }
    return fac;
}

double abslt(double n) {
    if (n >= 0) return n;
    else {
        return n *= -1;
    }
}

double power(double base, int exp) {
    if (exp == 0) return 1;

    double product = base;
    for (int i = 1; i < exp; i++) {
        product *= base;
    }
    return product;
}

double reduce_angle(double theta) {
    while (theta > PI)
        theta -= 2 * PI;

    while (theta < -PI)
        theta += 2 * PI;

    return theta;
}

double sine(double theta) {
    theta = reduce_angle(theta);

    double sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += (power(-1, i)/factorial((2*i + 1))) * power(theta, 2*i + 1);
    }
    return sum;
}

double cosine(double theta) {
    theta = reduce_angle(theta);

    double sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += (power(-1, i)/(factorial(2*i)))*power(theta, 2*i);
    }
    return sum;
}

double tangent(double theta) {
    double x = cosine(theta);
    if (abslt(x) < 1e-12) return MATH_ERROR;
    return sine(theta)/x;
}

double min(double num1, double num2) {
    if (num1 <= num2) {
        return num1;
    } else {
        return num2;
    }
}

double max(double num1, double num2) {
    if (num1 >= num2) {
        return num1;
    } else {
        return num2;
    }
}

double arccos(double theta) {

    if (theta < -1 || theta > 1) {
        return MATH_ERROR;
    }

    double sum = 0;
    for (int i = 0; i < 86; i++) {
        sum += factorial(2*i)/(power(4, i) * power(factorial(i), 2) * (2*i+1)) * power(theta, 2*i+1);
    }
    return (PI/2) - sum;
}
