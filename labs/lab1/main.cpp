#include <iostream>
#include "header.h"
using namespace std;

int main() {
    cout << "LAB 1. FUNCTIONS\n\n";

    cout << "1. Factorial\n";
    cout << "factorial(5) = " << factorial(5) << " (expected 120)\n";
    cout << "factorial(0) = " << factorial(0) << " (expected 1)\n";
    cout << "factorial(-3) = " << factorial(-3) << " (-1 means invalid input)\n\n";

    cout << "2. Number of digits and sum of digits\n";
    const long long values[] = {123, 22345, -56, 7, 0, -1};
    for (int i = 0; i < 6; ++i) {
        cout << values[i] << ": digits = " << countDigits(values[i])
             << ", sum = " << sumDigits(values[i]) << '\n';
    }
    cout << "\n";

    cout << "3. Overloaded order functions\n";
    int a = 9, b = 2;
    order(a, b);
    cout << "integer pair after order: " << a << ", " << b << '\n';
    double x = 3.5, y = -1.25;
    order(x, y);
    cout << "real pair after order: " << x << ", " << y << "\n\n";

    cout << "4. Inline maximum functions\n";
    cout << "maximum(4, 9) = " << maximum(4, 9) << '\n';
    cout << "maximum(2.5, 1.5) = " << maximum(2.5, 1.5) << '\n';
    cout << "maximum(4, 9, 6) = " << maximum(4, 9, 6) << '\n';
    cout << "maximum(2.5, 7.1, 3.0) = " << maximum(2.5, 7.1, 3.0) << "\n\n";

    cout << "5. First and last digits\n";
    long long numbers[] = {1231, 123, 7, 1001};
    for (int i = 0; i < 4; ++i) {
        long long number = numbers[i];
        cout << number << " -> ";
        if (firstDigit(number) == lastDigit(number))
            cout << removeFirstAndLastDigits(number) << " (first and last digits removed)\n";
        else
            cout << swapFirstAndLastDigits(number) << " (first and last digits swapped)\n";
    }
    cout << "\n";

    cout << "Additional task 1. Binary digit counts\n";
    int zeros = 0, ones = 0;
    countBinaryDigits(13, zeros, ones); 
    cout << "13 (binary 1101): zeros = " << zeros << ", ones = " << ones << '\n';
    countBinaryDigits(0, zeros, ones);
    cout << "0 (binary 0): zeros = " << zeros << ", ones = " << ones << "\n\n";

    cout << "Additional task 2. Integer power and digit-power sum\n";
    bool valid = true;
    cout << "2^5 = " << integerPower(2, 5, valid) << '\n';
    cout << "2^-2 = " << integerPower(2, -2, valid) << '\n';
    integerPower(0, -1, valid);
    cout << "0^-1 valid = " << valid << '\n';
    cout << "153 equals sum of cubes of its digits: "
         << equalsSumOfDigitPowers(153, 3) << " (1 means true)\n";

    return 0;
}
