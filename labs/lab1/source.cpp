#include "header.h"

long long factorial(int n) {
    if (n < 0 || n > 20) return -1; 
    long long result = 1;
    for (int i = 2; i <= n; ++i) result *= i;
    return result;
}

int countDigits(long long number) {
    int count = 0;
    if (number < 0) number = -number;
    do {
        ++count;
        number /= 10;
    } while (number != 0);
    return count;
}

int sumDigits(long long number) {
    int sum = 0;
    if (number < 0) number = -number;
    while (number != 0) {
        sum += static_cast<int>(number % 10);
        number /= 10;
    }
    return sum;
}

void order(int& first, int& second) {
    if (first > second) {
        int temp = first;
        first = second;
        second = temp;
    }
}

void order(double& first, double& second) {
    if (first > second) {
        double temp = first;
        first = second;
        second = temp;
    }
}

int firstDigit(long long number) {
    if (number < 0) number = -number;
    while (number >= 10) number /= 10;
    return static_cast<int>(number);
}

int lastDigit(long long number) {
    if (number < 0) number = -number;
    return static_cast<int>(number % 10);
}

long long removeFirstAndLastDigits(long long number) {
    if (number < 0) number = -number;
    if (number < 10) return 0;
    long long divisor = 1;
    while (number / divisor >= 10) divisor *= 10;
    return (number % divisor) / 10;
}

long long swapFirstAndLastDigits(long long number) {
    if (number < 0) number = -number;
    if (number < 10) return number;
    long long divisor = 1;
    while (number / divisor >= 10) divisor *= 10;
    int first = static_cast<int>(number / divisor);
    int last = static_cast<int>(number % 10);
    long long middle = (number % divisor) / 10;
    return static_cast<long long>(last) * divisor + middle * 10 + first;
}

void countBinaryDigits(unsigned int number, int& zeros, int& ones) {
    zeros = 0;
    ones = 0;
    do {
        if ((number & 1U) != 0U) ++ones;
        else ++zeros;
        number >>= 1;
    } while (number != 0U);
}

double integerPower(int base, int exponent, bool& valid) {
    valid = true;
    if (base == 0 && exponent < 0) {
        valid = false;
        return 0.0;
    }
    long long power = exponent;
    bool negativeExponent = power < 0;
    if (negativeExponent) power = -power;
    double result = 1.0;
    for (long long i = 0; i < power; ++i) result *= base;
    if (negativeExponent) result = 1.0 / result;
    return result;
}

bool equalsSumOfDigitPowers(int number, int exponent) {
    if (number < 0 || exponent < 0) return false;
    int original = number;
    long long sum = 0;
    do {
        int digit = number % 10;
        bool valid = true;
        double value = integerPower(digit, exponent, valid);
        if (!valid) return false;
        sum += static_cast<long long>(value);
        number /= 10;
    } while (number != 0);
    return sum == original;
}
