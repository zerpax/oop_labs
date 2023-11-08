#include <gtest/gtest.h>
#include "seven.h"


TEST(basic_test_set, test_1)
{
    ASSERT_TRUE(Seven("").Equals(Seven("")));
}

TEST(basic_test_set, test_2)
{
    ASSERT_TRUE(Seven("123").Equals(Seven("123")));
}

TEST(basic_test_set, test_3)
{
    ASSERT_TRUE(Seven("250").Equals(Seven("124").Plus(Seven("123"))));
}


TEST(basic_test_set, test_4)
{
    ASSERT_TRUE(Seven("1").Equals(Seven("124").Minus(Seven("123"))));
}

TEST(basic_test_set, test_5)
{
    ASSERT_TRUE((Seven("123").Copy(Seven("321"))).Equals(Seven("321")));
}

TEST(basic_test_set, test_6)
{
    ASSERT_TRUE(Seven("123").Greater(Seven("122")));
}

TEST(basic_test_set, test_7)
{
    ASSERT_TRUE(Seven("123").Less(Seven("124")));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}