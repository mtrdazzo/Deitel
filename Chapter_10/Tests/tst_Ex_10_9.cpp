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
    HugeInteger singleDigit1{5};
    HugeInteger singleDigit2{4};
    HugeInteger singleDigit3{6};

    /* Add two single digit integers no carry */
    HugeInteger singleDigit4 = singleDigit1 + singleDigit2;
    EXPECT_EQ(singleDigit4.str(), "9");

    /* Add two single digit integers with carry */
    HugeInteger multiDigit1 = singleDigit1 + singleDigit3;
    EXPECT_EQ(multiDigit1.str(), "11");

    /* Add two random huge integers */
    HugeInteger multiDigit2{"234235324534747345345"};
    HugeInteger multiDigit3{"334534634664645756869856"};
    HugeInteger multiDigit4 = multiDigit2 + multiDigit3;
    EXPECT_EQ(multiDigit4.str(), "334768869989180504215201");

    /* Add max HugeInteger and see rollover */
    HugeInteger multiDigit5{"9999999999999999999999999999999999999999"};
    HugeInteger singleDigit5{1};
    HugeInteger zeroSum = multiDigit5 + singleDigit5;
    EXPECT_EQ(zeroSum.str(), "0");
}

/**
 * @brief Addition operator overload with Integers
 * 
 */
TEST(Addition, Integers) {

    /* single digit string */
    HugeInteger singleDigit1{5};
    int singleDigit2{4};
    int singleDigit3{6};

    /* Add two single digit integers no carry */
    HugeInteger singleDigit4 = singleDigit1 + singleDigit2;
    EXPECT_EQ(singleDigit4.str(), "9");

    /* Add two single digit integers with carry */
    HugeInteger multiDigit1 = singleDigit1 + singleDigit3;
    EXPECT_EQ(multiDigit1.str(), "11");

    /* Add two random huge integers */
    HugeInteger multiDigit2{"234235324534747345345"};
    int multiDigit3{0x7FFFFFFF};
    HugeInteger multiDigit4 = multiDigit2 + multiDigit3;
    EXPECT_EQ(multiDigit4.str(), "234235324536894828992");

    /* Add max HugeInteger and see rollover */
    HugeInteger multiDigit5{"9999999999999999999999999999999999999999"};
    int singleDigit5{1};
    HugeInteger zeroSum = multiDigit5 + singleDigit5;
    EXPECT_EQ(zeroSum.str(), "0");
}

/**
 * @brief Addition operator overloaded with Strings
 * 
 */
TEST(Addition, Strings) {

    /* single digit string */
    HugeInteger singleDigit1{5};
    std::string singleDigit2{"4"};
    std::string singleDigit3{"6"};

    /* Add two single digit integers no carry */
    HugeInteger singleDigit4 = singleDigit1 + singleDigit2;
    EXPECT_EQ(singleDigit4.str(), "9");

    /* Add two single digit integers with carry */
    HugeInteger multiDigit1 = singleDigit1 + singleDigit3;
    EXPECT_EQ(multiDigit1.str(), "11");

    /* Add two random huge integers */
    HugeInteger multiDigit2{"234235324534747345345"};
    std::string multiDigit3{"334534634664645756869856"};
    HugeInteger multiDigit4 = multiDigit2 + multiDigit3;
    EXPECT_EQ(multiDigit4.str(), "334768869989180504215201");

    /* Add max HugeInteger and see rollover */
    HugeInteger multiDigit5{"9999999999999999999999999999999999999999"};
    std::string singleDigit5{"1"};
    HugeInteger zeroSum = multiDigit5 + singleDigit5;
    EXPECT_EQ(zeroSum.str(), "0");
}

/**
 * @brief Multiplication operator overloaded with HugeIntegers
 * 
 */
