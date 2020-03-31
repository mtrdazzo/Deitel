#include <Ex_9_14.h>
#include <gtest/gtest.h>

TEST(Constructor, singleDigit) {

    std::string singleDigit{"1"};
    HugeInteger smallInt{singleDigit};
    EXPECT_EQ(smallInt.output(), singleDigit);
}

TEST(Constructor, multipleDigits) {

    std::string randomDigits{"12342423"};
    HugeInteger smallInt{randomDigits};
    EXPECT_EQ(smallInt.output(), randomDigits);
}

TEST(Constructor, overrideDigits) {

    std::string firstDigits{"1234567890123456789012345678901234567890"};
    std::string secondDigits{"4567"};
    HugeInteger smallInt{firstDigits};
    EXPECT_EQ(smallInt.output(), firstDigits);

    smallInt.input(secondDigits);
    EXPECT_EQ(smallInt.output(), secondDigits);
}

TEST(Constructor, maxDigits) {

    std::string maxIntStr{"1234567890123456789012345678901234567890"};
    HugeInteger smallInt{maxIntStr};
    EXPECT_EQ(smallInt.output(), maxIntStr);
}

TEST(Constructor, noDigits) {

    std::string maxIntStr{""};
    try {
        HugeInteger smallInt{maxIntStr};
    } catch ( std::invalid_argument const & err) {
        EXPECT_STRCASEEQ(err.what(), "ERROR: invalid number of digits");
    }
}

TEST(Constructor, overMaxDigits) {

    std::string maxIntStr{"12345678901234567890123456789012345678901"};
    try {
        HugeInteger smallInt{maxIntStr};
    } catch ( std::invalid_argument const & err) {
        EXPECT_STRCASEEQ(err.what(), "ERROR: invalid number of digits");
    }
}

TEST(Constructor, invalidDigit) {

    std::string maxIntStr{"12345678901234567A9012345678901234567890"};
    try {
        HugeInteger smallInt{maxIntStr};
    } catch ( std::invalid_argument const & err) {
        EXPECT_STRCASEEQ(err.what(), "ERROR: not a valid string of digits");
    }
}

TEST(LessThan, smallerLength) {

    std::string longerStr{"1234"};
    std::string shorterStr{"123"};

    HugeInteger shorter{shorterStr};
    HugeInteger longer{longerStr};

    EXPECT_TRUE(shorter.isLessThan(longer));
}

TEST(LessThan, largerLength) {

    std::string longerStr{"1234"};
    std::string shorterStr{"123"};

    HugeInteger shorter{shorterStr};
    HugeInteger longer{longerStr};

    EXPECT_FALSE(longer.isLessThan(shorter));
}

TEST(LessThan, equalValues) {

    std::string longerStr{"1234"};
    std::string shorterStr{"1234"};

    HugeInteger shorter{shorterStr};
    HugeInteger longer{longerStr};

    EXPECT_FALSE(longer.isLessThan(shorter));
}

