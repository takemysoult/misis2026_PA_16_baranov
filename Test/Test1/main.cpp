#include <iostream>
#include "header.h"
using namespace std;

void printErrorMessage(int error) {
    if (error == ERROR_DIGIT_RANGE) cout << "error: digits must be from 0 to 9\n";
    else if (error == ERROR_ARGUMENT_RANGE) cout << "error: argument or result is out of range\n";
    else if (error == ERROR_INVALID_RECTANGLE) cout << "error: corners of the rectangle are mixed up\n";
    else if (error == ERROR_PRECISION) cout << "error: eps must be positive\n";
    else cout << "error: unknown error code " << error << '\n';
}

// задание 1 (результат сначала сохраняем в переменную чтоб при throw не напечаталась половина строки)
void showReplaceDigit(int caseNumber, int n, int from, int to) {
    cout << caseNumber << ".\n";
    cout << "n = " << n << ", from = " << from << ", to = " << to << '\n';
    try {
        int result = replace_digit(n, from, to);
        cout << "replace_digit(n, from, to) = " << result << '\n';
    } catch (int error) {
        printErrorMessage(error);
    }
}

// задание 2
void showIntersectionArea(int caseNumber, double x1, double y1, double x2, double y2,
                          double x3, double y3, double x4, double y4) {
    cout << caseNumber << ".\n";
    cout << "first: (" << x1 << ", " << y1 << ") - (" << x2 << ", " << y2 << ")\n";
    cout << "second: (" << x3 << ", " << y3 << ") - (" << x4 << ", " << y4 << ")\n";
    try {
        double result = intersection_area(x1, y1, x2, y2, x3, y3, x4, y4);
        cout << "intersection_area = " << result << '\n';
    } catch (int error) {
        printErrorMessage(error);
    }
}

// задание 3
void showLnDiv(int caseNumber, double x, double eps) {
    cout << caseNumber << ".\n";
    cout << "x = " << x << ", eps = " << eps << '\n';
    try {
        double result = t_ln_div(x, eps);
        cout << "t_ln_div(x, eps) = " << result << '\n';
    } catch (int error) {
        printErrorMessage(error);
    }
}

// задание 4
void showBinary(int caseNumber, int n) {
    cout << caseNumber << ".\n";
    cout << "n = " << n << '\n';
    cout << "print_binary(n) = ";
    print_binary(n);
    cout << '\n';
}

int main() {
    cout << "TEST 1. VARIANT 6\n";

    cout << "\n***\nTask 1. int replace_digit\n";
    showReplaceDigit(1, -202, 2, 7);
    showReplaceDigit(2, 12321, 1, 9);
    showReplaceDigit(3, 555, 3, 1);
    showReplaceDigit(4, 0, 0, 5);
    showReplaceDigit(5, 205, 2, 0);
    showReplaceDigit(6, -2147483647 - 1, 8, 0);
    showReplaceDigit(7, 1999999999, 1, 9);
    showReplaceDigit(8, 123, 10, 1);

    cout << "\n***\nTask 2. double intersection_area\n";
    showIntersectionArea(1, 0, 0, 4, 3, 2, 1, 6, 5);
    showIntersectionArea(2, 0, 0, 10, 10, 2, 2, 4, 4);
    showIntersectionArea(3, 0, 0, 1, 1, 2, 2, 3, 3);
    showIntersectionArea(4, 0, 0, 2, 2, 2, 0, 4, 2);
    showIntersectionArea(5, -3, -3, -1, -1, -2, -2, 0, 0);
    showIntersectionArea(6, 4, 0, 0, 3, 2, 1, 6, 5);

    cout << "\n***\nTask 3. double t_ln_div\n";
    showLnDiv(1, 0.5, 1e-10);
    showLnDiv(2, -0.5, 1e-10);
    showLnDiv(3, 0.0, 1e-10);
    showLnDiv(4, 0.9, 1e-6);
    showLnDiv(5, 1.0, 1e-6);
    showLnDiv(6, 0.5, 0.0);
    showLnDiv(7, 1.5, 1e-6);

    cout << "\n***\nTask 4. void print_binary\n";
    showBinary(1, 5);
    showBinary(2, 0);
    showBinary(3, 1);
    showBinary(4, 1024);
    showBinary(5, -6);
    showBinary(6, 2147483647);
    showBinary(7, -2147483647 - 1);
    showBinary(8, -1);

    return 0;
}