TEST(Multiplication, HugeIntegers) {

    HugeInteger int1{3};
    HugeInteger identity{1};
    HugeInteger zero{0};
    HugeInteger int2{10};
    HugeInteger int3{0};

    /* Single digit identity */
    int3 = int1 * identity;
    EXPECT_EQ(int3.str(), int1.str());
 
    /* Double digit identity */
    int3 = int2 * identity;
    EXPECT_EQ(int3.str(), int2.str());

    /* Single digit zero multiplier */
    int3 = int1 * zero;
    EXPECT_EQ(int3.str(), "0");

    /* Double digit zero multiplier */
    int3 = int2 * zero;
    EXPECT_EQ(int3.str(), "0");

    /* Single digit no carry */
    HugeInteger noCarry1{2};
    int3 = int1 * noCarry1;
    EXPECT_EQ(int3.str(), "6");

    /* Double digit with no carry */
    HugeInteger noCarry2{10};
    int3 = int2 * noCarry2;
    EXPECT_EQ(int3.str(), "100");

    /* Single digit with carry */
    HugeInteger carry1{4};
    int3 = int1 * carry1;
    EXPECT_EQ(int3.str(), "12");

    /* Double digit with carry */
    HugeInteger carry2{15};
    int2 = carry2;
    int3 = int2 * carry2;
    EXPECT_EQ(int3.str(), "225");

    /* Maximum long multiplication */
    int1 = 0x7FFFFFFF;
    HugeInteger maxLong{0x7FFFFFFF};
    int3 = int1 * maxLong;
    EXPECT_EQ(int3.str(), "4611686014132420609");
}

/**
 * @brief Multiplication operator overloaded with Integers
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

/**
 * @brief Multiplication operator overloaded with Strings
 * 
 */
TEST(Multiplication, Strings) {

    HugeInteger int1{3};
    std::string identity{"1"};
    std::string zero{"0"};
    HugeInteger int2{10};
    HugeInteger int3{0};

    /* Single digit identity */
    int3 = int1 * identity;
    EXPECT_EQ(int3.str(), int1.str());
 
    /* Double digit identity */
    int3 = int2 * identity;
    EXPECT_EQ(int3.str(), int2.str());

    /* Single digit zero multiplier */
    int3 = int1 * zero;
    EXPECT_EQ(int3.str(), "0");

    /* Double digit zero multiplier */
    int3 = int2 * zero;
    EXPECT_EQ(int3.str(), "0");

    /* Single digit no carry */
    std::string noCarry1{"2"};
    int3 = int1 * noCarry1;
    EXPECT_EQ(int3.str(), "6");

    /* Double digit with no carry */
    std::string noCarry2{"10"};
    int3 = int2 * noCarry2;
    EXPECT_EQ(int3.str(), "100");

    /* Single digit with carry */
    std::string carry1{"4"};
    int3 = int1 * carry1;
    EXPECT_EQ(int3.str(), "12");

    /* Double digit with carry */
    std::string carry2{"15"};
    int2 = carry2;
    int3 = int2 * carry2;
    EXPECT_EQ(int3.str(), "225");

    /* Maximum long multiplication */
    int1 = 0x7FFFFFFF;
    std::string maxLong{"2147483647"};
    int3 = int1 * maxLong;
    EXPECT_EQ(int3.str(), "4611686014132420609");
}

/**
 * @brief Test the equality operator
 * 
 */
TEST(EqualityOperator, EqualTo) {

    /* Single Digits */
    HugeInteger singleDigit1{5};
    HugeInteger singleDigit2{singleDigit1 + 1};
    HugeInteger singleDigit3{singleDigit2 + 1};

    EXPECT_TRUE(singleDigit2 == singleDigit2);
    EXPECT_FALSE(singleDigit2 == singleDigit3);
    EXPECT_FALSE(singleDigit2 == singleDigit1);

    /* Multiple Digits */
    HugeInteger multiDigit1{"123124134253456346"};
    HugeInteger multiDigit2{multiDigit1 + 1};
    HugeInteger multiDigit3{multiDigit2 + 1};

    EXPECT_TRUE(multiDigit2 == multiDigit2);
    EXPECT_FALSE(multiDigit2 == multiDigit3);
    EXPECT_FALSE(multiDigit2 == multiDigit1);

    /* Maximum Digits */
    HugeInteger maxDigit1{"1234567890123456789012345678901234567890"};
    HugeInteger maxDigit2{maxDigit1 + 1};
    HugeInteger maxDigit3{maxDigit2 + 1};

    /* Different numbers of digits */
    EXPECT_TRUE(maxDigit2 == maxDigit2);
    EXPECT_FALSE(maxDigit2 == maxDigit3);
    EXPECT_FALSE(maxDigit2 == maxDigit1);

    EXPECT_FALSE(singleDigit1 == multiDigit1);
    EXPECT_FALSE(multiDigit1 == maxDigit1);

    EXPECT_FALSE(multiDigit1 == singleDigit1);
    EXPECT_FALSE(maxDigit1 == multiDigit1);
}

