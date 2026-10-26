#ifndef LAB3_HEADER_H
#define LAB3_HEADER_H

// коды ошибок, которые выбрасываются через throw
const int ERROR_BIT_INDEX = 1;
const int ERROR_PRECISION = 2;
const int ERROR_ARGUMENT_RANGE = 3;


// НОД вычитанием (геометрический алгоритм Евклида)
int gcd(int a, int b);
// вывод двоичной записи от младших разрядов к старшим
void print_bin(short number);
// то же, но выводятся все 16 бит short
void print_mem_bin(short number);
// 8 бит от старших к младшим
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


// 1 + 1/2 + ... + 1/n в прямом и обратном порядке
double sum_1(int n);
double sum_2(int n);


// index от 0 до 31, иначе throw ERROR_BIT_INDEX
int getBit(int number, int index);
int setBit(int number, int index);
int clearBit(int number, int index);


// e^x и sin(x) через ряд Тейлора, eps - точность (должна быть > 0)
double taylorExp(double x, double eps);
double taylorSin(double x, double eps);

#endif
