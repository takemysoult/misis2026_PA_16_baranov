#include <iostream>
#include <sstream>
#include <string>
#include <gtest/gtest.h>
#include "../header.h"

const double tolerance = 1e-9;

// print_binary печатает в cout поэтому забираем напечатанное в строку
std::string printed(int n) {
    std::ostringstream output;
    std::streambuf* old = std::cout.rdbuf(output.rdbuf());
    print_binary(n);
    std::cout.rdbuf(old);
    return output.str();
}


TEST(ReplaceDigitTests, PositiveNumber) {
    EXPECT_EQ(3833, replace_digit(3233, 2, 8));
    EXPECT_EQ(1551, replace_digit(1221, 2, 5));
}

TEST(ReplaceDigitTests, NegativeNumber) {
    EXPECT_EQ(-707, replace_digit(-202, 2, 7));
}

TEST(ReplaceDigitTests, NoSuchDigit) {
    EXPECT_EQ(123, replace_digit(123, 9, 1));
}

TEST(ReplaceDigitTests, Zero) {
    EXPECT_EQ(5, replace_digit(0, 0, 5));
}

TEST(ReplaceDigitTests, WrongDigitThrows) {
    EXPECT_THROW(replace_digit(123, 10, 1), int);
}


TEST(IntersectionAreaTests, PartialOverlap) {
    EXPECT_NEAR(4.0, intersection_area(0, 0, 4, 3, 2, 1, 6, 5), tolerance);
}

TEST(IntersectionAreaTests, OneInsideAnother) {
    EXPECT_NEAR(4.0, intersection_area(0, 0, 10, 10, 2, 2, 4, 4), tolerance);
}

TEST(IntersectionAreaTests, NoIntersection) {
    EXPECT_NEAR(0.0, intersection_area(0, 0, 1, 1, 2, 2, 3, 3), tolerance);
}

TEST(IntersectionAreaTests, WrongCornersThrows) {
    EXPECT_THROW(intersection_area(4, 0, 0, 3, 2, 1, 6, 5), int);
}


TEST(LnDivTests, Zero) {
    EXPECT_NEAR(0.0, t_ln_div(0.0, 1e-9), tolerance);
}

TEST(LnDivTests, Half) {
    // ln((1 + 0.5) / (1 - 0.5)) = ln 3
    EXPECT_NEAR(1.0986122887, t_ln_div(0.5, 1e-12), 1e-9);
}

TEST(LnDivTests, MinusHalf) {
    EXPECT_NEAR(-1.0986122887, t_ln_div(-0.5, 1e-12), 1e-9);
}

TEST(LnDivTests, XEqualsOneThrows) {
    EXPECT_THROW(t_ln_div(1.0, 1e-6), int);
}

TEST(LnDivTests, ZeroEpsThrows) {
    EXPECT_THROW(t_ln_div(0.5, 0.0), int);
}


TEST(PrintBinaryTests, Zero) {
    EXPECT_EQ("0", printed(0));
}

TEST(PrintBinaryTests, Five) {
    EXPECT_EQ("101", printed(5));
}

TEST(PrintBinaryTests, Eight) {
    EXPECT_EQ("1000", printed(8));
}

TEST(PrintBinaryTests, NegativeNumber) {
    EXPECT_EQ("-110", printed(-6));
}
