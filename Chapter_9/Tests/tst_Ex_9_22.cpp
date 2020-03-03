/**
 * @file tst_Ex_9_22.cpp
 *
 * @brief Test the functionality of the Time class to represent the time as the number
 *        of seconds after midnight.
 *
 * @author Matt Randazzo
 */

#include <Ex_9_22.h>
#include <gtest/gtest.h>

/**
 * @brief Set zero seconds since midnight
 */
TEST(Constructor, ZeroSeconds) {

    Time time_zero;

    EXPECT_EQ(time_zero.getHour(), static_cast<unsigned int>(0));
    EXPECT_EQ(time_zero.getMinute(), static_cast<unsigned int>(0));
    EXPECT_EQ(time_zero.getSecond(), static_cast<unsigned int>(0));
    EXPECT_EQ(time_zero.toStandardString(), "12:00:00 AM");
    EXPECT_EQ(time_zero.toUniversalString(), "00:00:00");
}

/**
 * @brief Set valid time before noon
 */
TEST(Constructor, SetValidTimeBeforeNoon) {
    Time sample_time(6, 30, 30);

    EXPECT_EQ(sample_time.getHour(), static_cast<unsigned int>(6));
    EXPECT_EQ(sample_time.getMinute(), static_cast<unsigned int>(30));
    EXPECT_EQ(sample_time.getSecond(), static_cast<unsigned int>(30));
    EXPECT_EQ(sample_time.toStandardString(), "06:30:30 AM");
    EXPECT_EQ(sample_time.toUniversalString(), "06:30:30");
}

/**
 * @brief Set maximum valid time after noon
 */
TEST(Constructor, SetValidTimeAfterNoon) {
    Time sample_time(23, 59, 59);

    EXPECT_EQ(sample_time.getHour(), static_cast<unsigned int>(23));
    EXPECT_EQ(sample_time.getMinute(), static_cast<unsigned int>(59));
    EXPECT_EQ(sample_time.getSecond(), static_cast<unsigned int>(59));
    EXPECT_EQ(sample_time.toStandardString(), "11:59:59 PM");
    EXPECT_EQ(sample_time.toUniversalString(), "23:59:59");
}

/**
 * @brief Set invalid hour
 */
TEST(SetHour, SetInvalidHour) {
    
    try {
        Time sample_time(24, 30, 30);
    } catch (std::invalid_argument const &err) {
        EXPECT_STRCASEEQ(err.what(), "hour must be 0-23");
    } 
}

/**
 * @brief Set invalid minute parameter
 */
TEST(SetMinute, SetInvalidMinute) {
    
    try {
        Time sample_time(23, 60, 30);
    } catch (std::invalid_argument const &err) {
        EXPECT_STRCASEEQ(err.what(), "minute must be 0-59");
    } 
}

/**
 * @brief Set invalid second parameter
 */
TEST(SetSecond, SetInvalidSecond) {
    
    try {
        Time sample_time(23, 59, 60);
    } catch (std::invalid_argument const &err) {
        EXPECT_STRCASEEQ(err.what(), "second must be 0-59");
    } 
}
