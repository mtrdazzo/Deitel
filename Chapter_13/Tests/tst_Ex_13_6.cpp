/**
 * @file tst_Ex_13_6.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Exercises with formatted input/output streams
 * @version 0.1
 * @date 2020-07-19
 * 
 * Exercise 13-6 Write C++ Statements
 * 
 * a) Print integer 40000 left justified in a 15-digit field
 * 
 * b) Read a string into character array variable state.
 * 
 * c) Print 200 with and without a sign.
 * 
 * d) Print the decimal value 80 in octal form proceeded by 0.
 * 
 * e) Read characters into array charArray until the character 'p' is encountered, up to a limit
 *    of 10 characters (including the terminating null character). Extract the delimiter from the
 *    input stream, and discard it.
 * 
 * f) Print 1.234 in a 9-digit field with preceding zeros.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <gtest/gtest.h>
#include <sstream>

#define BUF_SIZE 100

class StreamFormatting : public ::testing::Test {

    /**
     * @brief Clear the stream
     * 
     */
    void SetUp() {
        output.str("");
        output.clear();
    }

    protected:
        std::ostringstream output;
};

/**
 * @brief Print integer 40000 left justified in a 15-digit field
 * 
 */
TEST_F(StreamFormatting, 40000LeftJustified) {

    output << std::left << std::setw(15) << std::setfill('#')
        << 40000;

    EXPECT_EQ(output.str(), "40000##########");
}

/**
 * @brief Read a string into character array variable state
 * 
 */
TEST_F(StreamFormatting, ReadString) {
    // char state[BUF_SIZE];
    // std::cin.getline(state, BUF_SIZE);
    // std::cout << state << std::endl;
}

/**
 * @brief Print 200 with and without a sign
 * 
 */
TEST_F(StreamFormatting, 200WithWithoutSign) {

    int value{200};
    output << "Without sign: " << value << "\n";
    output << "With sign: " << std::showpos << value;

    EXPECT_EQ(output.str(), "Without sign: 200\nWith sign: +200");
}

/**
 * @brief Print the decimal value 80 in octal form proceeded by 0
 * 
 */
TEST_F(StreamFormatting, 80Octal) {

    int value{80};
    output << std::showbase << std::oct << value;
    output << std::dec;
    output << std::noshowbase;

    EXPECT_EQ(output.str(), "0120");
}

/**
 * @brief Read characters into array charArray until the character 'p' is encountered
 * 
 */
TEST_F(StreamFormatting, readUntilP) {

    // const int charArraySize{10};
    // char charArray[charArraySize];
    // std::cin.getline(charArray, charArraySize, 'p');
    // std::cout << "charArray: " << charArray;
}

/**
 * @brief Print 1.234 in a 9-digit field with preceding zeros.
 * 
 */
TEST_F(StreamFormatting, 1234_9DigitField) {

    float number{1.234};
    output << std::setw(9) << std::setfill('0') << number;

    EXPECT_EQ(output.str(), "00001.234");
}