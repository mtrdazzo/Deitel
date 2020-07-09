/**
 * @file tst_Ex_11_9.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Test the implementation of the Package class hierarchy
 * @version 0.1
 * @date 2020-07-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <gtest/gtest.h>
#include <Ex_11_9.h>

/**
 * @brief Test functionality of the Address class
 * 
 */
TEST(AddressClass, Constructor) {

    Address sample{"Jon Doe", 1234, "Fake St.", "San Diego", "CA", 93456};
    EXPECT_EQ(sample.getPersonName(), "Jon Doe");
    EXPECT_EQ(sample.getStreetNumber(), 1234);
    EXPECT_EQ(sample.getStreetName(), "Fake St.");
    EXPECT_EQ(sample.getCityName(), "San Diego");
    EXPECT_EQ(sample.getStateName(), "CA");
    EXPECT_EQ(sample.getZipCode(), 93456);

    try {
        Address sample_failure{"", 1234, "Fake St.", "San Diego", "CA", 93456};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid name");
    }

    try {
        Address sample_failure{"Jon Doe", 0, "Fake St.", "San Diego", "CA", 93456};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid street number");
    }

    try {
        Address sample_failure{"Jon Doe", 1234, "", "San Diego", "CA", 93456};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid street name");
    }

    try {
        Address sample_failure{"Jon Doe", 1234, "Fake St.", "", "CA", 93456};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid city name");
    }

    try {
        Address sample_failure{"Jon Doe", 1234, "Fake St.", "San Diego", "", 93456};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid state name");
    }

    try {
        Address sample_failure{"Jon Doe", 1234, "Fake St.", "San Diego", "CA", 0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid zip code");
    }
}