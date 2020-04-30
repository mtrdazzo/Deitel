/**
 * @file tst_Ex_9_9.cpp
 *
 * @brief Tests the instantiation of the Student and Name class.
 *
 * @author Matt Randazzo
 */

#include <Ex_9_9.h>
#include <gtest/gtest.h>

/**
 * @brief Instantiate an invalid male student
 */
TEST(Constructor, validStudentMale) {

    Student newStudent("Matthew", "John", "Randazzo", "Male", 8, 29, 1901, 44223, "mtr@bing.com");

    EXPECT_EQ(newStudent.getFirstName(), std::string("Matthew"));
    EXPECT_EQ(newStudent.getMiddleName(), std::string("John"));
    EXPECT_EQ(newStudent.getLastName(), std::string("Randazzo"));
    EXPECT_EQ(newStudent.getSex(), std::string("Male"));
    EXPECT_EQ(newStudent.getYearOfBirth(), static_cast<uint32_t>(1901));
    EXPECT_EQ(newStudent.getRegistrationNumber(), static_cast<uint32_t>(44223));
    EXPECT_EQ(newStudent.getEmail(), std::string("mtr@bing.com"));
    EXPECT_EQ(newStudent.getMonth(), static_cast<uint32_t>(8));
    EXPECT_EQ(newStudent.getDay(), static_cast<uint32_t>(29));

}

/**
 * @brief Instantiate a valid female student
 */
TEST(Constructor, validStudentFemale) {

    Student newStudent("Alex", "Kenfield", "Randazzo", "Female", 4, 20, 2020, 44223, "mtr@bing.com");

    EXPECT_EQ(newStudent.getFirstName(), std::string("Alex"));
    EXPECT_EQ(newStudent.getMiddleName(), std::string("Kenfield"));
    EXPECT_EQ(newStudent.getLastName(), std::string("Randazzo"));
    EXPECT_EQ(newStudent.getSex(), std::string("Female"));
    EXPECT_EQ(newStudent.getYearOfBirth(), static_cast<uint32_t>(2020));
    EXPECT_EQ(newStudent.getRegistrationNumber(), static_cast<uint32_t>(44223));
    EXPECT_EQ(newStudent.getEmail(), std::string("mtr@bing.com"));
    EXPECT_EQ(newStudent.getMonth(), static_cast<uint32_t>(4));
    EXPECT_EQ(newStudent.getDay(), static_cast<uint32_t>(20));

}

/**
 * @brief Instantiate an invalid sex
 */
TEST(Sex, invalidSex) {

    try {
        Student newStudent("Matthew", "John", "Randazzo", "Both", 8, 29, 1901, 44223, "mtr@bing.com");
    }
    catch (std::invalid_argument &err) {
        EXPECT_STREQ(err.what(), "invalid sex must be either Male/Female");
    }
}

/**
 * @brief Instantiate an invalid low birth day in a leap year
 */
TEST(BirthYear, invalidBirthYearLow) {

    try {
        Student newStudent("Matthew", "John", "Randazzo", "Male", 4, 20, 1899, 44223, "mtr@bing.com");
    }
    catch (std::invalid_argument &err) {
        EXPECT_STREQ(err.what(), "Invalid year of birth, must be (1900-2020)");
    }
}

/**
 * @brief Instantiate an invalid birth day in a leap year
 */
TEST(BirthYear, invalidBirthYearHigh) {

    try {
        Student newStudent("Matthew", "John", "Randazzo", "Male", 4, 20, 2021, 44223, "mtr@bing.com");
    }
    catch (std::invalid_argument &err) {
        EXPECT_STREQ(err.what(), "Invalid year of birth, must be (1900-2020)");
    }
}

/**
 * @brief Instantiate an invalid birth month in a non leap year
 */
TEST(BirthMonth, invalidBirthMonthLow) {

    try {
        Student newStudent("Matthew", "John", "Randazzo", "Male", 0, 20, 1989, 44223, "mtr@bing.com");
    }
    catch (std::invalid_argument &err) {
        EXPECT_STREQ(err.what(), "Invalid month of year, must be (1-12)");
    }
}

/**
 * @brief Instantiate an invalid high birth month in a leap year
 */
TEST(BirthMonth, invalidBirthMonthHigh) {

    try {
        Student newStudent("Matthew", "John", "Randazzo", "Male", 13, 20, 1989, 44223, "mtr@bing.com");
    }
    catch (std::invalid_argument &err) {
        EXPECT_STREQ(err.what(), "Invalid month of year, must be (1-12)");
    }
}

/**
 * @brief Instantiate an invalid odd high birth month in a leap year
 */
TEST(Birthday, invalidBirthdayOddMonthHigh) {

    try {
        Student newStudent("Matthew", "John", "Randazzo", "Male", 1, 32, 1989, 44223, "mtr@bing.com");
    }
    catch (std::invalid_argument &err) {
        EXPECT_STREQ(err.what(), "Invalid day, must be (1-31) for this month");
    }
}

/**
 * @brief Instantiate an invalid month in a leap year
 */
TEST(Birthday, invalidBirthdayOddMonthLow) {

    try {
        Student newStudent("Matthew", "John", "Randazzo", "Male", 1, 0, 1989, 44223, "mtr@bing.com");
    }
    catch (std::invalid_argument &err) {
        EXPECT_STREQ(err.what(), "Invalid day, must be (1-31) for this month");
    }
}

/**
 * @brief Instantiate an invalid low month a leap year
 */
TEST(Birthday, invalidBirthdayEvenMonthLow) {

    try {
        Student newStudent("Matthew", "John", "Randazzo", "Male", 4, 0, 1989, 44223, "mtr@bing.com");
    }
    catch (std::invalid_argument &err) {
        EXPECT_STREQ(err.what(), "Invalid day, must be (1-30) for this month");
    }
}

/**
 * @brief Instantiate an invalid month in a leap year
 */
TEST(Birthday, invalidBirthdayEvenMonthHigh) {

    try {
        Student newStudent("Matthew", "John", "Randazzo", "Male", 4, 32, 1989, 44223, "mtr@bing.com");
    }
    catch (std::invalid_argument &err) {
        EXPECT_STREQ(err.what(), "Invalid day, must be (1-30) for this month");
    }
}

/**
 * @brief Instantiate an invalid birthday in a leap year
 */
TEST(Birthday, invalidBirthdayLeapYearHigh) {

    try {
        Student newStudent("Matthew", "John", "Randazzo", "Male", 2, 31, 2000, 44223, "mtr@bing.com");
    }
    catch (std::invalid_argument &err) {
        EXPECT_STREQ(err.what(), "Invalid day, must be (1-29) for this month");
    }
}

/**
 * @brief Instantiate an invalid email service
 */
TEST(Email, invalidEmailAt) {

    try {
        Student newStudent("Matthew", "John", "Randazzo", "Male", 4, 20, 2021, 44223, "mtrbing.com");
    }
    catch (std::invalid_argument &err) {
        EXPECT_STREQ(err.what(), "Invalid email must be in the form <address>@<service>.com");
    }
}

/**
 * @brief Instantiate an invalid email service
 */
TEST(Email, invalidEmailService) {

    try {
        Student newStudent("Matthew", "John", "Randazzo", "Male", 4, 20, 2021, 44223, "mtr@bingcom");
    }
    catch (std::invalid_argument &err) {
        EXPECT_STREQ(err.what(), "Invalid email must be in the form <address>@<service>.com");
    }
}