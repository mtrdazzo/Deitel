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

    UndergraduateStudent student1{"Jon", "Doe", 24, 8, 1988, FRESHMAN_YEAR};
    EXPECT_EQ(student1.getFirstName(), "Jon");
    EXPECT_EQ(student1.getLastName(), "Doe");
    EXPECT_EQ(student1.getDOB(), "August 24, 1988");
    EXPECT_NE(student1.getID(), "");
    EXPECT_EQ(student1.getStudentYear(), FRESHMAN_YEAR);

    /* Invalid first name */
    try {
        UndergraduateStudent student{"", "Doe", 24, 8, 1988, 1};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid first name");
    }

    /* Invalid last name */
    try {
        UndergraduateStudent student{"Jon", "", 24, 8, 1988, 1};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid last name");
    }

    /* Invalid day */
    try {
        UndergraduateStudent student{"Jon", "Doe", 0, 8, 1988, 1};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "day must be a positive integer");
    }
    /* Invalid day of even month */
    try {
        UndergraduateStudent student{"Jon", "Doe", 32, 8, 1988, 1};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }
    /* Invalid day of odd month */
    try {
        UndergraduateStudent student{"Jon", "Doe", 31, 9, 1988, 1};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }
    /* Invalid day of non-leap year */
    try {
        UndergraduateStudent student{"Jon", "Doe", 29, 2, 2001, 1};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }

    /* valid day for leap year */
    UndergraduateStudent student{"Jon", "Doe", 29, 2, 2000, 1};
    expected = "Jon Doe";
    expected += "\nFebruary 29, 2000";
    expected += "\nUser ID: " + student.getID();
    expected += "\nYear: " + std::to_string(student.getStudentYear());
    EXPECT_EQ(student.toString(), expected);

    /* Invalid day of leap year */
    try {
        UndergraduateStudent student{"Jon", "Doe", 30, 2, 2000, 1};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }

    /* Invalid month */
    try {
        UndergraduateStudent student{"Jon", "Doe", 28, 0, 2000, 1};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid month");
    }
    /* Invalid month */
    try {
        UndergraduateStudent student{"Jon", "Doe", 28, 13, 2000, 1};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid month");
    }

    /* Invalid year */
    try {
        UndergraduateStudent student{"Jon", "Doe", 28, 10, 0, 1};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid year");
    }

    /* Invalid stduent year */
    try {
        UndergraduateStudent student{"Jon", "Doe", 28, 10, 1988, 0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid student year");
    }
}

/**
 * @brief Test all Freshman class methods
 * 
 */
