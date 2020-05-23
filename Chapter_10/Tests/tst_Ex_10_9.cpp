#include <gtest/gtest.h>
#include <sstream>
#include <Ex_10_9.h>

/**
 * @brief Create single digit and double HugeIntegers using longs.
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

/**
 * @brief Create single digit and double HugeIntegers using strings.
 * 
 */
TEST(Constructor, SingleMultiDigitStrings) {

    /* single digit string */
    std::string singleDigitString{"1"};
    HugeInteger int1{singleDigitString};
    std::ostringstream output1;

    output1 << int1;

    EXPECT_STREQ(output1.str().c_str(), singleDigitString.c_str());


    /* multi digit string */
    std::string multiDigitString{"1234234235"};
    HugeInteger int2{multiDigitString};
    std::ostringstream output2;

    output2 << int2;

    EXPECT_STREQ(output2.str().c_str(), multiDigitString.c_str());

    /* max digit string */
    std::string maxDigitString{"1234567890123456789012345678901234567890"};
    HugeInteger int3{maxDigitString};
    std::ostringstream output3;

    output3 << int3;

    EXPECT_STREQ(output3.str().c_str(), maxDigitString.c_str());

    /* invaild digit string */
    try {
        std::string maxDigitString{"12a3456789012345678901234567890123456789"};
    }
    catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "must be a string of digits");
    }
}