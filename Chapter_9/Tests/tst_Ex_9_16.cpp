#include <Ex_9_16.h>
#include <gtest/gtest.h>

/**
 * @brief Create BrokenEncapsulation object with no arguments.
 */
TEST(Constructor, NoArguments) {

    BrokenEncapsulation test;

    EXPECT_EQ(0, test.getData());
}

/**
 * @brief Create a BrokenEncapsulation object with a single argument.
 */
TEST(Constructor, SingleArgument) {

    BrokenEncapsulation test{1};

    EXPECT_EQ(1, test.getData());
}

/**
 * @brief Get Private Data from BrokenEncapsulation objects.
 */
TEST(GetPrivateData, BreakEncapsulation1) {

    BrokenEncapsulation test{1};
    int *privateData;

    EXPECT_EQ(1, test.getData());

    privateData = test.getPrivateInt1();
    *privateData = 2;

    EXPECT_EQ(*privateData, test.getData());
}

/**
 * @brief Change private member of BrokenEncapsulation object.
 */
TEST(GetPrivateData, BreakEncapsulation2) {

    BrokenEncapsulation test{1};
    int &privateData = test.getPrivateInt2();

    EXPECT_EQ(1, test.getData());

    privateData = 2;

    EXPECT_EQ(privateData, test.getData());
}