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

    /* invaild digit string middle */
    try {
        std::string maxDigitString{"12a3456789012345678901234567890123456789"};
        HugeInteger int4{maxDigitString};
    }
    catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "must be a string of digits");
    }

    /* invaild digit string end */
    try {
        std::string maxDigitString{"123456789012345678901234567890123456789z"};
        HugeInteger int4{maxDigitString};
    }
    catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "must be a string of digits");
    }

    /* invaild digit string beginning */
    try {
        std::string maxDigitString{"e123456789012345678901234567890123456789z"};
        HugeInteger int4{maxDigitString};
    }
    catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "must be a string of digits");
    }
}

/**
 * @brief Addition + operator overload with ints and HugeIntegers
 * 
 */
TEST(Operators, addition) {

    /* single digit string */
    HugeInteger int1{"5"};
    HugeInteger int2{"4"};
    HugeInteger int3 = int1 + int2;
    HugeInteger int4{"6"};

    std::ostringstream output1;
    std::ostringstream output2;

    output1 << int3;
    output2 << int1 + int4;

    /* Add two single digit integers no carry */
    EXPECT_STREQ(output1.str().c_str(), "9");

    /* Add two single digit integers with carray */
    EXPECT_STREQ(output2.str().c_str(), "11");

    /* Add two random huge integers */
    HugeInteger int5{"234235324534747345345"};
    HugeInteger int6{"334534634664645756869856"};
    std::ostringstream output3;

    output3 << int5 +int6;
    EXPECT_STREQ(output3.str().c_str(), "334768869989180504215201");

    /* Add max random huge integers */
    HugeInteger int7{"9999999999999999999999999999999999999999"};
    HugeInteger int8{"1"};

    std::ostringstream output4;

    output4 << int7 +int8;
    EXPECT_STREQ(output4.str().c_str(), "0");
}