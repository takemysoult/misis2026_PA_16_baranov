#ifndef LAB4_HEADER_H
#define LAB4_HEADER_H

const int ERROR_DIVISION_BY_ZERO = 1;
const int ERROR_NEGATIVE_ROOT = 2;
const int ERROR_UNDEFINED_GCD = 3;
const int ERROR_ARGUMENT_RANGE = 4;
const int ERROR_INVALID_OPERATION = 5;
const int ERROR_INVALID_EXPRESSION = 6;

using func = double (*)(double);


double hyperbola(double x);
double squareRoot(double x);
double parabola(double x);

void chart(double a, double b, int n);
void chart(func f, double a, double b, int n);


void printReversedDigits(int number);

int gcdRecursive(int a, int b);
int gcdIterative(int a, int b);

double power(double base, int exponent);


double calculate(const char* expression);

#endif