TEST(LessThan, lessValueEqualLength) {

    std::string value1{"1234"};
    std::string value2{"1235"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_TRUE(int1.isLessThan(int2));
}

TEST(LessThan, greaterValueEqualLength) {

    std::string value1{"1234"};
    std::string value2{"1435"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_FALSE(int2.isLessThan(int1));
}

TEST(LessThan, singleIntegersFalse) {

    std::string value1{"1"};
    std::string value2{"2"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_FALSE(int2.isLessThan(int1));
}

TEST(LessThan, singleIntegersEqual) {

    std::string value1{"1"};
    std::string value2{"1"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_FALSE(int2.isLessThan(int1));
}

TEST(LessThan, singleIntegersTrue) {

    std::string value1{"3"};
    std::string value2{"2"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_TRUE(int2.isLessThan(int1));
}

TEST(LessThan, maxIntegersFalse) {

    std::string value1{"1234567890123456789012345678901234567880"};
    std::string value2{"1234567890123456789012345678901234567890"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_FALSE(int2.isLessThan(int1));
}

TEST(LessThan, maxIntegersEqual) {

    std::string value1{"1234567890123456789012345678901234567890"};
    std::string value2{"1234567890123456789012345678901234567890"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_FALSE(int2.isLessThan(int1));
}

TEST(LessThan, maxIntegersTrue) {

    std::string value1{"1234567890123456789012345678901234567890"};
    std::string value2{"1234567890123456789012345678901234567880"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_TRUE(int2.isLessThan(int1));
}

/*************************************************/

TEST(LessThanEqualTo, smallerLength) {

    std::string longerStr{"1234"};
    std::string shorterStr{"123"};

    HugeInteger shorter{shorterStr};
    HugeInteger longer{longerStr};

    EXPECT_TRUE(shorter.isLessThanOrEqualTo(longer));
}

TEST(LessThanEqualTo, largerLength) {

    std::string longerStr{"1234"};
    std::string shorterStr{"123"};

    HugeInteger shorter{shorterStr};
    HugeInteger longer{longerStr};

    EXPECT_FALSE(longer.isLessThanOrEqualTo(shorter));
}

TEST(LessThanEqualTo, equalValues) {

    std::string longerStr{"1234"};
    std::string shorterStr{"1234"};

    HugeInteger shorter{shorterStr};
    HugeInteger longer{longerStr};

    EXPECT_TRUE(longer.isLessThanOrEqualTo(shorter));
}

TEST(LessThanEqualTo, lessValueEqualLength) {

    std::string value1{"1234"};
    std::string value2{"1235"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_TRUE(int1.isLessThanOrEqualTo(int2));
}

TEST(LessThanEqualTo, greaterValueEqualLength) {

    std::string value1{"1234"};
    std::string value2{"1435"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_FALSE(int2.isLessThanOrEqualTo(int1));
}

TEST(LessThanEqualTo, singleIntegersFalse) {

    std::string value1{"1"};
    std::string value2{"2"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_FALSE(int2.isLessThanOrEqualTo(int1));
}

TEST(LessThanEqualTo, singleIntegersEqual) {

    std::string value1{"1"};
    std::string value2{"1"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_TRUE(int2.isLessThanOrEqualTo(int1));
}

TEST(LessThanEqualTo, singleIntegersTrue) {

    std::string value1{"3"};
    std::string value2{"2"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_TRUE(int2.isLessThanOrEqualTo(int1));
}

TEST(LessThanEqualTo, maxIntegersFalse) {

    std::string value1{"1234567890123456789012345678901234567880"};
    std::string value2{"1234567890123456789012345678901234567890"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_FALSE(int2.isLessThanOrEqualTo(int1));
}

TEST(LessThanEqualTo, maxIntegersEqual) {

    std::string value1{"1234567890123456789012345678901234567890"};
    std::string value2{"1234567890123456789012345678901234567890"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_TRUE(int2.isLessThanOrEqualTo(int1));
}

TEST(LessThanEqualTo, maxIntegersTrue) {

    std::string value1{"1234567890123456789012345678901234567890"};
    std::string value2{"1234567890123456789012345678901234567880"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_TRUE(int2.isLessThanOrEqualTo(int1));
}

/**********************************************/

TEST(GreaterThan, smallerLength) {

    std::string longerStr{"1234"};
    std::string shorterStr{"123"};

    HugeInteger shorter{shorterStr};
    HugeInteger longer{longerStr};

    EXPECT_FALSE(shorter.isGreaterThan(longer));
}

TEST(GreaterThan, largerLength) {

    std::string longerStr{"1234"};
    std::string shorterStr{"123"};

    HugeInteger shorter{shorterStr};
    HugeInteger longer{longerStr};

    EXPECT_TRUE(longer.isGreaterThan(shorter));
}

TEST(GreaterThan, equalValues) {

    std::string longerStr{"1234"};
    std::string shorterStr{"1234"};

    HugeInteger shorter{shorterStr};
    HugeInteger longer{longerStr};

    EXPECT_FALSE(longer.isGreaterThan(shorter));
}

TEST(GreaterThan, lessValueEqualLength) {

    std::string value1{"1234"};
    std::string value2{"1235"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_FALSE(int1.isGreaterThan(int2));
}

TEST(GreaterThan, greaterValueEqualLength) {

    std::string value1{"1234"};
    std::string value2{"1435"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_TRUE(int2.isGreaterThan(int1));
}

TEST(GreaterThan, singleIntegersFalse) {

    std::string value1{"1"};
    std::string value2{"2"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_TRUE(int2.isGreaterThan(int1));
}

TEST(GreaterThan, singleIntegersEqual) {

    std::string value1{"1"};
    std::string value2{"1"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_FALSE(int2.isGreaterThan(int1));
}

TEST(GreaterThan, singleIntegersTrue) {

    std::string value1{"3"};
    std::string value2{"2"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_FALSE(int2.isGreaterThan(int1));
}

TEST(GreaterThan, maxIntegersTrue) {

    std::string value1{"1234567890123456789012345678901234567880"};
    std::string value2{"1234567890123456789012345678901234567890"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_TRUE(int2.isGreaterThan(int1));
}

TEST(GreaterThan, maxIntegersEqual) {

    std::string value1{"1234567890123456789012345678901234567890"};
    std::string value2{"1234567890123456789012345678901234567890"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_FALSE(int2.isGreaterThan(int1));
}

TEST(GreaterThan, maxIntegersFalse) {

    std::string value1{"1234567890123456789012345678901234567890"};
    std::string value2{"1234567890123456789012345678901234567880"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_FALSE(int2.isGreaterThan(int1));
}

/********************************************************/


TEST(GreaterThanEqualTo, smallerLength) {

    std::string longerStr{"1234"};
    std::string shorterStr{"123"};

    HugeInteger shorter{shorterStr};
    HugeInteger longer{longerStr};

    EXPECT_FALSE(shorter.isGreaterThanOrEqualTo(longer));
}

TEST(GreaterThanEqualTo, largerLength) {

    std::string longerStr{"1234"};
    std::string shorterStr{"123"};

    HugeInteger shorter{shorterStr};
    HugeInteger longer{longerStr};

    EXPECT_TRUE(longer.isGreaterThanOrEqualTo(shorter));
}

TEST(GreaterThanEqualTo, equalValues) {

    std::string longerStr{"1234"};
    std::string shorterStr{"1234"};

    HugeInteger shorter{shorterStr};
    HugeInteger longer{longerStr};

    EXPECT_TRUE(longer.isGreaterThanOrEqualTo(shorter));
}

TEST(GreaterThanEqualTo, lessValueEqualLength) {

    std::string value1{"1234"};
    std::string value2{"1235"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_FALSE(int1.isGreaterThanOrEqualTo(int2));
}

TEST(GreaterThanEqualTo, greaterValueEqualLength) {

    std::string value1{"1234"};
    std::string value2{"1435"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_TRUE(int2.isGreaterThanOrEqualTo(int1));
}

TEST(GreaterThanEqualTo, singleIntegersFalse) {

    std::string value1{"1"};
    std::string value2{"2"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_TRUE(int2.isGreaterThanOrEqualTo(int1));
}

TEST(GreaterThanEqualTo, singleIntegersEqual) {

    std::string value1{"1"};
    std::string value2{"1"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_TRUE(int2.isGreaterThanOrEqualTo(int1));
}

TEST(GreaterThanEqualTo, singleIntegersTrue) {

    std::string value1{"3"};
    std::string value2{"2"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_FALSE(int2.isGreaterThanOrEqualTo(int1));
}

TEST(GreaterThanEqualTo, maxIntegersFalse) {

    std::string value1{"1234567890123456789012345678901234567880"};
    std::string value2{"1234567890123456789012345678901234567890"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_TRUE(int2.isGreaterThanOrEqualTo(int1));
}

TEST(GreaterThanEqualTo, maxIntegersEqual) {

    std::string value1{"1234567890123456789012345678901234567890"};
    std::string value2{"1234567890123456789012345678901234567890"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_TRUE(int2.isGreaterThanOrEqualTo(int1));
}

TEST(GreaterThanEqualTo, maxIntegersTrue) {

    std::string value1{"1234567890123456789012345678901234567890"};
    std::string value2{"1234567890123456789012345678901234567880"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};

    EXPECT_FALSE(int2.isGreaterThanOrEqualTo(int1));
}

TEST(IsZero, nonZeroAndZero) {

    std::string value1{"1"};
    std::string value2{"0"};
    std::string value3{"0000"};
    std::string value4{"0002"};

    HugeInteger int1{value1};
    HugeInteger int2{value2};
    HugeInteger int3{value3};
    HugeInteger int4{value4};

    EXPECT_FALSE(int1.isZero());
    EXPECT_TRUE(int2.isZero());
    EXPECT_TRUE(int3.isZero());
    EXPECT_FALSE(int4.isZero());
}

TEST(Mulitply, zeroSingleDigitProduct) {

    HugeInteger int1{"1"};
    HugeInteger int2{"0"};

    int1.multiply(int2);

    EXPECT_TRUE(int1.isZero());
}

TEST(Mulitply, zeroDoubleDigitProduct) {

    HugeInteger int1{"25"};
    HugeInteger int2{"0"};

    int1.multiply(int2);

    EXPECT_TRUE(int1.isZero());
}

TEST(Mulitply, zeroSingleDigitProductOpposite) {

    HugeInteger int1{"0"};
    HugeInteger int2{"1"};

    int1.multiply(int2);

    EXPECT_TRUE(int1.isZero());
}

TEST(Mulitply, zeroDoubleDigitProductOpposite) {

    HugeInteger int1{"0"};
    HugeInteger int2{"25"};

    int1.multiply(int2);

    EXPECT_TRUE(int1.isZero());
}

TEST(Mulitply, zeroMaxDigitProduct) {

    HugeInteger int1{"1234567890123456789012345678901234567880"};
    HugeInteger int2{"0"};

    int1.multiply(int2);

    EXPECT_TRUE(int1.isZero());
}

TEST(Mulitply, singleDigitProduct) {

    HugeInteger int1{"1"};
    HugeInteger int2{"4"};

    int1.multiply(int2);

    EXPECT_EQ(int1.output(), "4");
}

TEST(Mulitply, singleDigitMaxProduct) {

    HugeInteger int1{"1234567890123456789012345678901234567880"};
    HugeInteger int2{"1"};

    int1.multiply(int2);

    EXPECT_EQ(int1.output(), "1234567890123456789012345678901234567880");
}

TEST(Mulitply, doubleDigitProduct) {

    HugeInteger int1{"6"};
    HugeInteger int2{"4"};

    int1.multiply(int2);

    EXPECT_EQ(int1.output(), "24");
}

TEST(Mulitply, doubleDoubleDigitProduct) {

    HugeInteger int1{"12"};
    HugeInteger int2{"12"};

    int1.multiply(int2);

    EXPECT_EQ(int1.output(), "144");
}

TEST(Multiply, randomSquareProduct) {

    HugeInteger int1{"523452346"};
    HugeInteger int2{"345345"};

    int1.multiply(int2);

    EXPECT_EQ(int1.output(), "180771650429370");
}

TEST(Mulitply, maxDigitProductRollover) {

    HugeInteger int1{"2695780820544754983753410191747515940864"};
    HugeInteger int2{"4"};

    int1.multiply(int2);

    EXPECT_EQ(int1.output(), "783123282179019935013640766990063763457");
    EXPECT_EQ(int1.getNumDigits(), static_cast<unsigned int>(39));
}

TEST(Mulitply, maxDigitProductNoRollover) {

    std::string intstr_op1{"3"};
    std::string intstr_op2{"2695780820544754983753410191747515940864"};
    std::string intstr_product{"8087342461634264951260230575242547822592"};

    HugeInteger int_op1{intstr_op1};
    HugeInteger int_op2{intstr_op2};

    int_op1.multiply(int_op2);

    EXPECT_EQ(int_op1.output(), intstr_product);
    EXPECT_EQ(int_op1.getNumDigits(), intstr_product.length());
}