/**
 * @brief Test the inequality operator
 * 
 */
TEST(EqualityOperator, NotEqualTo) {

    /* Single Digits */
    HugeInteger singleDigit1{5};
    HugeInteger singleDigit2{singleDigit1 + 1};
    HugeInteger singleDigit3{singleDigit2 + 1};

    EXPECT_FALSE(singleDigit2 != singleDigit2);
    EXPECT_TRUE(singleDigit2 != singleDigit3);
    EXPECT_TRUE(singleDigit2 != singleDigit1);

    /* Multiple Digits */
    HugeInteger multiDigit1{"123124134253456346"};
    HugeInteger multiDigit2{multiDigit1 + 1};
    HugeInteger multiDigit3{multiDigit2 + 1};

    EXPECT_FALSE(multiDigit2 != multiDigit2);
    EXPECT_TRUE(multiDigit2 != multiDigit3);
    EXPECT_TRUE(multiDigit2 != multiDigit1);

    /* Maximum Digits */
    HugeInteger maxDigit1{"1234567890123456789012345678901234567890"};
    HugeInteger maxDigit2{maxDigit1 + 1};
    HugeInteger maxDigit3{maxDigit2 + 1};

    /* Different numbers of digits */
    EXPECT_FALSE(maxDigit2 != maxDigit2);
    EXPECT_TRUE(maxDigit2 != maxDigit3);
    EXPECT_TRUE(maxDigit2 != maxDigit1);

    EXPECT_TRUE(singleDigit1 != multiDigit1);
    EXPECT_TRUE(multiDigit1 != maxDigit1);

    EXPECT_TRUE(multiDigit1 != singleDigit1);
    EXPECT_TRUE(maxDigit1 != multiDigit1);
}

/**
 * @brief Test the less than operator
 * 
 */
TEST(EqualityOperators, LessThan) {

    /* Single Digits */
    HugeInteger singleDigit1{5};
    HugeInteger singleDigit2{singleDigit1 + 1};
    HugeInteger singleDigit3{singleDigit2 + 1};

    EXPECT_FALSE(singleDigit2 < singleDigit2);
    EXPECT_TRUE(singleDigit2 < singleDigit3);
    EXPECT_FALSE(singleDigit2 < singleDigit1);

    /* Multiple Digits */
    HugeInteger multiDigit1{"123124134253456346"};
    HugeInteger multiDigit2{multiDigit1 + 1};
    HugeInteger multiDigit3{multiDigit2 + 1};

    EXPECT_FALSE(multiDigit2 < multiDigit2);
    EXPECT_TRUE(multiDigit2 < multiDigit3);
    EXPECT_FALSE(multiDigit2 < multiDigit1);

    /* Maximum Digits */
    HugeInteger maxDigit1{"1234567890123456789012345678901234567890"};
    HugeInteger maxDigit2{maxDigit1 + 1};
    HugeInteger maxDigit3{maxDigit2 + 1};

    /* Different numbers of digits */
    EXPECT_FALSE(maxDigit2 < maxDigit2);
    EXPECT_TRUE(maxDigit2 < maxDigit3);
    EXPECT_FALSE(maxDigit2 < maxDigit1);

    EXPECT_TRUE(singleDigit1 < multiDigit1);
    EXPECT_TRUE(multiDigit1 < maxDigit1);

    EXPECT_FALSE(multiDigit1 < singleDigit1);
    EXPECT_FALSE(maxDigit1 < multiDigit1);
}

/**
 * @brief Test the less or equal to operator
 * 
 */
