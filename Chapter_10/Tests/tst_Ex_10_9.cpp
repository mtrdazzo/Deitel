#include <gtest/gtest.h>
#include <sstream>
#include <Ex_10_9.h>

/**
 * @brief Create single digit and double HugeIntegers.
 * 
 */
TEST(Constructor, SingleMultiDigitIntegers) {
    
    /* zero */
    HugeInteger int1;
    std::ostringstream output1;

    output1 << int1;

    EXPECT_STREQ(output1.str().c_str(), "0");

    /* single digit */
    HugeInteger int2{3};
    std::ostringstream output2;

    output2 << int2;

    EXPECT_STREQ(output2.str().c_str(), "3");

    /* multi digit */
    HugeInteger int3{99};
    std::ostringstream output3;

    output3 << int3;

    EXPECT_STREQ(output3.str().c_str(), "99");

    /* maximum positive long */
    HugeInteger int4{0x7FFFFFFFFFFFFFFF};
    std::ostringstream output4;

    output4 << int4;

    EXPECT_STREQ(output4.str().c_str(), "9223372036854775807");
}