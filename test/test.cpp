#include <gtest/gtest.h>
#include "../lib/sad.h"

TEST(basic_test_set, test_1)
{
    ASSERT_TRUE(sad("monday",1)==false);
}

TEST(basic_test_set, test_2)
{
    ASSERT_TRUE(sad("monday",12)==true);
}

TEST(basic_test_set, test_3)
{
    ASSERT_TRUE(sad("tuesday",222)==true);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}