TEST(EqualityOperators, LessThanEqualTo) {

    /* Single Digits */
    HugeInteger singleDigit1{5};
    HugeInteger singleDigit2{singleDigit1 + 1};
    HugeInteger singleDigit3{singleDigit2 + 1};

    EXPECT_TRUE(singleDigit2 <= singleDigit2);
    EXPECT_TRUE(singleDigit2 <= singleDigit3);
    EXPECT_FALSE(singleDigit2 <= singleDigit1);

    /* Multiple Digits */
    HugeInteger multiDigit1{"123124134253456346"};
    HugeInteger multiDigit2{multiDigit1 + 1};
    HugeInteger multiDigit3{multiDigit2 + 1};

    EXPECT_TRUE(multiDigit2 <= multiDigit2);
    EXPECT_TRUE(multiDigit2 <= multiDigit3);
    EXPECT_FALSE(multiDigit2 <= multiDigit1);

    /* Maximum Digits */
    HugeInteger maxDigit1{"1234567890123456789012345678901234567890"};
    HugeInteger maxDigit2{maxDigit1 + 1};
    HugeInteger maxDigit3{maxDigit2 + 1};

    /* Different numbers of digits */
    EXPECT_TRUE(maxDigit2 <= maxDigit2);
    EXPECT_TRUE(maxDigit2 <= maxDigit3);
    EXPECT_FALSE(maxDigit2 <= maxDigit1);

    EXPECT_TRUE(singleDigit1 <= multiDigit1);
    EXPECT_TRUE(multiDigit1 <= maxDigit1);

    EXPECT_FALSE(multiDigit1 <= singleDigit1);
    EXPECT_FALSE(maxDigit1 <= multiDigit1);
}

/**
 * @brief Test the greater than operator
 * 
 */
TEST(EqualityOperators, GreaterThan) {

    /* Single Digits */
    HugeInteger singleDigit1{5};
    HugeInteger singleDigit2{singleDigit1 + 1};
    HugeInteger singleDigit3{singleDigit2 + 1};

    EXPECT_FALSE(singleDigit2 > singleDigit2);
    EXPECT_FALSE(singleDigit2 > singleDigit3);
    EXPECT_TRUE(singleDigit2 > singleDigit1);

    /* Multiple Digits */
    HugeInteger multiDigit1{"123124134253456346"};
    HugeInteger multiDigit2{multiDigit1 + 1};
    HugeInteger multiDigit3{multiDigit2 + 1};

    EXPECT_FALSE(multiDigit2 > multiDigit2);
    EXPECT_FALSE(multiDigit2 > multiDigit3);
    EXPECT_TRUE(multiDigit2 > multiDigit1);

    /* Maximum Digits */
    HugeInteger maxDigit1{"1234567890123456789012345678901234567890"};
    HugeInteger maxDigit2{maxDigit1 + 1};
    HugeInteger maxDigit3{maxDigit2 + 1};

    /* Different numbers of digits */
    EXPECT_FALSE(maxDigit2 > maxDigit2);
    EXPECT_FALSE(maxDigit2 > maxDigit3);
    EXPECT_TRUE(maxDigit2 > maxDigit1);

    EXPECT_FALSE(singleDigit1 > multiDigit1);
    EXPECT_FALSE(multiDigit1 > maxDigit1);

    EXPECT_TRUE(multiDigit1 > singleDigit1);
    EXPECT_TRUE(maxDigit1 > multiDigit1);
}

/**
 * @brief Test the greater or equal to operator
 * 
 */
TEST(EqualityOperators, GreaterThanEqualTo) {

    /* Single Digits */
    HugeInteger singleDigit1{5};
    HugeInteger singleDigit2{singleDigit1 + 1};
    HugeInteger singleDigit3{singleDigit2 + 1};

    EXPECT_TRUE(singleDigit2 >= singleDigit2);
    EXPECT_FALSE(singleDigit2 >= singleDigit3);
    EXPECT_TRUE(singleDigit2 >= singleDigit1);

    /* Multiple Digits */
    HugeInteger multiDigit1{"123124134253456346"};
    HugeInteger multiDigit2{multiDigit1 + 1};
    HugeInteger multiDigit3{multiDigit2 + 1};

    EXPECT_TRUE(multiDigit2 >= multiDigit2);
    EXPECT_FALSE(multiDigit2 >= multiDigit3);
    EXPECT_TRUE(multiDigit2 >= multiDigit1);

    /* Maximum Digits */
    HugeInteger maxDigit1{"1234567890123456789012345678901234567890"};
    HugeInteger maxDigit2{maxDigit1 + 1};
    HugeInteger maxDigit3{maxDigit2 + 1};

    /* Different numbers of digits */
    EXPECT_TRUE(maxDigit2 >= maxDigit2);
    EXPECT_FALSE(maxDigit2 >= maxDigit3);
    EXPECT_TRUE(maxDigit2 >= maxDigit1);

    EXPECT_FALSE(singleDigit1 >= multiDigit1);
    EXPECT_FALSE(multiDigit1 >= maxDigit1);

    EXPECT_TRUE(multiDigit1 >= singleDigit1);
    EXPECT_TRUE(maxDigit1 >= multiDigit1);
}

