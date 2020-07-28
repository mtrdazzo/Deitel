/**
 * @file tst_Ex_13_7.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-07-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <gtest/gtest.h>
#include <Ex_13_7.h>
#include <fstream>

class NumberClass : public ::testing::Test {

    protected:

        void SetUp(const std::string & input) {

            /* open file, write to file */
            outFile.open(fileName);
            outFile << input;
            outFile.close();

            /* open file, write to Number object */
            inFile.open(fileName);
            inFile >> testNum;
        }

        void TearDown() {
            inFile.close();
            std::remove(fileName);
        }

        const char *fileName{"tempFile.txt"};
        std::ofstream outFile;
        std::ifstream inFile;
        std::string tempStr;
        Number testNum;
};

/**
 * @brief Test hex representations
 * 
 */
TEST_F(NumberClass, HexValues) {

    SetUp("0xFF");
    EXPECT_EQ(testNum.getValue(), 255);
    inFile.close();

    SetUp("0xfe");
    EXPECT_EQ(testNum.getValue(), 254);
    inFile.close();

    SetUp("0xfD");
    EXPECT_EQ(testNum.getValue(), 253);
    inFile.close();

    SetUp("0X00");
    EXPECT_EQ(testNum.getValue(), 0);
    inFile.close();

    SetUp("0x01");
    EXPECT_EQ(testNum.getValue(), 1);
    inFile.close();

    SetUp("0X1");
    EXPECT_EQ(testNum.getValue(), 1);
    inFile.close();

    SetUp("0xabcdef");
    EXPECT_EQ(testNum.getValue(), 11259375);
    inFile.close();

    SetUp("0X00000001");
    EXPECT_EQ(testNum.getValue(), 1);
    inFile.close();

    SetUp("0xffffffff");
    EXPECT_EQ(static_cast<uint32_t>(testNum.getValue()), 4294967295u);
    inFile.close();

    try {
        SetUp("0g0g");
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid input for number representation");
    }
    inFile.close();

    try {
        SetUp("0x0g");
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid hex character");
    }
    inFile.close();

    try {
        SetUp("0xg0");
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid hex character");
    }
    inFile.close();

    try {
        SetUp("0x01234567g");
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "hex string too long, max value is 0xFFFFFFFF");
    }
}

/**
 * @brief Test decimal representations
 * 
 */
TEST_F(NumberClass, DecimalValues) {

    try {
        SetUp("-100");
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid decimal character");
    }

    SetUp("0");
    EXPECT_EQ(testNum.getValue(), 0);
    inFile.close();

    SetUp("10");
    EXPECT_EQ(testNum.getValue(), 10);
    inFile.close();

    SetUp("100");
    EXPECT_EQ(testNum.getValue(), 100);
    inFile.close();

    SetUp("4294967295");
    EXPECT_EQ(static_cast<uint32_t>(testNum.getValue()), 4294967295u);
    inFile.close();

    try {
        SetUp("429496729e");
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid decimal character");
    }
    inFile.close();

    try {
        SetUp("4e94967295");
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid decimal character");
    }
    inFile.close();

    try {
        SetUp("4294g67295");
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid decimal character");
    }

    try {
        SetUp("42941672951");
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "decimal string too long, max value is 4294967295");
    }

    try {
        SetUp("4294167296");
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "decimal too large, max value is 4294967295");
    }
}

/**
 * @brief Test octal representations
 * 
 */
TEST_F(NumberClass, OctalValues) {

    SetUp("01");
    EXPECT_EQ(testNum.getValue(), 1);
    inFile.close();

    SetUp("00");
    EXPECT_EQ(testNum.getValue(), 0);
    inFile.close();

    SetUp("0000000000");
    EXPECT_EQ(testNum.getValue(), 0);
    inFile.close();

    SetUp("0000000001");
    EXPECT_EQ(testNum.getValue(), 1);
    inFile.close();

    SetUp("011");
    EXPECT_EQ(testNum.getValue(), 9);
    inFile.close();

    SetUp("0377777777");
    EXPECT_EQ(static_cast<uint32_t>(testNum.getValue()), 67108863u);
    inFile.close();

    try {
        SetUp("018");
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid octal character");
    }
    inFile.close();

    try {
        SetUp("0377787777");
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid octal character");
    }
    inFile.close();

    try {
        SetUp("0200F00001");
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid octal character");
    }
    inFile.close();

    try {
        SetUp("037777777F");
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid octal character");
    }
    inFile.close();

    try {
        SetUp("0b377");
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid input for number representation");
    }
    inFile.close();

    try {
        SetUp("000000000h");
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid octal character");
    }
    inFile.close();

    /* too long of a string */
    try {
        SetUp("03777777771");
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "decimal string too long, max value is 0377777777");
    }
    inFile.close();

    /* too big a value for 32-bit integer */
    try {
        SetUp("0477777777");
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "integer overflow, max value is 0377777777");
    }
}
