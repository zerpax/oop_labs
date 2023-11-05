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

TEST(basic_test_set, test_4)
{
    ASSERT_TRUE(sad("wednesday",34)==true);
}

TEST(basic_test_set, test_5)
{
    ASSERT_TRUE(sad("thursday",0)==true);
}

TEST(basic_test_set, test_6)
{
    ASSERT_TRUE(sad("friday",100)==true);
}

TEST(basic_test_set, test_7)
{
    ASSERT_TRUE(sad("saturday",56)==true);
}

TEST(basic_test_set, test_8)
{
    ASSERT_TRUE(sad("sunday",-666)==true);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}