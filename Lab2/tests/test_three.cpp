#include "three.h"
#include <gtest/gtest.h>

TEST(ThreeTests, ConstructorDefault) {
    Three num;
    EXPECT_EQ(num.toString(), "0");
}

TEST(ThreeTests, ConstructorFromString) {
    Three num("102");
    EXPECT_EQ(num.toString(), "102");
}

TEST(ThreeTests, Addition) {
    Three num1("12");
    Three num2("21");
    Three result = num1 + num2;
    EXPECT_EQ(result.toString(), "110");
}

TEST(ThreeTests, Subtraction) {
    Three num1("210");
    Three num2("12");
    Three result = num1 - num2;
    EXPECT_EQ(result.toString(), "121");
}

TEST(ThreeTests, ComparisonEqual) {
    Three num1("102");
    Three num2("102");
    EXPECT_TRUE(num1 == num2);
}

TEST(ThreeTests, ComparisonNotEqual) {
    Three num1("102");
    Three num2("210");
    EXPECT_TRUE(num1 != num2);
}

TEST(ThreeTests, OutOfRangeError) {
    EXPECT_THROW(Three("1234"), std::invalid_argument);
}