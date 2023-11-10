#include <gtest/gtest.h>
#include "seven.h"

bool Check(int correct_size, unsigned char* correct, int seven_size, unsigned char* seven) {
    if (correct_size == seven_size) {
        for (int i = 0; i < correct_size; i++) {
            if (correct[i] != seven[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

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

TEST(basic_test_set, test_8)
{
    ASSERT_TRUE(Seven("123").Less(Seven("124")));
}

TEST(basic_test_set, test_9)
{
    Seven seven(5, '1');
    unsigned char* correct = new unsigned char[5];
    for (int i = 0; i < 5; i++) {
        correct[i] = '1';
    }
    ASSERT_TRUE(Check(5, correct, seven.Size(), seven.Value()));
}

TEST(basic_test_set, test_10)
{
    Seven seven{ '1','2','3','4','5' };
    unsigned char* correct = new unsigned char[5];
    for (int i = 0; i < 5; i++) {
        correct[i] = '1' + i;
    }
    ASSERT_TRUE(Check(5, correct, seven.Size(), seven.Value()));
}

TEST(basic_test_set, test_11)
{
    Seven seven("12345");
    unsigned char* correct = new unsigned char[5];
    for (int i = 0; i < 5; i++) {
        correct[i] = '1' + i;
    }
    ASSERT_TRUE(Check(5, correct, seven.Size(), seven.Value()));
}

TEST(basic_test_set, test_12)
{
    Seven orig("12345");
    Seven seven(orig);
    unsigned char* correct = new unsigned char[5];
    for (int i = 0; i < 5; i++) {
        correct[i] = '1' + i;
    }
    ASSERT_TRUE(Check(5, correct, seven.Size(), seven.Value()));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}