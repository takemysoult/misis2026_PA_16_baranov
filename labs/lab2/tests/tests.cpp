#include "CppUnitTest.h"
#include "../header.h"
#include "../../lab1/header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab2Tests
{
    const double tolerance = 1e-9;

    TEST_CLASS(DistanceTests)
    {
    public:
        TEST_METHOD(EgyptianTriangle)
        {
            Assert::AreEqual(5.0, Distance(0.0, 0.0, 3.0, 4.0), tolerance);
        }

        TEST_METHOD(SamePoint)
        {
            Assert::AreEqual(0.0, Distance(1.5, -2.0, 1.5, -2.0), tolerance);
        }

        TEST_METHOD(NegativeCoordinates)
        {
            Assert::AreEqual(5.0, Distance(-1.0, -1.0, -4.0, -5.0), tolerance);
        }

        TEST_METHOD(FractionalResult)
        {
            Assert::AreEqual(1.4142135623730951, Distance(0.0, 0.0, 1.0, 1.0), tolerance);
        }

        TEST_METHOD(PointOverload)
        {
            point a = {1.0, 2.0};
            point b = {4.0, 6.0};
            Assert::AreEqual(5.0, Distance(a, b), tolerance);
        }
    };

    TEST_CLASS(SquareTests)
    {
    public:
        TEST_METHOD(RightTriangle)
        {
            Assert::AreEqual(6.0, Square(0.0, 0.0, 4.0, 0.0, 0.0, 3.0), tolerance);
        }

        TEST_METHOD(ClockwiseOrderGivesPositiveArea)
        {
            Assert::AreEqual(6.0, Square(0.0, 0.0, 0.0, 3.0, 4.0, 0.0), tolerance);
        }

        TEST_METHOD(NegativeCoordinates)
        {
            Assert::AreEqual(2.0, Square(-1.0, -1.0, -3.0, -1.0, -1.0, -3.0), tolerance);
        }

        TEST_METHOD(CollinearPoints)
        {
            Assert::AreEqual(0.0, Square(0.0, 0.0, 1.0, 1.0, 2.0, 2.0), tolerance);
        }

        TEST_METHOD(CoincidentPoints)
        {
            Assert::AreEqual(0.0, Square(2.0, 2.0, 2.0, 2.0, 2.0, 2.0), tolerance);
        }
    };

    TEST_CLASS(DistanceToLineTests)
    {
    public:
        TEST_METHOD(HorizontalLine)
        {
            Assert::AreEqual(3.0, Distance_to_line(0.0, 3.0, 0.0, 0.0, 4.0, 0.0), tolerance);
        }

        TEST_METHOD(PointBelowLine)
        {
            Assert::AreEqual(3.0, Distance_to_line(1.0, -3.0, 0.0, 0.0, 4.0, 0.0), tolerance);
        }

        TEST_METHOD(DiagonalLine)
        {
            Assert::AreEqual(1.4142135623730951, Distance_to_line(0.0, 2.0, 0.0, 0.0, 1.0, 1.0), tolerance);
        }

        TEST_METHOD(PointOnLine)
        {
            Assert::AreEqual(0.0, Distance_to_line(5.0, 5.0, 0.0, 0.0, 1.0, 1.0), tolerance);
        }

        TEST_METHOD(DegenerateLine)
        {
            Assert::AreEqual(-1.0, Distance_to_line(0.0, 0.0, 1.0, 1.0, 1.0, 1.0), tolerance);
        }
    };

    TEST_CLASS(TriangleTypeTests)
    {
    public:
        TEST_METHOD(ArbitraryTriangle)
        {
            Assert::AreEqual(0, Check_triangle_type(0.0, 0.0, 3.0, 0.0, 0.0, 4.0));
        }

        TEST_METHOD(IsoscelesTriangle)
        {
            Assert::AreEqual(1, Check_triangle_type(0.0, 0.0, 4.0, 0.0, 2.0, 5.0));
        }

        TEST_METHOD(EquilateralTriangle)
        {
            Assert::AreEqual(2, Check_triangle_type(0.0, 0.0, 2.0, 0.0, 1.0, 1.7320508075688772));
        }

        TEST_METHOD(CollinearPointsAreNotTriangle)
        {
            Assert::AreEqual(-1, Check_triangle_type(0.0, 0.0, 1.0, 1.0, 2.0, 2.0));
        }

        TEST_METHOD(CoincidentPointsAreNotTriangle)
        {
            Assert::AreEqual(-1, Check_triangle_type(1.0, 1.0, 1.0, 1.0, 3.0, 2.0));
        }

        TEST_METHOD(EnumVersion)
        {
            Assert::AreEqual(static_cast<int>(tIsoscel),
                             static_cast<int>(Check_triangle_type_new(0.0, 0.0, 4.0, 0.0, 2.0, 5.0)));
            Assert::AreEqual(static_cast<int>(tInvalid),
                             static_cast<int>(Check_triangle_type_new(0.0, 0.0, 1.0, 1.0, 2.0, 2.0)));
        }

        TEST_METHOD(PointVersion)
        {
            point a = {0.0, 0.0};
            point b = {2.0, 0.0};
            point c = {1.0, 1.7320508075688772};
            Assert::AreEqual(static_cast<int>(tEqui), static_cast<int>(Check_triangle_type_new(a, b, c)));
        }
    };

    TEST_CLASS(Lab1FactorialTests)
    {
    public:
        TEST_METHOD(Zero)
        {
            Assert::AreEqual(1LL, factorial(0));
        }

        TEST_METHOD(Five)
        {
            Assert::AreEqual(120LL, factorial(5));
        }

        TEST_METHOD(UpperBound)
        {
            Assert::AreEqual(2432902008176640000LL, factorial(20));
        }

        TEST_METHOD(NegativeArgument)
        {
            Assert::AreEqual(-1LL, factorial(-3));
        }

        TEST_METHOD(Overflow)
        {
            Assert::AreEqual(-1LL, factorial(21));
        }
    };

    TEST_CLASS(Lab1DigitTests)
    {
    public:
        TEST_METHOD(CountDigits)
        {
            Assert::AreEqual(3, countDigits(123));
            Assert::AreEqual(5, countDigits(22345));
            Assert::AreEqual(2, countDigits(-56));
            Assert::AreEqual(1, countDigits(0));
        }

        TEST_METHOD(SumDigits)
        {
            Assert::AreEqual(6, sumDigits(123));
            Assert::AreEqual(16, sumDigits(22345));
            Assert::AreEqual(11, sumDigits(-56));
            Assert::AreEqual(0, sumDigits(0));
        }

        TEST_METHOD(RemoveFirstAndLastDigits)
        {
            Assert::AreEqual(23LL, removeFirstAndLastDigits(1231));
            Assert::AreEqual(0LL, removeFirstAndLastDigits(7));
        }

        TEST_METHOD(SwapFirstAndLastDigits)
        {
            Assert::AreEqual(321LL, swapFirstAndLastDigits(123));
            Assert::AreEqual(7LL, swapFirstAndLastDigits(7));
        }
    };

    TEST_CLASS(Lab1OrderAndMaximumTests)
    {
    public:
        TEST_METHOD(OrderIntegers)
        {
            int first = 9;
            int second = 2;
            order(first, second);
            Assert::AreEqual(2, first);
            Assert::AreEqual(9, second);
        }

        TEST_METHOD(OrderAlreadySortedDoubles)
        {
            double first = -1.25;
            double second = 3.5;
            order(first, second);
            Assert::AreEqual(-1.25, first, tolerance);
            Assert::AreEqual(3.5, second, tolerance);
        }

        TEST_METHOD(MaximumOfTwo)
        {
            Assert::AreEqual(9, maximum(4, 9));
            Assert::AreEqual(2.5, maximum(2.5, 1.5), tolerance);
        }

        TEST_METHOD(MaximumOfThree)
        {
            Assert::AreEqual(9, maximum(4, 9, 6));
            Assert::AreEqual(-1, maximum(-5, -1, -3));
            Assert::AreEqual(7.1, maximum(2.5, 7.1, 3.0), tolerance);
        }
    };

    TEST_CLASS(Lab1PowerTests)
    {
    public:
        TEST_METHOD(PositiveExponent)
        {
            bool valid = false;
            Assert::AreEqual(32.0, integerPower(2, 5, valid), tolerance);
            Assert::IsTrue(valid);
        }

        TEST_METHOD(NegativeExponent)
        {
            bool valid = false;
            Assert::AreEqual(0.25, integerPower(2, -2, valid), tolerance);
            Assert::IsTrue(valid);
        }

        TEST_METHOD(ZeroToNegativePowerIsInvalid)
        {
            bool valid = true;
            integerPower(0, -1, valid);
            Assert::IsFalse(valid);
        }

        TEST_METHOD(ArmstrongNumber)
        {
            Assert::IsTrue(equalsSumOfDigitPowers(153, 3));
            Assert::IsFalse(equalsSumOfDigitPowers(154, 3));
        }
    };
}
