/**
 * @file tst_Ex_22_16.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Test CommandLineArgsToDouble
 * @version 0.1
 * @date 2020-12-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <gtest/gtest.h>
#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <fstream>
#include <string>

#include "Ex_22_16.h"


class TestCommandLineArgsToFloat : public testing::Test {

    protected:

        /**
         * @brief Write the command line args the temp file
         * 
         * @param args 
         */
        void WriteCommandLineArgs(std::string args) {

            if (in.is_open())
                in.close();
            
            out.open(fileName, std::ios::out);
            out << args;
            out.close();

            in.open(fileName, std::ios::in);
            std::cin.rdbuf(in.rdbuf());
        }

        /**
         * @brief Set random seed
         * 
         */
        void SetUp() {
            srand(static_cast<size_t>(time(nullptr)));
        }

        /**
         * @brief Remove tmp file and close streams
         * 
         */
        void TearDown() {
            out.close();
            in.close();
            remove(fileName);
        }

        /**
         * @brief Get the Random floating-point int
         * 
         * @return double Random floating-point int
         */
        double GetRandomFloat(void) {
            return static_cast<double>(rand()) / static_cast<double>(RAND_MAX / maxFloatValue) + minFloatValue;
        }

        double randFloat;
        const double maxFloatValue{45.0};
        const double minFloatValue{-45.0};
        const double sumTolerance{0.001};
        const size_t numIterations{100};
        std::ofstream out; // output stream
        std::ifstream in;  // input stream
        const char * fileName{"file.tmp"}; // temporary file name

};



/**
 * @brief Write a zero floats as command line arguments
 * 
 */
TEST_F(TestCommandLineArgsToFloat, ZeroIntegers) {

    WriteCommandLineArgs(std::string{""});
    EXPECT_EQ(CommandLineArgsToDouble(), 0);
}

/**
 * @brief Write a single float as a command line argument
 * 
 */
TEST_F(TestCommandLineArgsToFloat, SingleFloat) {
    for (size_t i{0}; i < numIterations; ++i) {
        randFloat = GetRandomFloat();
        WriteCommandLineArgs(std::to_string(randFloat));
        EXPECT_NEAR(CommandLineArgsToDouble(), randFloat, sumTolerance);
    }
}

/**
 * @brief Write a random number of floats (2 - 4) as command line arguments
 * 
 */
TEST_F(TestCommandLineArgsToFloat, MultipleFloats) {
    size_t randNumInts;
    std::string randomString;
    double sum;

    for (size_t i{0}; i < numIterations; ++i) {
        sum = 0;
        randNumInts = rand() % 3 + 2;
        for (size_t num{0}; num < randNumInts; ++num) {
            // try not to overflow sum
            randFloat = GetRandomFloat() / randNumInts; 
            sum += randFloat;
            randomString += std::to_string(randFloat);

            if (num + 1 < randNumInts)
                randomString += ' ';
        }
        WriteCommandLineArgs(randomString);
        EXPECT_NEAR(CommandLineArgsToDouble(), sum, sumTolerance);
        randomString.erase();
    }
}

/**
 * @brief Write an invalid command-line entry
 * 
 */
TEST_F(TestCommandLineArgsToFloat, InvalidEntries) {
    WriteCommandLineArgs(std::string{"some random strings"});
    EXPECT_EQ(CommandLineArgsToDouble(), 0.0);
}

/**
 * @brief Write float too large
 * 
 */
TEST_F(TestCommandLineArgsToFloat, IntegerTooLarge) {
    std::string floatTooLarge{std::to_string(DBL_MAX)};
    floatTooLarge += '0';
    WriteCommandLineArgs(floatTooLarge);
    // undefined behavior
    EXPECT_NO_FATAL_FAILURE(CommandLineArgsToDouble());}

/**
 * @brief Write float too large
 * 
 */
TEST_F(TestCommandLineArgsToFloat, FloatTooSmall) {
    std::string floatTooSmall{std::to_string(DBL_MIN)};
    floatTooSmall += '0';
    WriteCommandLineArgs(floatTooSmall);
    // undefined behavior
    EXPECT_NO_FATAL_FAILURE(CommandLineArgsToDouble());
}

/**
 * @brief Write some invalid command-line entries
 * 
 */
TEST_F(TestCommandLineArgsToFloat, InvalidEntriesMixed) {
    std::string randomStr;
    double otherRandFloat;
    for (size_t i{0}; i < numIterations; ++i) {
        randFloat = GetRandomFloat();
        randomStr += std::to_string(randFloat);
        randomStr += " ";
        randomStr += std::string{"invalid strings"};
        randomStr += " ";
        otherRandFloat = GetRandomFloat();
        randomStr += std::to_string(otherRandFloat);
        WriteCommandLineArgs(randomStr);
        EXPECT_NEAR(CommandLineArgsToDouble(), randFloat + otherRandFloat, sumTolerance);

        randomStr.erase();
    }
}
