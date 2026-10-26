#include <iostream>
#include "header.h"
using namespace std;

// текст ошибки по коду из header.h
void printErrorMessage(int error) {
    if (error == ERROR_DIVISION_BY_ZERO) cout << "error: division by zero\n";
    else if (error == ERROR_NEGATIVE_ROOT) cout << "error: root of a negative number\n";
    else if (error == ERROR_UNDEFINED_GCD) cout << "error: gcd(0, 0) is undefined\n";
    else if (error == ERROR_ARGUMENT_RANGE) cout << "error: argument is out of range\n";
    else if (error == ERROR_INVALID_OPERATION) cout << "error: unknown operation sign\n";
    else if (error == ERROR_INVALID_EXPRESSION) cout << "error: expression must look like digit, sign, digit\n";
    else cout << "error: unknown error code " << error << '\n';
}

// результат сначала сохраняем в переменную, чтобы при throw не напечаталась половина строки
void showHyperbola(int caseNumber, double x) {
    cout << caseNumber << ".\n";
    cout << "x = " << x << '\n';
    try {
        double result = hyperbola(x);
        cout << "hyperbola(x) = " << result << '\n';
    } catch (int error) {
        printErrorMessage(error);
    }
}

void showChart(int caseNumber, const char* name, func f, double a, double b, int n) {
    cout << caseNumber << ".\n";
    cout << "f(x) = " << name << ", a = " << a << ", b = " << b << ", n = " << n << '\n';
    chart(f, a, b, n);
}

void showReversedDigits(int caseNumber, int number) {
    cout << caseNumber << ".\n";
    cout << "number = " << number << '\n';
    cout << "printReversedDigits(number) = ";
    printReversedDigits(number);
    cout << '\n';
}

void showGcd(int caseNumber, int a, int b) {
    cout << caseNumber << ".\n";
    cout << "a = " << a << ", b = " << b << '\n';
    try {
        int recursiveResult = gcdRecursive(a, b);
        int iterativeResult = gcdIterative(a, b);
        cout << "gcdRecursive(a, b) = " << recursiveResult << '\n';
        cout << "gcdIterative(a, b) = " << iterativeResult << '\n';
    } catch (int error) {
        printErrorMessage(error);
    }
}

void showPower(int caseNumber, double base, int exponent) {
    cout << caseNumber << ".\n";
    cout << "base = " << base << ", exponent = " << exponent << '\n';
    try {
        double result = power(base, exponent);
        cout << "power(base, exponent) = " << result << '\n';
    } catch (int error) {
        printErrorMessage(error);
    }
}

void showCalculate(int caseNumber, const char* expression) {
    cout << caseNumber << ".\n";
    cout << "expression = \"" << expression << "\"\n";
    try {
        double result = calculate(expression);
        cout << "calculate(expression) = " << result << '\n';
    } catch (int error) {
        printErrorMessage(error);
    }
}

int main() {
    cout << "LAB 4. ERROR HANDLING. RECURSIVE FUNCTIONS\n";

    cout << "\n***\nTask 1. hyperbola(x) = 1/x\n";
    showHyperbola(1, 2.0);
    showHyperbola(2, -0.25);
    showHyperbola(3, 0.0);

    cout << "\n***\nTask 2. chart(a, b, n) for 1/x\n";
    cout << "1.\na = -1, b = 1, n = 5\n";
    chart(-1.0, 1.0, 5);
    cout << "2.\na = 1, b = 2, n = 1\n";
    chart(1.0, 2.0, 1);
    cout << "3.\na = 0, b = 1, n = 0\n";
    chart(0.0, 1.0, 0);

    cout << "\n***\nTask 3. chart(f, a, b, n) for any function\n";
    showChart(1, "squareRoot(x)", squareRoot, -2.0, 2.0, 5);
    showChart(2, "parabola(x)", parabola, -2.0, 2.0, 5);
    showChart(3, "hyperbola(x)", hyperbola, 2.0, -2.0, 3);
    showChart(4, "nullptr", nullptr, 0.0, 1.0, 3);

    cout << "\n***\nTask 4. Recursive output of digits in reverse order\n";
    showReversedDigits(1, 12345);
    showReversedDigits(2, 0);
    showReversedDigits(3, -907);
    showReversedDigits(4, 1000);
    showReversedDigits(5, -2147483647 - 1);

    cout << "\n***\nTask 5. Greatest common divisor\n";
    showGcd(1, 48, 36);
    showGcd(2, -48, 36);
    showGcd(3, 17, 5);
    showGcd(4, 0, 9);
    showGcd(5, 0, 0);
    showGcd(6, -2147483647 - 1, 2);

    cout << "\n***\nTask 6. Recursive power\n";
    showPower(1, 2.0, 10);
    showPower(2, -3.0, 3);
    showPower(3, 2.0, -2);
    showPower(4, 1.5, 0);
    showPower(5, 0.0, 5);
    showPower(6, 0.0, -1);

    cout << "\n***\nTask 7. Expression digit, sign, digit\n";
    showCalculate(1, "6-4");
    showCalculate(2, "2*5");
    showCalculate(3, "3/1");
    showCalculate(4, "7/2");
    showCalculate(5, "8+9");
    showCalculate(6, "5/0");
    showCalculate(7, "4%2");
    showCalculate(8, "12+3");
    showCalculate(9, "a+1");
    showCalculate(10, "");

    return 0;
}
