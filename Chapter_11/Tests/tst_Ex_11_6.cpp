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

/**
 * @brief Test all Undergraduate class methods
 * 
 */
TEST(UndergraduateStudent, AllMethods) {

    Student student_orig{"Jon", "Doe", 24, 8, 1988};
    std::string expected = "Jon Doe";
    expected += "\nAugust 24, 1988";
    EXPECT_EQ(student_orig.toString(), expected);

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
    expected = "Jon Doe";
    expected += "\nFebruary 29, 2000";
    expected += "\nUser ID: " + student.getID();
    EXPECT_EQ(student.toString(), expected);

    /* Invalid day of leap year */
    try {
        UndergraduateStudent student{"Jon", "Doe", 30, 2, 2000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }

    /* Invalid month */
    try {
        UndergraduateStudent student{"Jon", "Doe", 28, 0, 2000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid month");
    }
    /* Invalid month */
    try {
        UndergraduateStudent student{"Jon", "Doe", 28, 13, 2000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid month");
    }

    /* Invalid year */
    try {
        UndergraduateStudent student{"Jon", "Doe", 28, 10, 0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid year");
    }
}

/**
 * @brief Test all Graduate Student class methods
 * 
 */
TEST(GraduateStudent, AllMethods) {

    Student student_orig{"Jon", "Doe", 24, 8, 1988};
    std::string expected = "Jon Doe";
    expected += "\nAugust 24, 1988";
    EXPECT_EQ(student_orig.toString(), expected);

    GraduateStudent student1{"Jon", "Doe", 24, 8, 1988};
    EXPECT_EQ(student1.getFirstName(), "Jon");
    EXPECT_EQ(student1.getLastName(), "Doe");
    EXPECT_EQ(student1.getDOB(), "August 24, 1988");
    EXPECT_NE(student1.getID(), "");

    /* Invalid first name */
    try {
        GraduateStudent student{"", "Doe", 24, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid first name");
    }

    /* Invalid last name */
    try {
        GraduateStudent student{"Jon", "", 24, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid last name");
    }

    /* Invalid day */
    try {
        GraduateStudent student{"Jon", "Doe", 0, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "day must be a positive integer");
    }
    /* Invalid day of even month */
    try {
        GraduateStudent student{"Jon", "Doe", 32, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }
    /* Invalid day of odd month */
    try {
        GraduateStudent student{"Jon", "Doe", 31, 9, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }
    /* Invalid day of non-leap year */
    try {
        GraduateStudent student{"Jon", "Doe", 29, 2, 2001};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }

    /* valid day for leap year */
    GraduateStudent student{"Jon", "Doe", 29, 2, 2000};
    expected = "Jon Doe";
    expected += "\nFebruary 29, 2000";
    expected += "\nUser ID: " + student.getID();
    EXPECT_EQ(student.toString(), expected);

    /* Invalid day of leap year */
    try {
        GraduateStudent student{"Jon", "Doe", 30, 2, 2000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }

    /* Invalid month */
    try {
        GraduateStudent student{"Jon", "Doe", 28, 0, 2000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid month");
    }
    /* Invalid month */
    try {
        GraduateStudent student{"Jon", "Doe", 28, 13, 2000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid month");
    }

    /* Invalid year */
    try {
        GraduateStudent student{"Jon", "Doe", 28, 10, 0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid year");
    }
}

/**
 * @brief Test all Masters Student class methods
 * 
 */
TEST(MastersStudent, AllMethods) {

    Student student_orig{"Jon", "Doe", 24, 8, 1988};
    std::string expected = "Jon Doe";
    expected += "\nAugust 24, 1988";
    EXPECT_EQ(student_orig.toString(), expected);

    MastersStudent student1{"Jon", "Doe", 24, 8, 1988};
    EXPECT_EQ(student1.getFirstName(), "Jon");
    EXPECT_EQ(student1.getLastName(), "Doe");
    EXPECT_EQ(student1.getDOB(), "August 24, 1988");
    EXPECT_NE(student1.getID(), "");

    /* Invalid first name */
    try {
        MastersStudent student{"", "Doe", 24, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid first name");
    }

    /* Invalid last name */
    try {
        MastersStudent student{"Jon", "", 24, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid last name");
    }

    /* Invalid day */
    try {
        MastersStudent student{"Jon", "Doe", 0, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "day must be a positive integer");
    }
    /* Invalid day of even month */
    try {
        MastersStudent student{"Jon", "Doe", 32, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }
    /* Invalid day of odd month */
    try {
        MastersStudent student{"Jon", "Doe", 31, 9, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }
    /* Invalid day of non-leap year */
    try {
        MastersStudent student{"Jon", "Doe", 29, 2, 2001};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }

    /* valid day for leap year */
    MastersStudent student{"Jon", "Doe", 29, 2, 2000};
    expected = "Jon Doe";
    expected += "\nFebruary 29, 2000";
    expected += "\nUser ID: " + student.getID();
    EXPECT_EQ(student.toString(), expected);

    /* Invalid day of leap year */
    try {
        MastersStudent student{"Jon", "Doe", 30, 2, 2000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }

    /* Invalid month */
    try {
        MastersStudent student{"Jon", "Doe", 28, 0, 2000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid month");
    }
    /* Invalid month */
    try {
        MastersStudent student{"Jon", "Doe", 28, 13, 2000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid month");
    }

    /* Invalid year */
    try {
        MastersStudent student{"Jon", "Doe", 28, 10, 0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid year");
    }
}

/**
 * @brief Test all Doctoral Student class methods
 * 
 */
TEST(DoctoralStudent, AllMethods) {

    Student student_orig{"Jon", "Doe", 24, 8, 1988};
    std::string expected = "Jon Doe";
    expected += "\nAugust 24, 1988";
    EXPECT_EQ(student_orig.toString(), expected);

    DoctoralStudent student1{"Jon", "Doe", 24, 8, 1988};
    EXPECT_EQ(student1.getFirstName(), "Jon");
    EXPECT_EQ(student1.getLastName(), "Doe");
    EXPECT_EQ(student1.getDOB(), "August 24, 1988");
    EXPECT_NE(student1.getID(), "");

    /* Invalid first name */
    try {
        DoctoralStudent student{"", "Doe", 24, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid first name");
    }

    /* Invalid last name */
    try {
        DoctoralStudent student{"Jon", "", 24, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid last name");
    }

    /* Invalid day */
    try {
        DoctoralStudent student{"Jon", "Doe", 0, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "day must be a positive integer");
    }
    /* Invalid day of even month */
    try {
        DoctoralStudent student{"Jon", "Doe", 32, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }
    /* Invalid day of odd month */
    try {
        DoctoralStudent student{"Jon", "Doe", 31, 9, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }
    /* Invalid day of non-leap year */
    try {
        DoctoralStudent student{"Jon", "Doe", 29, 2, 2001};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }

    /* valid day for leap year */
    DoctoralStudent student{"Jon", "Doe", 29, 2, 2000};
    expected = "Jon Doe";
    expected += "\nFebruary 29, 2000";
    expected += "\nUser ID: " + student.getID();
    EXPECT_EQ(student.toString(), expected);

    /* Invalid day of leap year */
    try {
        DoctoralStudent student{"Jon", "Doe", 30, 2, 2000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }

    /* Invalid month */
    try {
        DoctoralStudent student{"Jon", "Doe", 28, 0, 2000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid month");
    }
    /* Invalid month */
    try {
        DoctoralStudent student{"Jon", "Doe", 28, 13, 2000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid month");
    }

    /* Invalid year */
    try {
        DoctoralStudent student{"Jon", "Doe", 28, 10, 0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid year");
    }
}