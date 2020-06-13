#include <gtest/gtest.h>
#include <sstream>
#include <Ex_10_9.h>


/**
 * @brief Instantiate HugeInteger with no arguments.
 * 
 */
TEST(Constructor, Default) {

    HugeInteger int1;

    EXPECT_EQ(int1.str(), "0");
}

/**
 * @brief Instantiate a HugeInteger using an integer.
 * 
 */
TEST(Constructor, Integer) {
    
    /* zero */
    HugeInteger int1{0};

    EXPECT_EQ(int1.str(), "0");

    /* single digit */
    int single_digit_int{3};
    HugeInteger int2{single_digit_int};
    EXPECT_EQ(int2.str(), std::to_string(single_digit_int));

    /* multi digit */
    int multi_digit_int{12345678};
    HugeInteger int3{multi_digit_int};
    EXPECT_EQ(int3.str(), std::to_string(multi_digit_int));

    /* maximum positive long */
    long int max_long{0x7FFFFFFFFFFFFFFF};
    HugeInteger int4{max_long};
    EXPECT_EQ(int4.str(), std::to_string(max_long));

}

/**
 * @brief Instantiate a HugeInteger using a string.
 * 
 */
TEST(Constructor, String) {

    /* single digit string */
    std::string singleDigitString{"1"};
    HugeInteger int1{singleDigitString};

    EXPECT_EQ(int1.str(), singleDigitString.c_str());

    /* multi digit string */
    std::string multiDigitString{"1234234235"};
    HugeInteger int2{multiDigitString};

    EXPECT_EQ(int2.str(), multiDigitString.c_str());

    /* max digit string */
    std::string maxDigitString{"1234567890123456789012345678901234567890"};
    HugeInteger int3{maxDigitString};

    EXPECT_EQ(int3.str(), maxDigitString.c_str());

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
 * @brief Addition operator overloaded with HugeIntegers
 * 
 */
TEST(Addition, HugeIntegers) {

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
 * @brief Addition operator overload with Integers
 * 
 */
TEST(Addition, Integers) {

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
 * @brief Addition operator overloaded with Strings
 * 
 */
TEST(Addition, Strings) {

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
 * @brief Multiplication operator overloaded with integers
 * 
 */
TEST(Multiplication, Integers) {

    HugeInteger int1{3};
    HugeInteger int2{10};
    HugeInteger int3{0};

    /* Single digit identity */
    int3 = int1 * 1;
    EXPECT_EQ(int3.str(), int1.str());
 
    /* Double digit identity */
    int3 = int2 * 1;
    EXPECT_EQ(int3.str(), int2.str());

    /* Single digit zero multiplier */
    int3 = int1 * 0;
    EXPECT_EQ(int3.str(), "0");

    /* Double digit zero multiplier */
    int3 = int2 * 0;
    EXPECT_EQ(int3.str(), "0");

    /* Single digit no carry */
    int3 = int1 * 2;
    EXPECT_EQ(int3.str(), "6");

    /* Double digit with no carry */
    int3 = int2 * 10;
    EXPECT_EQ(int3.str(), "100");

    /* Single digit with carry */
    int3 = int1 * 4;
    EXPECT_EQ(int3.str(), "12");

    /* Double digit with carry */
    int2 = 15;
    int3 = int2 * 15;
    EXPECT_EQ(int3.str(), "225");

    /* Maximum long multiplication */
    int1 = 0x7FFFFFFF;
    int3 = int1 * 0x7FFFFFFF;
    EXPECT_EQ(int3.str(), "4611686014132420609");
}