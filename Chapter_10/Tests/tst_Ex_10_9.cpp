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
 * @brief Addition + operator overload with HugeIntegers
 * 
 */
TEST(Operators, additionOnlyHugeIntegers) {

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

/**
 * @brief Addition + operator overload with ints and HugeIntegers
 * 
 */
TEST(Operators, additionWithInts) {

    /* single digit add */
    HugeInteger int1{"5"};
    int int2{4};
    HugeInteger int3 = int1 + int2;
    int int4{6};

    std::ostringstream output1;
    std::ostringstream output2;

    output1 << int3;
    output2 << int1 + int4;

    /* Add single digit HugeInteger and int with no carry */
    EXPECT_STREQ(output1.str().c_str(), "9");

    /* Add single digit HugeInteger and int with carry */
    EXPECT_STREQ(output2.str().c_str(), "11");

    /* Adds two random huge integers */
    HugeInteger int5{"234235324534747345345"};
    int int6{0x7FFFFFFF};
    std::ostringstream output3;

    output3 << int5 +int6;
    EXPECT_STREQ(output3.str().c_str(), "234235324536894828992");

    /* Add max random huge integers */
    HugeInteger int7{"9999999999999999999999999999999999999999"};
    int int8{1};

    std::ostringstream output4;

    output4 << int7 +int8;
    EXPECT_STREQ(output4.str().c_str(), "0");
}

/**
 * @brief Addition + operator overload with strings and HugeIntegers
 * 
 */
TEST(Operators, additionWithString) {

    /* single digit add */
    HugeInteger int1{"5"};
    std::string int2{"4"};
    HugeInteger int3 = int1 + int2;
    std::string int4{"6"};

    std::ostringstream output1;
    std::ostringstream output2;

    output1 << int3;
    output2 << int1 + int4;

    /* Add single digit HugeInteger and int with no carry */
    EXPECT_STREQ(output1.str().c_str(), "9");

    /* Add single digit HugeInteger and int with carry */
    EXPECT_STREQ(output2.str().c_str(), "11");

    /* Add two random huge integers */
    HugeInteger int5{"234235324534747345345"};
    std::string int6{"2147483647"};
    std::ostringstream output3;

    output3 << int5 +int6;
    EXPECT_STREQ(output3.str().c_str(), "234235324536894828992");

    /* Add max random huge integers */
    HugeInteger int7{"9999999999999999999999999999999999999999"};
    std::string int8{"1"};

    std::ostringstream output4;

    output4 << int7 +int8;
    EXPECT_STREQ(output4.str().c_str(), "0");
}

/**
 * @brief Multiplication * operator with integers
 * 
 */
TEST(Operators, multiplicationWithInt) {

    HugeInteger int1{3};
    HugeInteger int2{10};
    HugeInteger int3{0};

    /* Single digit identity */
    int3 = int1 * 1;
    EXPECT_EQ(int3.str(), "3");
 
    /* Single digit zero multiplier */
    int3 = int1 * 0;
    EXPECT_EQ(int3.str(), "0");

    /* Double digit zero multiplier */
    int3 = int2 * 0;
    EXPECT_EQ(int3.str(), "0");

    /* Single digit no carry */
    int3 = int1 * 2;
    EXPECT_EQ(int3.str(), "6");

    /* Single digit with carry */
    int3 = int1 * 4;
    EXPECT_EQ(int3.str(), "12");

    /* Double digit identity */
    int3 = int3 * 1;
    EXPECT_EQ(int3.str(), "12");

    /* Double digit zero multiplier */
    int3 = int3 * 0;
    EXPECT_EQ(int3.str(), "0");

    /* Double digit with no carry */
    int3 = int2 * 10;
    EXPECT_EQ(int3.str(), "100");

    int2 = 15;
    int3 = int2 * 15;

    /* Double digit with carry */
    EXPECT_EQ(int3.str(), "225");

}

TEST(operators, multiplicationAdvancedInt) {

    HugeInteger int1{12345};
    int int2{3456};
    HugeInteger int3 = int1 * int2;

    EXPECT_EQ(int3.str(), "42664320");
}