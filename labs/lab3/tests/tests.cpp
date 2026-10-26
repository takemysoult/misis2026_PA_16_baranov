#include <cmath>
#include "CppUnitTest.h"
#include "../header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab3Tests
{
    const double eps = 1e-15;
    const double PI = 3.14159265358979323846;

    double relativeError(double expected, double actual) {
        double difference = expected - actual;
        if (difference < 0.0) difference = -difference;
        double scale = expected < 0.0 ? -expected : expected;
        return scale > 1.0 ? difference / scale : difference;
    }

    TEST_CLASS(GcdTests)
    {
    public:
        TEST_METHOD(PositiveNumbers)
        {
            Assert::AreEqual(6, gcd(12, 18));
            Assert::AreEqual(1, gcd(17, 5));
        }

        TEST_METHOD(NegativeNumbers)
        {
            Assert::AreEqual(12, gcd(-48, 36));
            Assert::AreEqual(12, gcd(-48, -36));
        }

        TEST_METHOD(ZeroArguments)
        {
            Assert::AreEqual(7, gcd(0, 7));
            Assert::AreEqual(7, gcd(-7, 0));
            Assert::AreEqual(0, gcd(0, 0));
        }

        TEST_METHOD(MinimalIntThrows)
        {
            Assert::ExpectException<int>([]() { gcd(-2147483647 - 1, 2); });
        }
    };

    TEST_CLASS(FastOperationTests)
    {
    public:
        TEST_METHOD(MultiplyByTwo)
        {
            Assert::AreEqual(14U, mul_2(7U));
            Assert::AreEqual(0U, mul_2(0U));
        }

        TEST_METHOD(DivideByTwo)
        {
            Assert::AreEqual(3U, div_2(7U));
            Assert::AreEqual(5U, div_2(10U));
        }

        TEST_METHOD(Odd)
        {
            Assert::IsTrue(odd(7U));
            Assert::IsFalse(odd(10U));
            Assert::IsFalse(odd(0U));
        }
    };

    TEST_CLASS(HarmonicSumTests)
    {
    public:
        TEST_METHOD(SmallSum)
        {
            Assert::AreEqual(1.8333333333333333, sum_1(3), 1e-15);
            Assert::AreEqual(1.8333333333333333, sum_2(3), 1e-15);
        }

        TEST_METHOD(EmptySum)
        {
            Assert::AreEqual(0.0, sum_1(0), 1e-15);
            Assert::AreEqual(0.0, sum_2(-5), 1e-15);
        }

        TEST_METHOD(LargeSumsAreClose)
        {
            Assert::AreEqual(sum_2(2000), sum_1(2000), 1e-12);
        }
    };

    TEST_CLASS(GetBitTests)
    {
    public:
        TEST_METHOD(BitsOfFive)
        {
            Assert::AreEqual(1, getBit(5, 0));
            Assert::AreEqual(0, getBit(5, 1));
            Assert::AreEqual(1, getBit(5, 2));
            Assert::AreEqual(0, getBit(5, 3));
        }

        TEST_METHOD(SignBit)
        {
            Assert::AreEqual(1, getBit(-1, 31));
            Assert::AreEqual(0, getBit(2147483647, 31));
        }

        TEST_METHOD(ZeroNumber)
        {
            Assert::AreEqual(0, getBit(0, 0));
            Assert::AreEqual(0, getBit(0, 31));
        }

        TEST_METHOD(InvalidIndexThrows)
        {
            Assert::ExpectException<int>([]() { getBit(5, -1); });
            Assert::ExpectException<int>([]() { getBit(5, 32); });
        }
    };

    TEST_CLASS(SetAndClearBitTests)
    {
    public:
        TEST_METHOD(SetBit)
        {
            Assert::AreEqual(7, setBit(5, 1));
            Assert::AreEqual(5, setBit(5, 0));
            Assert::AreEqual(1, setBit(0, 0));
            Assert::AreEqual(-2147483647 - 1, setBit(0, 31));
        }

        TEST_METHOD(ClearBit)
        {
            Assert::AreEqual(4, clearBit(5, 0));
            Assert::AreEqual(5, clearBit(5, 1));
            Assert::AreEqual(2147483647, clearBit(-1, 31));
            Assert::AreEqual(-2, clearBit(-1, 0));
        }

        TEST_METHOD(InvalidIndexThrows)
        {
            Assert::ExpectException<int>([]() { setBit(5, 32); });
            Assert::ExpectException<int>([]() { clearBit(5, -3); });
        }
    };

    TEST_CLASS(TaylorExpTests)
    {
    public:
        TEST_METHOD(Zero)
        {
            Assert::AreEqual(1.0, taylorExp(0.0, eps), 1e-15);
        }

        TEST_METHOD(SmallPositiveArguments)
        {
            Assert::AreEqual(std::exp(1.0), taylorExp(1.0, eps), 1e-14);
            Assert::AreEqual(std::exp(0.5), taylorExp(0.5, eps), 1e-14);
        }

        TEST_METHOD(NegativeArguments)
        {
            Assert::AreEqual(std::exp(-1.0), taylorExp(-1.0, eps), 1e-14);
            Assert::AreEqual(std::exp(-10.0), taylorExp(-10.0, eps), 1e-17);
            Assert::AreEqual(std::exp(-30.0), taylorExp(-30.0, eps), 1e-25);
        }

        TEST_METHOD(LargeArguments)
        {
            Assert::IsTrue(relativeError(std::exp(10.0), taylorExp(10.0, eps)) < 1e-13);
            Assert::IsTrue(relativeError(std::exp(50.0), taylorExp(50.0, eps)) < 1e-13);
        }

        TEST_METHOD(LowPrecision)
        {
            Assert::AreEqual(std::exp(1.0), taylorExp(1.0, 1e-3), 1e-3);
        }

        TEST_METHOD(InvalidPrecisionThrows)
        {
            Assert::ExpectException<int>([]() { taylorExp(1.0, 0.0); });
            Assert::ExpectException<int>([]() { taylorExp(1.0, -1e-5); });
        }
    };

    TEST_CLASS(TaylorSinTests)
    {
    public:
        TEST_METHOD(Zero)
        {
            Assert::AreEqual(0.0, taylorSin(0.0, eps), 1e-15);
        }

        TEST_METHOD(StandardAngles)
        {
            Assert::AreEqual(std::sin(PI / 6.0), taylorSin(PI / 6.0, eps), 1e-14);
            Assert::AreEqual(std::sin(PI / 2.0), taylorSin(PI / 2.0, eps), 1e-14);
            Assert::AreEqual(std::sin(3.0), taylorSin(3.0, eps), 1e-14);
        }

        TEST_METHOD(NegativeArguments)
        {
            Assert::AreEqual(std::sin(-1.0), taylorSin(-1.0, eps), 1e-14);
            Assert::AreEqual(std::sin(-PI / 2.0), taylorSin(-PI / 2.0, eps), 1e-14);
            Assert::AreEqual(std::sin(-5.5), taylorSin(-5.5, eps), 1e-14);
        }

        TEST_METHOD(LargePositiveArguments)
        {
            Assert::AreEqual(std::sin(201.0), taylorSin(201.0, eps), 1e-12);
            Assert::AreEqual(std::sin(250.0), taylorSin(250.0, eps), 1e-12);
            Assert::AreEqual(std::sin(1000.5), taylorSin(1000.5, eps), 1e-12);
            Assert::AreEqual(std::sin(123456.789), taylorSin(123456.789, eps), 1e-10);
        }

        TEST_METHOD(LargeNegativeArguments)
        {
            Assert::AreEqual(std::sin(-201.0), taylorSin(-201.0, eps), 1e-12);
            Assert::AreEqual(std::sin(-777.7), taylorSin(-777.7, eps), 1e-12);
            Assert::AreEqual(std::sin(-1000.5), taylorSin(-1000.5, eps), 1e-12);
        }

        TEST_METHOD(InvalidArgumentsThrow)
        {
            Assert::ExpectException<int>([]() { taylorSin(1.0, 0.0); });
            Assert::ExpectException<int>([]() { taylorSin(1e20, eps); });
        }
    };
}
