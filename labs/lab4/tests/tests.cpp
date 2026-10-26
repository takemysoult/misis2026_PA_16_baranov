#include "CppUnitTest.h"
#include "../header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab4Tests
{
    const double tolerance = 1e-12;

    TEST_CLASS(HyperbolaTests)
    {
    public:
        TEST_METHOD(PositiveArgument)
        {
            Assert::AreEqual(0.5, hyperbola(2.0), tolerance);
        }

        TEST_METHOD(NegativeArgument)
        {
            Assert::AreEqual(-4.0, hyperbola(-0.25), tolerance);
        }

        TEST_METHOD(ZeroThrowsInt)
        {
            Assert::ExpectException<int>([]() { hyperbola(0.0); });
        }

        TEST_METHOD(ZeroThrowsDivisionByZeroCode)
        {
            int code = 0;
            try {
                hyperbola(0.0);
            } catch (int error) {
                code = error;
            }
            Assert::AreEqual(ERROR_DIVISION_BY_ZERO, code);
        }
    };

    TEST_CLASS(ChartFunctionTests)
    {
    public:
        TEST_METHOD(SquareRoot)
        {
            Assert::AreEqual(2.0, squareRoot(4.0), tolerance);
            Assert::AreEqual(0.0, squareRoot(0.0), tolerance);
            Assert::AreEqual(1.4142135623730951, squareRoot(2.0), tolerance);
            Assert::AreEqual(0.5, squareRoot(0.25), tolerance);
        }

        TEST_METHOD(SquareRootOfNegativeThrows)
        {
            Assert::ExpectException<int>([]() { squareRoot(-1.0); });
        }

        TEST_METHOD(Parabola)
        {
            Assert::AreEqual(4.0, parabola(-2.0), tolerance);
            Assert::AreEqual(0.0, parabola(0.0), tolerance);
        }

        TEST_METHOD(ChartDoesNotThrow)
        {
            chart(-1.0, 1.0, 5);
            chart(squareRoot, -2.0, 2.0, 5);
            chart(nullptr, 0.0, 1.0, 3);
            chart(parabola, 0.0, 1.0, 0);
        }
    };

    TEST_CLASS(GcdRecursiveTests)
    {
    public:
        TEST_METHOD(PositiveNumbers)
        {
            Assert::AreEqual(12, gcdRecursive(48, 36));
            Assert::AreEqual(1, gcdRecursive(17, 5));
            Assert::AreEqual(5, gcdRecursive(5, 5));
        }

        TEST_METHOD(NegativeNumbers)
        {
            Assert::AreEqual(12, gcdRecursive(-48, 36));
            Assert::AreEqual(12, gcdRecursive(-48, -36));
        }

        TEST_METHOD(OneZeroArgument)
        {
            Assert::AreEqual(9, gcdRecursive(0, 9));
            Assert::AreEqual(9, gcdRecursive(-9, 0));
        }

        TEST_METHOD(BothZeroThrows)
        {
            Assert::ExpectException<int>([]() { gcdRecursive(0, 0); });
        }

        TEST_METHOD(MinimalIntThrows)
        {
            Assert::ExpectException<int>([]() { gcdRecursive(-2147483647 - 1, 2); });
        }
    };

    TEST_CLASS(GcdIterativeTests)
    {
    public:
        TEST_METHOD(PositiveNumbers)
        {
            Assert::AreEqual(12, gcdIterative(48, 36));
            Assert::AreEqual(1, gcdIterative(17, 5));
            Assert::AreEqual(5, gcdIterative(5, 5));
        }

        TEST_METHOD(NegativeNumbers)
        {
            Assert::AreEqual(12, gcdIterative(-48, 36));
            Assert::AreEqual(12, gcdIterative(-48, -36));
        }

        TEST_METHOD(OneZeroArgument)
        {
            Assert::AreEqual(9, gcdIterative(0, 9));
            Assert::AreEqual(9, gcdIterative(-9, 0));
        }

        TEST_METHOD(BothZeroThrows)
        {
            Assert::ExpectException<int>([]() { gcdIterative(0, 0); });
        }

        TEST_METHOD(SameResultAsRecursive)
        {
            Assert::AreEqual(gcdRecursive(1071, 462), gcdIterative(1071, 462));
            Assert::AreEqual(gcdRecursive(2147483647, 1000000), gcdIterative(2147483647, 1000000));
        }
    };

    TEST_CLASS(PowerTests)
    {
    public:
        TEST_METHOD(PositiveExponent)
        {
            Assert::AreEqual(1024.0, power(2.0, 10), tolerance);
            Assert::AreEqual(2.25, power(1.5, 2), tolerance);
        }

        TEST_METHOD(NegativeBase)
        {
            Assert::AreEqual(-27.0, power(-3.0, 3), tolerance);
            Assert::AreEqual(81.0, power(-3.0, 4), tolerance);
        }

        TEST_METHOD(NegativeExponent)
        {
            Assert::AreEqual(0.25, power(2.0, -2), tolerance);
            Assert::AreEqual(-0.125, power(-2.0, -3), tolerance);
        }

        TEST_METHOD(ZeroExponent)
        {
            Assert::AreEqual(1.0, power(7.5, 0), tolerance);
            Assert::AreEqual(1.0, power(0.0, 0), tolerance);
        }

        TEST_METHOD(ZeroBase)
        {
            Assert::AreEqual(0.0, power(0.0, 5), tolerance);
        }

        TEST_METHOD(ZeroBaseNegativeExponentThrows)
        {
            Assert::ExpectException<int>([]() { power(0.0, -1); });
        }

        TEST_METHOD(MinimalIntExponent)
        {
            Assert::AreEqual(1.0, power(1.0, -2147483647 - 1), tolerance);
        }
    };

    TEST_CLASS(CalculateTests)
    {
    public:
        TEST_METHOD(AllOperations)
        {
            Assert::AreEqual(2.0, calculate("6-4"), tolerance);
            Assert::AreEqual(10.0, calculate("2*5"), tolerance);
            Assert::AreEqual(3.0, calculate("3/1"), tolerance);
            Assert::AreEqual(17.0, calculate("8+9"), tolerance);
        }

        TEST_METHOD(NegativeAndFractionalResults)
        {
            Assert::AreEqual(-7.0, calculate("2-9"), tolerance);
            Assert::AreEqual(3.5, calculate("7/2"), tolerance);
        }

        TEST_METHOD(DivisionByZeroThrows)
        {
            Assert::ExpectException<int>([]() { calculate("5/0"); });
        }

        TEST_METHOD(InvalidOperationThrows)
        {
            int code = 0;
            try {
                calculate("4%2");
            } catch (int error) {
                code = error;
            }
            Assert::AreEqual(ERROR_INVALID_OPERATION, code);
        }

        TEST_METHOD(InvalidFormatThrows)
        {
            Assert::ExpectException<int>([]() { calculate("12+3"); });
            Assert::ExpectException<int>([]() { calculate("a+1"); });
            Assert::ExpectException<int>([]() { calculate("1+"); });
            Assert::ExpectException<int>([]() { calculate(""); });
            Assert::ExpectException<int>([]() { calculate(nullptr); });
        }
    };
}
