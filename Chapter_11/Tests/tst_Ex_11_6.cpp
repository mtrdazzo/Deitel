/**
 * @file tst_Ex_11_6.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Testing Inheritance heirarchy for students at a university definitions
 * @version 0.1
 * @date 2020-07-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <gtest/gtest.h>
#include <Ex_11_6.h>

TEST(UndergraduateStudent, AllMethods) {

    UndergraduateStudent student1{"Jon", "Doe", 24, 8, 1988};
    EXPECT_EQ(student1.getFirstName(), "Jon");
    EXPECT_EQ(student1.getLastName(), "Doe");
    EXPECT_EQ(student1.getDOB(), "August 24, 1988");
    EXPECT_NE(student1.getID(), "");

    /* Invalid first name */
    try {
        UndergraduateStudent student{"", "Doe", 24, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid first name");
    }

    /* Invalid last name */
    try {
        UndergraduateStudent student{"Jon", "", 24, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid last name");
    }

    /* Invalid day */
    try {
        UndergraduateStudent student{"Jon", "Doe", 0, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "day must be a positive integer");
    }
    /* Invalid day of even month */
    try {
        UndergraduateStudent student{"Jon", "Doe", 32, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }
    /* Invalid day of odd month */
    try {
        UndergraduateStudent student{"Jon", "Doe", 31, 9, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }
    /* Invalid day of non-leap year */
    try {
        UndergraduateStudent student{"Jon", "Doe", 29, 2, 2001};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }

    /* valid day for leap year */
    UndergraduateStudent student{"Jon", "Doe", 29, 2, 2000};
}