#ifndef LAB1_HEADER_H
#define LAB1_HEADER_H


// факториал, для n < 0 и n > 20 возвращает -1 (дальше long long переполнится)
long long factorial(int n);
// кол-во цифр числа, знак не учитывается
int countDigits(long long number);
// сумма цифр числа
int sumDigits(long long number);
// ставит два числа по возрастанию
void order(int& first, int& second);
void order(double& first, double& second);


int firstDigit(long long number);
int lastDigit(long long number);
// 1231 -> 23
long long removeFirstAndLastDigits(long long number);
// 123 -> 321
long long swapFirstAndLastDigits(long long number);


// сколько нулей и единиц в двоичной записи
void countBinaryDigits(unsigned int number, int& zeros, int& ones);
// base^exponent, valid = false если 0 в отрицательной степени
double integerPower(int base, int exponent, bool& valid);
// проверка: число равно сумме своих цифр в степени exponent (153 = 1^3 + 5^3 + 3^3)
bool equalsSumOfDigitPowers(int number, int exponent);


// inline-версии максимума для двух и трех аргументов
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
