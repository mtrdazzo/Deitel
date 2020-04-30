/**
 * @file tst_Ex_9_7.cpp
 *
 * @brief Tests the constructor and get salutation of the Name class.
 *
 * @author Matt Randazzo
 */

#include <Ex_9_7.h>
#include <gtest/gtest.h>

/**
 * @brief Create a valid Name class
 */
TEST(Constructor, validConstructor) {

    Name sampleName{"Hello there,", "Matthew", "J", "Rand"};

}

/**
 * @brief Get the salutation of a Name object
 */
TEST(toString, getValidString) {

    Name sampleName{"Hello there,", "Matthew", "J", "Rand"};

    EXPECT_EQ(sampleName.toString(), "Hello there, Rand, Matthew J.");
}
