#include <iostream>
#include "header.h"
using namespace std;

void printErrorMessage(int error) {
    if (error == ERROR_BIT_INDEX) cout << "error: bit index is out of range\n";
    else if (error == ERROR_PRECISION) cout << "error: precision must be positive\n";
    else if (error == ERROR_ARGUMENT_RANGE) cout << "error: argument is out of range\n";
    else cout << "error: unknown error code " << error << '\n';
}

void showGcd(int caseNumber, int a, int b) {
    cout << caseNumber << ".\n";
    cout << "a = " << a << ", b = " << b << '\n';
    try {
        int result = gcd(a, b);
        cout << "gcd(a, b) = " << result << '\n';
    } catch (int error) {
        printErrorMessage(error);
    }
}

void showBinary(int caseNumber, short number) {
    cout << caseNumber << ".\n";
    cout << "number = " << number << '\n';
    cout << "print_bin(number) = ";
    print_bin(number);
    cout << "\nprint_mem_bin(number) = ";
    print_mem_bin(number);
    cout << "\ndispBinary(number) = ";
    dispBinary(static_cast<unsigned char>(number));
    cout << '\n';
}

void showFastOperations(int caseNumber, unsigned int x) {
    cout << caseNumber << ".\n";
    cout << "x = " << x << '\n';
    cout << "mul_2(x) = " << mul_2(x) << ", div_2(x) = " << div_2(x)
         << ", odd(x) = " << (odd(x) ? "true" : "false") << '\n';
}

void showBitFunctions(int caseNumber, int number, int index) {
    cout << caseNumber << ".\n";
    cout << "number = " << number << ", index = " << index << '\n';
    try {
        int bit = getBit(number, index);
        int withSetBit = setBit(number, index);
        int withClearedBit = clearBit(number, index);
        cout << "getBit(number, index) = " << bit << '\n';
        cout << "setBit(number, index) = " << withSetBit << '\n';
        cout << "clearBit(number, index) = " << withClearedBit << '\n';
    } catch (int error) {
        printErrorMessage(error);
    }
}

void showExp(int caseNumber, double x, double eps) {
    cout << caseNumber << ".\n";
    cout << "x = " << x << ", eps = " << eps << '\n';
    try {
        double result = taylorExp(x, eps);
        cout << "taylorExp(x, eps) = " << result << '\n';
    } catch (int error) {
        printErrorMessage(error);
    }
}

void showSin(int caseNumber, double x, double eps) {
    cout << caseNumber << ".\n";
    cout << "x = " << x << ", eps = " << eps << '\n';
    try {
        double result = taylorSin(x, eps);
        cout << "taylorSin(x, eps) = " << result << '\n';
    } catch (int error) {
        printErrorMessage(error);
    }
}

int main() {
    cout << "LAB 3. DATA TYPES AND OPERATIONS\n";
    cout.precision(15);

    cout << "\n***\nPart A. Euclidean algorithm gcd(a, b)\n";
    showGcd(1, 12, 18);
    showGcd(2, -48, 36);
    showGcd(3, 17, 5);
    showGcd(4, 0, 7);
    showGcd(5, 0, 0);
    showGcd(6, -2147483647 - 1, 2);

    cout << "\n***\nPart A. Binary output (print_bin and print_mem_bin from lower bits, dispBinary from higher bits)\n";
    showBinary(1, 5);
    showBinary(2, 0);
    showBinary(3, -1);
    showBinary(4, 255);

    cout << "\n***\nPart A. Bit operations mul_2, div_2, odd\n";
    showFastOperations(1, 7);
    showFastOperations(2, 10);
    showFastOperations(3, 0);

    cout << "\n***\nPart B. Accumulation of floating point error\n";
    cout.precision(20);
    cout << "n = 2000\n";
    cout << "sum_1(n) = " << sum_1(2000) << " (terms from 1 to 1/n)\n";
    cout << "sum_2(n) = " << sum_2(2000) << " (terms from 1/n to 1)\n";
    cout << "sum_1(n) - sum_2(n) = " << sum_1(2000) - sum_2(2000) << '\n';
    cout << "sum_2 is more accurate: small terms are added first, so they are not lost against a large sum\n";
    cout << "n = 0\n";
    cout << "sum_1(n) = " << sum_1(0) << ", sum_2(n) = " << sum_2(0) << '\n';
    cout.precision(15);

    cout << "\n***\nTask 1-2. getBit, setBit, clearBit\n";
    showBitFunctions(1, 5, 0);
    showBitFunctions(2, 5, 1);
    showBitFunctions(3, 5, 2);
    showBitFunctions(4, -1, 31);
    showBitFunctions(5, 0, 31);
    showBitFunctions(6, 5, 32);
    showBitFunctions(7, 5, -1);

    cout << "\n***\nTask 3. Exponent by Taylor series\n";
    showExp(1, 0.0, 1e-15);
    showExp(2, 1.0, 1e-15);
    showExp(3, 10.0, 1e-15);
    showExp(4, -10.0, 1e-15);
    showExp(5, 1.0, 1e-3);
    showExp(6, 1.0, 0.0);

    cout << "\n***\nTask 4. Sine by Taylor series\n";
    showSin(1, 0.0, 1e-15);
    showSin(2, 3.14159265358979323846 / 6.0, 1e-15);
    showSin(3, -3.14159265358979323846 / 2.0, 1e-15);
    showSin(4, 250.0, 1e-15);
    showSin(5, -1000.5, 1e-15);
    showSin(6, 1.0, -1e-3);
    showSin(7, 1e20, 1e-15);

    return 0;
}
