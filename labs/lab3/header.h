#ifndef LAB3_HEADER_H
#define LAB3_HEADER_H

const int ERROR_BIT_INDEX = 1;
const int ERROR_PRECISION = 2;
const int ERROR_ARGUMENT_RANGE = 3;


int gcd(int a, int b);
void print_bin(short number);
void print_mem_bin(short number);
void dispBinary(unsigned char u);

inline unsigned int mul_2(unsigned int x) {
    return x << 1;
}

inline unsigned int div_2(unsigned int x) {
    return x >> 1;
}

inline bool odd(unsigned int x) {
    return (x & 1U) != 0U;
}


double sum_1(int n);
double sum_2(int n);


int getBit(int number, int index);
int setBit(int number, int index);
int clearBit(int number, int index);


double taylorExp(double x, double eps);
double taylorSin(double x, double eps);

#endif
