#ifndef LAB1_HEADER_H
#define LAB1_HEADER_H


long long factorial(int n);
int countDigits(long long number);
int sumDigits(long long number);
void order(int& first, int& second);
void order(double& first, double& second);


int firstDigit(long long number);
int lastDigit(long long number);
long long removeFirstAndLastDigits(long long number);
long long swapFirstAndLastDigits(long long number);


void countBinaryDigits(unsigned int number, int& zeros, int& ones);
double integerPower(int base, int exponent, bool& valid);
bool equalsSumOfDigitPowers(int number, int exponent);


inline int maximum(int a, int b) {
    return (a > b) ? a : b;
}

inline double maximum(double a, double b) {
    return (a > b) ? a : b;
}

inline int maximum(int a, int b, int c) {
    return maximum(maximum(a, b), c);
}

inline double maximum(double a, double b, double c) {
    return maximum(maximum(a, b), c);
}

#endif