TEST(Freshman, AllMethods) {

    Student student_orig{"Jon", "Doe", 24, 8, 1988};
    std::string expected = "Jon Doe";
    expected += "\nAugust 24, 1988";
    EXPECT_EQ(student_orig.toString(), expected);

    Freshman student1{"Jon", "Doe", 24, 8, 1988};
    EXPECT_EQ(student1.getFirstName(), "Jon");
    EXPECT_EQ(student1.getLastName(), "Doe");
    EXPECT_EQ(student1.getDOB(), "August 24, 1988");
    EXPECT_NE(student1.getID(), "");
    EXPECT_EQ(student1.getStudentYear(), FRESHMAN_YEAR);

    /* Invalid first name */
    try {
        Freshman student{"", "Doe", 24, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid first name");
    }

    /* Invalid last name */
    try {
        Freshman student{"Jon", "", 24, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid last name");
    }

    /* Invalid day */
    try {
        Freshman student{"Jon", "Doe", 0, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "day must be a positive integer");
    }
    /* Invalid day of even month */
    try {
        Freshman student{"Jon", "Doe", 32, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }
    /* Invalid day of odd month */
    try {
        Freshman student{"Jon", "Doe", 31, 9, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }
    /* Invalid day of non-leap year */
    try {
        Freshman student{"Jon", "Doe", 29, 2, 2001};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }

    /* valid day for leap year */
    Freshman student{"Jon", "Doe", 29, 2, 2000};
    expected = "Jon Doe";
    expected += "\nFebruary 29, 2000";
    expected += "\nUser ID: " + student.getID();
    expected += "\nYear: " + std::to_string(student.getStudentYear());
    EXPECT_EQ(student.toString(), expected);

    /* Invalid day of leap year */
    try {
        Freshman student{"Jon", "Doe", 30, 2, 2000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }

    /* Invalid month */
    try {
        Freshman student{"Jon", "Doe", 28, 0, 2000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid month");
    }
    /* Invalid month */
    try {
        Freshman student{"Jon", "Doe", 28, 13, 2000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid month");
    }

    /* Invalid year */
    try {
        Freshman student{"Jon", "Doe", 28, 10, 0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid year");
    }
}

/**
 * @brief Test all Sophomore class methods
 * 
 */
TEST(Sophomore, AllMethods) {

    Student student_orig{"Jon", "Doe", 24, 8, 1988};
    std::string expected = "Jon Doe";
    expected += "\nAugust 24, 1988";
    EXPECT_EQ(student_orig.toString(), expected);

    Sophomore student1{"Jon", "Doe", 24, 8, 1988};
    EXPECT_EQ(student1.getFirstName(), "Jon");
    EXPECT_EQ(student1.getLastName(), "Doe");
    EXPECT_EQ(student1.getDOB(), "August 24, 1988");
    EXPECT_NE(student1.getID(), "");
    EXPECT_EQ(student1.getStudentYear(), SOPHOMORE_YEAR);

    /* Invalid first name */
    try {
        Sophomore student{"", "Doe", 24, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid first name");
    }

    /* Invalid last name */
    try {
        Sophomore student{"Jon", "", 24, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid last name");
    }

    /* Invalid day */
    try {
        Sophomore student{"Jon", "Doe", 0, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "day must be a positive integer");
    }
    /* Invalid day of even month */
    try {
        Sophomore student{"Jon", "Doe", 32, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }
    /* Invalid day of odd month */
    try {
        Sophomore student{"Jon", "Doe", 31, 9, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }
    /* Invalid day of non-leap year */
    try {
        Sophomore student{"Jon", "Doe", 29, 2, 2001};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }

    /* valid day for leap year */
    Sophomore student{"Jon", "Doe", 29, 2, 2000};
    expected = "Jon Doe";
    expected += "\nFebruary 29, 2000";
    expected += "\nUser ID: " + student.getID();
    expected += "\nYear: " + std::to_string(student.getStudentYear());
    EXPECT_EQ(student.toString(), expected);

    /* Invalid day of leap year */
    try {
        Sophomore student{"Jon", "Doe", 30, 2, 2000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }

    /* Invalid month */
    try {
        Sophomore student{"Jon", "Doe", 28, 0, 2000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid month");
    }
    /* Invalid month */
    try {
        Sophomore student{"Jon", "Doe", 28, 13, 2000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid month");
    }

    /* Invalid year */
    try {
        Sophomore student{"Jon", "Doe", 28, 10, 0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid year");
    }
}

/**
 * @brief Test all Junior class methods
 * 
 */
TEST(Junior, AllMethods) {

    Student student_orig{"Jon", "Doe", 24, 8, 1988};
    std::string expected = "Jon Doe";
    expected += "\nAugust 24, 1988";
    EXPECT_EQ(student_orig.toString(), expected);

    Junior student1{"Jon", "Doe", 24, 8, 1988};
    EXPECT_EQ(student1.getFirstName(), "Jon");
    EXPECT_EQ(student1.getLastName(), "Doe");
    EXPECT_EQ(student1.getDOB(), "August 24, 1988");
    EXPECT_NE(student1.getID(), "");
    EXPECT_EQ(student1.getStudentYear(), JUNIOR_YEAR);

    /* Invalid first name */
    try {
        Junior student{"", "Doe", 24, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid first name");
    }

    /* Invalid last name */
    try {
        Junior student{"Jon", "", 24, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid last name");
    }

    /* Invalid day */
    try {
        Junior student{"Jon", "Doe", 0, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "day must be a positive integer");
    }
    /* Invalid day of even month */
    try {
        Junior student{"Jon", "Doe", 32, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }
    /* Invalid day of odd month */
    try {
        Junior student{"Jon", "Doe", 31, 9, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }
    /* Invalid day of non-leap year */
    try {
        Junior student{"Jon", "Doe", 29, 2, 2001};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }

    /* valid day for leap year */
    Junior student{"Jon", "Doe", 29, 2, 2000};
    expected = "Jon Doe";
    expected += "\nFebruary 29, 2000";
    expected += "\nUser ID: " + student.getID();
    expected += "\nYear: " + std::to_string(student.getStudentYear());
    EXPECT_EQ(student.toString(), expected);

    /* Invalid day of leap year */
    try {
        Junior student{"Jon", "Doe", 30, 2, 2000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }

    /* Invalid month */
    try {
        Junior student{"Jon", "Doe", 28, 0, 2000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid month");
    }
    /* Invalid month */
    try {
        Junior student{"Jon", "Doe", 28, 13, 2000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid month");
    }

    /* Invalid year */
    try {
        Junior student{"Jon", "Doe", 28, 10, 0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid year");
    }
}


/**
 * @brief Test all Senior class methods
 * 
 */
TEST(Senior, AllMethods) {

    Student student_orig{"Jon", "Doe", 24, 8, 1988};
    std::string expected = "Jon Doe";
    expected += "\nAugust 24, 1988";
    EXPECT_EQ(student_orig.toString(), expected);

    Senior student1{"Jon", "Doe", 24, 8, 1988};
    EXPECT_EQ(student1.getFirstName(), "Jon");
    EXPECT_EQ(student1.getLastName(), "Doe");
    EXPECT_EQ(student1.getDOB(), "August 24, 1988");
    EXPECT_NE(student1.getID(), "");
    EXPECT_EQ(student1.getStudentYear(), SENIOR_YEAR);

    /* Invalid first name */
    try {
        Senior student{"", "Doe", 24, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid first name");
    }

    /* Invalid last name */
    try {
        Senior student{"Jon", "", 24, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid last name");
    }

    /* Invalid day */
    try {
        Senior student{"Jon", "Doe", 0, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "day must be a positive integer");
    }
    /* Invalid day of even month */
    try {
        Senior student{"Jon", "Doe", 32, 8, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }
    /* Invalid day of odd month */
    try {
        Senior student{"Jon", "Doe", 31, 9, 1988};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }
    /* Invalid day of non-leap year */
    try {
        Senior student{"Jon", "Doe", 29, 2, 2001};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }

    /* valid day for leap year */
    Senior student{"Jon", "Doe", 29, 2, 2000};
    expected = "Jon Doe";
    expected += "\nFebruary 29, 2000";
    expected += "\nUser ID: " + student.getID();
    expected += "\nYear: " + std::to_string(student.getStudentYear());
    EXPECT_EQ(student.toString(), expected);

    /* Invalid day of leap year */
    try {
        Senior student{"Jon", "Doe", 30, 2, 2000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid day of month");
    }

    /* Invalid month */
    try {
        Senior student{"Jon", "Doe", 28, 0, 2000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid month");
    }
    /* Invalid month */
    try {
        Senior student{"Jon", "Doe", 28, 13, 2000};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid month");
    }

    /* Invalid year */
    try {
        Senior student{"Jon", "Doe", 28, 10, 0};
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