#include <climits>
#include <iostream>
#include "header.h"

using std::cout;

namespace {
    double absoluteValue(double value) {
        return value < 0.0 ? -value : value;
    }

    double maxValue(double a, double b) {
        if (a > b) return a;
        return b;
    }

    double minValue(double a, double b) {
        if (a < b) return a;
        return b;
    }

    // сначала печатаем старшие разряды потом текущий
    void printBinaryStep(long long number) {
        if (number >= 2) printBinaryStep(number / 2);
        cout << number % 2;
    }
}

int replace_digit(int n, int from, int to) {
    if (from < 0 || from > 9 || to < 0 || to > 9) throw ERROR_DIGIT_RANGE;

    // через long long т.к. -INT_MIN не влезает в int
    long long number = n;
    bool negative = false;
    if (number < 0) {
        negative = true;
        number = -number;
    }

    // у нуля одна цифра, а цикл ниже его пропустит
    if (number == 0) {
        if (from == 0) return to;
        return 0;
    }

    long long result = 0;
    long long place = 1;
    while (number > 0) {
        long long digit = number % 10;
        if (digit == from) digit = to;
        result += digit * place;
        place *= 10;
        number /= 10;
    }

    if (negative) result = -result;
    if (result > INT_MAX || result < INT_MIN) throw ERROR_ARGUMENT_RANGE;
    return static_cast<int>(result);
}

double intersection_area(double x1, double y1, double x2, double y2,
                         double x3, double y3, double x4, double y4) {
    if (x1 > x2 || y1 > y2 || x3 > x4 || y3 > y4) throw ERROR_INVALID_RECTANGLE;

    double left = maxValue(x1, x3);
    double right = minValue(x2, x4);
    double bottom = maxValue(y1, y3);
    double top = minValue(y2, y4);

    // не пересекаются или касаются только стороной/углом
    if (left >= right || bottom >= top) return 0.0;
    return (right - left) * (top - bottom);
}

double t_ln_div(double x, double eps) {
    if (!(eps > 0.0)) throw ERROR_PRECISION;
    // ряд сходится только при |x| < 1, при x = 1 логарифм не определен
    if (!(x > -1.0 && x < 1.0)) throw ERROR_ARGUMENT_RANGE;

    double power = x;  // x^(2n+1)
    double term = x;   // x^(2n+1) / (2n+1)
    double sum = 0.0;
    int n = 0;
    while (absoluteValue(term) > eps) {
        sum += term;
        ++n;
        power *= x * x;
        term = power / (2 * n + 1);
    }
    return 2.0 * sum;
}

void print_binary(int n) {
    long long number = n;
    if (number < 0) {
        cout << '-';
        number = -number;
    }
    printBinaryStep(number);
}
