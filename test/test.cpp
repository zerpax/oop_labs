#include <gtest/gtest.h>
#include "sad.h"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(sad(monday,1)==false);
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(sad(monday,12)==true);
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(sad(tuesday,222)==true);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}