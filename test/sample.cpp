#include "calculator.h"
#include <gtest/gtest.h>

TEST(MathOperTest, SampleTests)
{
    ASSERT_EQ(2, calculate("1 + 1"));
    ASSERT_EQ(0, calculate("1 - 1"));
    ASSERT_EQ(-8, calculate("1 + -(4 + 5)"));
    ASSERT_EQ(6, calculate("2 + 2 * 2"));
    ASSERT_EQ(-2, calculate("2 + 2 * -2"));
    ASSERT_EQ(0.5, calculate("1/2"));
    ASSERT_EQ(2, calculate("-1 * -2"));
}

int main(int argc, char ** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
