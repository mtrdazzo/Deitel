/**
 * @file tst_Ex_9_8.cpp
 *
 * @brief Tests the instantiation of the Student class.
 *
 * @author Matt Randazzo
 */

#include <Ex_9_8.h>
#include <gtest/gtest.h>

/**
 * @brief Instantiate a male student
 */
TEST(Constructor, validStudentMale) {

    Student newStudent("Matthew", "John", "Randazzo", "Male", 1901, 44223, "mtr@bing.com");

    EXPECT_EQ(newStudent.getFirstName(), std::string("Matthew"));
    EXPECT_EQ(newStudent.getMiddleName(), std::string("John"));
    EXPECT_EQ(newStudent.getLastName(), std::string("Randazzo"));
    EXPECT_EQ(newStudent.getSex(), std::string("Male"));
    EXPECT_EQ(newStudent.getYearOfBirth(), static_cast<uint32_t>(1901));
    EXPECT_EQ(newStudent.getRegistrationNumber(), static_cast<uint32_t>(44223));
    EXPECT_EQ(newStudent.getEmail(), std::string("mtr@bing.com"));
}

/**
 * @brief Instantiate a female student
 */
TEST(Constructor, validStudentFemale) {

    Student newStudent("Alex", "Kenfield", "Randazzo", "Female", 2020, 44223, "mtr@bing.com");


    EXPECT_EQ(newStudent.getFirstName(), std::string("Alex"));
    EXPECT_EQ(newStudent.getMiddleName(), std::string("Kenfield"));
    EXPECT_EQ(newStudent.getLastName(), std::string("Randazzo"));
    EXPECT_EQ(newStudent.getSex(), std::string("Female"));
    EXPECT_EQ(newStudent.getYearOfBirth(), static_cast<uint32_t>(2020));
    EXPECT_EQ(newStudent.getRegistrationNumber(), static_cast<uint32_t>(44223));
    EXPECT_EQ(newStudent.getEmail(), std::string("mtr@bing.com"));
}

/**
 * @brief Instantiate a student with an invalid sex
 */
TEST(Sex, invalidSex) {

    try {
        Student newStudent("Matthew", "John", "Randazzo", "Both", 1901, 44223, "mtr@bing.com");
    }
    catch (std::invalid_argument &err) {
        EXPECT_STREQ(err.what(), "invalid sex must be either Male/Female");
    }
}

/**
 * @brief Instantiate a student with a low invalid birth year
 */
TEST(BirthYear, invalidBirthYearLow) {

    try {
        Student newStudent("Matthew", "John", "Randazzo", "Male", 1899, 44223, "mtr@bing.com");
    }
    catch (std::invalid_argument &err) {
        EXPECT_STREQ(err.what(), "Invalid year of birth, must be (1900-2020)");
    }
}

/**
 * @brief Instantiate a student with a high invalid birth year
 */
TEST(BirthYear, invalidBirthYearHigh) {

    try {
        Student newStudent("Matthew", "John", "Randazzo", "Male", 2021, 44223, "mtr@bing.com");
    }
    catch (std::invalid_argument &err) {
        EXPECT_STREQ(err.what(), "Invalid year of birth, must be (1900-2020)");
    }
}

/**
 * @brief Instantiate a student with an invalid email address
 */
TEST(Email, invalidEmailAt) {

    try {
        Student newStudent("Matthew", "John", "Randazzo", "Male", 2021, 44223, "mtrbing.com");
    }
    catch (std::invalid_argument &err) {
        EXPECT_STREQ(err.what(), "Invalid email must be in the form <address>@<service>.com");
    }
}

/**
 * @brief Instantiate a student with an invalid email service
 */
TEST(Email, invalidEmailService) {

    try {
        Student newStudent("Matthew", "John", "Randazzo", "Male", 2021, 44223, "mtr@bingcom");
    }
    catch (std::invalid_argument &err) {
        EXPECT_STREQ(err.what(), "Invalid email must be in the form <address>@<service>.com");
    }
}
