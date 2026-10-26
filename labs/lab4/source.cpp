#include <climits>
#include <iostream>
#include "header.h"

using std::cout;

namespace {
    double absoluteValue(double value) {
        return value < 0.0 ? -value : value;
    }

    int absoluteValue(int value) {
        // -INT_MIN в int не помещается
        if (value == INT_MIN) throw ERROR_ARGUMENT_RANGE;
        return value < 0 ? -value : value;
    }

    void printReversedDigitsStep(long long number) {
        cout << number % 10;
        if (number >= 10) printReversedDigitsStep(number / 10);
    }

    int gcdRecursiveStep(int a, int b) {
        if (b == 0) return a;
        return gcdRecursiveStep(b, a % b);
    }

    // быстрое возведение: x^n = (x^(n/2))^2, и еще * x если n нечетное
    double powerStep(double base, long long exponent) {
        if (exponent == 0) return 1.0;
        double half = powerStep(base, exponent / 2);
        if (exponent % 2 == 0) return half * half;
        return half * half * base;
    }

    bool isDigit(char symbol) {
        return symbol >= '0' && symbol <= '9';
    }
}

double hyperbola(double x) {
    if (x == 0.0) throw ERROR_DIVISION_BY_ZERO;
    return 1.0 / x;
}

double squareRoot(double x) {
    if (x < 0.0) throw ERROR_NEGATIVE_ROOT;
    if (x == 0.0) return 0.0;
    // метод Ньютона
    double guess = x >= 1.0 ? x : 1.0;
    for (int i = 0; i < 100; ++i) {
        double next = (guess + x / guess) / 2.0;
        if (absoluteValue(next - guess) < 1e-15 * next) return next;
        guess = next;
    }
    return guess;
}

double parabola(double x) {
    return x * x;
}

void chart(double a, double b, int n) {
    chart(hyperbola, a, b, n);
}

void chart(func f, double a, double b, int n) {
    if (f == nullptr) {
        cout << "function is not set\n";
        return;
    }
    if (n < 1) {
        cout << "number of points must be positive\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        // x считаем от a каждый раз, а не прибавляем шаг, чтобы не копилась ошибка
        double x = n == 1 ? a : a + (b - a) * i / (n - 1);
        cout << "x = " << x << "\t";
        try {
            double value = f(x);
            cout << "f(x) = " << value << '\n';
        } catch (int) {
            cout << "function value is undefined\n";
        }
    }
}

void printReversedDigits(int number) {
    // через long long, т.к. -INT_MIN не влезает в int
    long long value = number;
    if (value < 0) value = -value;
    printReversedDigitsStep(value);
}

int gcdRecursive(int a, int b) {
    if (a == 0 && b == 0) throw ERROR_UNDEFINED_GCD;
    return gcdRecursiveStep(absoluteValue(a), absoluteValue(b));
}

int gcdIterative(int a, int b) {
    if (a == 0 && b == 0) throw ERROR_UNDEFINED_GCD;
    a = absoluteValue(a);
    b = absoluteValue(b);
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

double power(double base, int exponent) {
    if (base == 0.0 && exponent < 0) throw ERROR_DIVISION_BY_ZERO;
    long long longExponent = exponent;
    if (longExponent < 0) return 1.0 / powerStep(base, -longExponent);
    return powerStep(base, longExponent);
}

double calculate(const char* expression) {
    if (expression == nullptr) throw ERROR_INVALID_EXPRESSION;
    // ровно 3 символа: цифра, знак, цифра
    if (!isDigit(expression[0]) || expression[1] == '\0' ||
        !isDigit(expression[2]) || expression[3] != '\0') throw ERROR_INVALID_EXPRESSION;
    double left = expression[0] - '0';
    double right = expression[2] - '0';
    switch (expression[1]) {
    case '+':
        return left + right;
    case '-':
        return left - right;
    case '*':
        return left * right;
    case '/':
        if (right == 0.0) throw ERROR_DIVISION_BY_ZERO;
        return left / right;
    default:
        throw ERROR_INVALID_OPERATION;
    }
}
