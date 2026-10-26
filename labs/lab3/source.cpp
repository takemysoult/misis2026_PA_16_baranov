#include <climits>
#include <iostream>
#include "header.h"

using std::cout;

namespace {
    const double PI = 3.14159265358979323846;
    const double TWO_PI_HIGH = 6.28318530717958623200;
    const double TWO_PI_LOW = 2.44929359829470635445e-16;
    const double MAX_SIN_ARGUMENT = 1e15;
    const int BITS_IN_INT = static_cast<int>(sizeof(int) * 8);

    int absoluteValue(int value) {
        return value < 0 ? -value : value;
    }

    double absoluteValue(double value) {
        return value < 0.0 ? -value : value;
    }

    void checkBitIndex(int index) {
        if (index < 0 || index >= BITS_IN_INT) throw ERROR_BIT_INDEX;
    }

    double reduceAngle(double x) {
        double turnsExact = x / TWO_PI_HIGH;
        double turns = static_cast<double>(static_cast<long long>(turnsExact >= 0.0 ? turnsExact + 0.5 : turnsExact - 0.5));
        double reduced = (x - turns * TWO_PI_HIGH) - turns * TWO_PI_LOW;
        if (reduced > PI) reduced -= TWO_PI_HIGH;
        if (reduced < -PI) reduced += TWO_PI_HIGH;
        return reduced;
    }
}

int gcd(int a, int b) {
    if (a == INT_MIN || b == INT_MIN) throw ERROR_ARGUMENT_RANGE;
    a = absoluteValue(a);
    b = absoluteValue(b);
    if (a == 0) return b;
    if (b == 0) return a;
    while (a != b) {
        if (a > b) a -= b;
        else b -= a;
    }
    return a;
}

void print_bin(short number) {
    unsigned short bits = static_cast<unsigned short>(number);
    do {
        cout << (bits & 1U);
        bits = static_cast<unsigned short>(bits >> 1);
    } while (bits != 0U);
}

void print_mem_bin(short number) {
    unsigned short bits = static_cast<unsigned short>(number);
    for (int i = 0; i < static_cast<int>(sizeof(short) * 8); ++i) {
        cout << (bits & 1U);
        bits = static_cast<unsigned short>(bits >> 1);
    }
}

void dispBinary(unsigned char u) {
    for (unsigned char mask = 128; mask > 0; mask = static_cast<unsigned char>(mask >> 1)) {
        if ((u & mask) != 0) cout << '1';
        else cout << '0';
    }
}

double sum_1(int n) {
    double s = 0.0;
    for (int i = 1; i <= n; ++i) s += 1.0 / i;
    return s;
}

double sum_2(int n) {
    double s = 0.0;
    for (int i = n; i > 0; --i) s += 1.0 / i;
    return s;
}

int getBit(int number, int index) {
    checkBitIndex(index);
    return static_cast<int>((static_cast<unsigned int>(number) >> index) & 1U);
}

int setBit(int number, int index) {
    checkBitIndex(index);
    return static_cast<int>(static_cast<unsigned int>(number) | (1U << index));
}

int clearBit(int number, int index) {
    checkBitIndex(index);
    return static_cast<int>(static_cast<unsigned int>(number) & ~(1U << index));
}

double taylorExp(double x, double eps) {
    if (!(eps > 0.0)) throw ERROR_PRECISION;
    if (x < 0.0) return 1.0 / taylorExp(-x, eps);
    double term = 1.0;
    double sum = 1.0;
    int n = 1;
    while (term > eps * sum) {
        term *= x / n;
        sum += term;
        ++n;
    }
    return sum;
}

double taylorSin(double x, double eps) {
    if (!(eps > 0.0)) throw ERROR_PRECISION;
    if (!(x >= -MAX_SIN_ARGUMENT && x <= MAX_SIN_ARGUMENT)) throw ERROR_ARGUMENT_RANGE;
    double angle = reduceAngle(x);
    double term = angle;
    double sum = angle;
    int n = 1;
    while (absoluteValue(term) > eps) {
        term *= -angle * angle / ((2.0 * n) * (2.0 * n + 1.0));
        sum += term;
        ++n;
    }
    return sum;
}
