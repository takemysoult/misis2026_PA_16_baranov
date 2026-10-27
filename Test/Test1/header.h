#ifndef TEST1_HEADER_H
#define TEST1_HEADER_H

// коды ошибок функции выбрасывают их как int
const int ERROR_DIGIT_RANGE = 1;
const int ERROR_ARGUMENT_RANGE = 2;
const int ERROR_INVALID_RECTANGLE = 3;
const int ERROR_PRECISION = 4;


// from и to от 0 до 9, знак числа сохраняется
// если результат не влезает в int -> throw
int replace_digit(int n, int from, int to);

// если углы перепутаны -> throw
double intersection_area(double x1, double y1, double x2, double y2,
                         double x3, double y3, double x4, double y4);

// ln((1 + x) / (1 - x)) через ряд, |x| < 1, eps > 0
double t_ln_div(double x, double eps);

// рекурсивно, для отрицательных сначала печатается минус
void print_binary(int n);

#endif
