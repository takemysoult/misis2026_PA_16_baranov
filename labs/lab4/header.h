#ifndef LAB4_HEADER_H
#define LAB4_HEADER_H

// коды ошибок, функции выбрасывают их как int
const int ERROR_DIVISION_BY_ZERO = 1;
const int ERROR_NEGATIVE_ROOT = 2;
const int ERROR_UNDEFINED_GCD = 3;
const int ERROR_ARGUMENT_RANGE = 4;
const int ERROR_INVALID_OPERATION = 5;
const int ERROR_INVALID_EXPRESSION = 6;

using func = double (*)(double);


// 1/x, при x = 0 throw
double hyperbola(double x);
// корень, для x < 0 throw
double squareRoot(double x);
double parabola(double x);

// таблица значений на [a, b] в n точках
void chart(double a, double b, int n);
void chart(func f, double a, double b, int n);


// печатает только цифры, минус пропускается
void printReversedDigits(int number);

// gcd(0, 0) не определен -> throw
int gcdRecursive(int a, int b);
int gcdIterative(int a, int b);

// рекурсивно, степень может быть отрицательной
double power(double base, int exponent);


// строка вида "6-4": цифра, знак, цифра
double calculate(const char* expression);

#endif
