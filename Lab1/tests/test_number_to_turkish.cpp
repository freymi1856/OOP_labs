#include <gtest/gtest.h>
#include "number_to_turkish.h"
#include <stdexcept>

TEST(NumberToTurkishTests, SingleDigits) {
    EXPECT_EQ(NumberToTurkish(0), "sıfır");
    EXPECT_EQ(NumberToTurkish(1), "bir");
    EXPECT_EQ(NumberToTurkish(9), "dokuz");
}

TEST(NumberToTurkishTests, Tens) {
    EXPECT_EQ(NumberToTurkish(10), "on");
    EXPECT_EQ(NumberToTurkish(20), "yirmi");
    EXPECT_EQ(NumberToTurkish(90), "doksan");
}

TEST(NumberToTurkishTests, CompositeNumbers) {
    EXPECT_EQ(NumberToTurkish(13), "on üç");
    EXPECT_EQ(NumberToTurkish(27), "yirmi yedi");
    EXPECT_EQ(NumberToTurkish(38), "otuz sekiz");
    EXPECT_EQ(NumberToTurkish(77), "yetmiş yedi");
    EXPECT_EQ(NumberToTurkish(94), "doksan dört");
}

TEST(NumberToTurkishTests, OutOfRange) {
    EXPECT_THROW(NumberToTurkish(-1), std::out_of_range);
    EXPECT_THROW(NumberToTurkish(100), std::out_of_range);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}