/**
 * @brief Addition operator overloaded with HugeIntegers
 * 
 */
TEST(Subtraction, HugeIntegers) {

    /* single digit string */
    HugeInteger singleDigit1{5};
    HugeInteger singleDigit2{4};
    HugeInteger singleDigit3;
    HugeInteger zero;

    /* Subtract zero from a single digit integer */
    singleDigit3 = singleDigit1 - zero;
    EXPECT_EQ(singleDigit3, singleDigit1);

    /* Subtract single digit integer from itself */
    singleDigit3 = singleDigit1 - singleDigit1;
    EXPECT_EQ(singleDigit3, zero);

    /* Subtract two single digit integers without carry */
    singleDigit3 = singleDigit1 - singleDigit2;
    EXPECT_EQ(singleDigit3.str(), "1");

    HugeInteger multiDigit1{20};
    HugeInteger multiDigit2{23};
    HugeInteger multiDigit3;

    /* Subtract zero from a multi digit integer */
    multiDigit3 = multiDigit1 - zero;
    EXPECT_EQ(multiDigit3, multiDigit1);

    /* Subtract multi digit integer from itself */
    multiDigit3 = multiDigit1 - multiDigit1;
    EXPECT_EQ(multiDigit3, zero);

    /* Subtract two multi digit integers without carry */
    multiDigit3 = multiDigit2 - multiDigit1;
    EXPECT_EQ(multiDigit3.str(), "3");

    /* Subtract two multi digit integers with carry */
    HugeInteger multiDigit4{14};
    multiDigit3 = multiDigit1 - multiDigit4;
    EXPECT_EQ(multiDigit3.str(), "6");

    HugeInteger largeDigit1{"9999999999999999999999999999999999999999"};
    HugeInteger largeDigit2{"3333333333333333333333333333333333333333"};
    HugeInteger largeDigit3{"2348625987359320572309457234095728345092"};
    HugeInteger largeDigit4;

    /* Subtract zero from a max digit integer */
    largeDigit4 = largeDigit1 - zero;
    EXPECT_EQ(largeDigit4, largeDigit1);

    /* Subtract large digit from itself */
    largeDigit4 = largeDigit1 - largeDigit1;
    EXPECT_EQ(largeDigit4, zero);

    /* Subtract two multi digit integers without carry */
    largeDigit4 = largeDigit1 - largeDigit2;
    EXPECT_EQ(largeDigit4.str(), "6666666666666666666666666666666666666666");

    /* Subtract two multi digit integers with carry */
    largeDigit4 = largeDigit2 - largeDigit3;
    EXPECT_EQ(largeDigit4.str(), "984707345974012761023876099237604988241");
}

/**
 * @brief Addition operator overloaded with Integers
 * 
 */
TEST(Subtraction, Integers) {

    /* single digit string */
    HugeInteger singleDigit1{5};
    HugeInteger singleDigit2{4};
    HugeInteger singleDigit3;
    HugeInteger zero;

    /* Subtract zero from a single digit integer */
    singleDigit3 = singleDigit1 - 0;
    EXPECT_EQ(singleDigit3, singleDigit1);

    /* Subtract single digit integer from itself */
    singleDigit3 = singleDigit1 - 5;
    EXPECT_EQ(singleDigit3, zero);

    /* Subtract two single digit integers without carry */
    singleDigit3 = singleDigit1 - 4;
    EXPECT_EQ(singleDigit3.str(), "1");

    HugeInteger multiDigit1{20};
    HugeInteger multiDigit2{23};
    HugeInteger multiDigit3;

    /* Subtract zero from a multi digit integer */
    multiDigit3 = multiDigit1 - 0;
    EXPECT_EQ(multiDigit3, multiDigit1);

    /* Subtract multi digit integer from itself */
    multiDigit3 = multiDigit1 - 20;
    EXPECT_EQ(multiDigit3, zero);

    /* Subtract two multi digit integers without carry */
    multiDigit3 = multiDigit2 - 20;
    EXPECT_EQ(multiDigit3.str(), "3");

    /* Subtract two multi digit integers with carry */
    multiDigit3 = multiDigit1 - 14;
    EXPECT_EQ(multiDigit3.str(), "6");

    HugeInteger largeDigit1{"9223372036854775807"};
    HugeInteger largeDigit2{"3333333333333333333333333333333333333333"};
    HugeInteger largeDigit3{"2348625987359320572309457234095728345092"};
    HugeInteger largeDigit4;

    /* Subtract zero from a max digit integer */
    largeDigit4 = largeDigit1 - 0;
    EXPECT_EQ(largeDigit4, largeDigit1);

    /* Subtract large digit from itself */
    largeDigit4 = largeDigit1 - 0x7FFFFFFFFFFFFFFFL;
    EXPECT_EQ(largeDigit4, zero);

    /* Subtract two multi digit integers without carry */
    largeDigit4 = largeDigit1 - 8112261025743664706;
    EXPECT_EQ(largeDigit4.str(), "1111111011111111101");

    /* Subtract two multi digit integers with carry */
    largeDigit4 = largeDigit2 - 71462935742029384;
    EXPECT_EQ(largeDigit4.str(), "3333333333333333333333261870397591303949");
}

/**
 * @brief Division operator overloaded with HugeIntegers
 * 
 */
TEST(Division, HugeIntegers) {

    /* single digit string */
    HugeInteger singleDigit1{5};
    HugeInteger singleDigit2{4};
    HugeInteger one{1};
    HugeInteger zero;
    HugeInteger singleDigit3;

    /* Divide single digit HugeInteger by identity */
    singleDigit3 = singleDigit1 / one;
    EXPECT_EQ(singleDigit3, singleDigit1);

    /* Divide single digit HugeInteger by zero */
    try {
        singleDigit3 = singleDigit1 / zero;
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "cannot divide by zero");
    }

    /* Divide single digit by larger single digit */
    singleDigit3 = singleDigit2 / singleDigit1;
    EXPECT_EQ(singleDigit3, zero);

    HugeInteger doubleDigit1{23};
    HugeInteger doubleDigit2 = doubleDigit1 * 2;

    /* Divide double digit HugeInteger by zero */
    try {
        doubleDigit2 = doubleDigit1 / zero;
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "cannot divide by zero");
    }

    /* Inverse property with HugeInteger */
    HugeInteger doubleDigit3 = doubleDigit2 / doubleDigit1;
    EXPECT_EQ(doubleDigit3, HugeInteger(2));

    /* Divide double digit HugeInteger by itself */
    doubleDigit2 = doubleDigit1 / doubleDigit1;
    EXPECT_EQ(doubleDigit2, one);

    /* Divide double digit HugeInteger by identity */
    doubleDigit2 = doubleDigit1 / one;
    EXPECT_EQ(doubleDigit2, doubleDigit1);

    /* Double digit with remainder */
    doubleDigit3 = doubleDigit1 - 1;
    EXPECT_EQ(doubleDigit1 / doubleDigit3, HugeInteger(1));

    /* Divide double digit by smaller double digit */
    doubleDigit3 = doubleDigit1 + 1;
    EXPECT_EQ(doubleDigit1 / doubleDigit3, zero);

    /* Divide single digit by double digit */
    EXPECT_EQ(singleDigit1 / doubleDigit1, zero);

    /* Divide double digit by single digit, no remainder */
    singleDigit1 = 5;
    doubleDigit1 = 25;
    EXPECT_EQ(doubleDigit1 / singleDigit1, 5);

    /* Divide double digit by single digit, with remainder */
    singleDigit1 = 6;
    EXPECT_EQ(doubleDigit1 / singleDigit1, 4);

    /* Divide two random huge integers */
    HugeInteger multiDigit2{"234235324534747345345"};
    HugeInteger multiDigit3{"334534634664645756869856"};
    EXPECT_EQ(multiDigit2 / multiDigit3, zero);
    EXPECT_EQ(multiDigit3 / multiDigit2, HugeInteger(1428));

    multiDigit3 = HugeInteger("345364567457334534634664645756869856");
    EXPECT_EQ(multiDigit3 / multiDigit2, HugeInteger("1474434174876564"));

    /* Divide max HugeInteger */
    multiDigit2 = HugeInteger("9999999999999999999999999999999999999999");
    EXPECT_EQ(multiDigit2 / HugeInteger(3), HugeInteger("3333333333333333333333333333333333333333"));
}