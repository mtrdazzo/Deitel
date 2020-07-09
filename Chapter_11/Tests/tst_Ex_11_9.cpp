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

#include <iomanip>
#include <gtest/gtest.h>
#include <Ex_11_9.h>

/**
 * @brief Test functionality of the Address class
 * 
 */
TEST(AddressClass, AllMethods) {

    Address sample{"Jon Doe", 1234, "Fake St.", "San Diego", "CA", 93456};
    EXPECT_EQ(sample.getPersonName(), "Jon Doe");
    EXPECT_EQ(sample.getStreetNumber(), 1234);
    EXPECT_EQ(sample.getStreetName(), "Fake St.");
    EXPECT_EQ(sample.getCityName(), "San Diego");
    EXPECT_EQ(sample.getStateName(), "CA");
    EXPECT_EQ(sample.getZipCode(), 93456);

    std::string expected = sample.getPersonName();
    expected += "\n" + std::to_string(sample.getStreetNumber()) + " " + sample.getStreetName();
    expected += "\n" + sample.getCityName() + ", " + sample.getStateName();
    expected += "\n" + std::to_string(sample.getZipCode());
    EXPECT_EQ(sample.toString(), expected);

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

/**
 * @brief Test functionality of the Package class
 * 
 */
#include <iostream>
TEST(PackageClass, AllMethods) {

    Address sender{"Jon Doe", 1234, "Fake St.", "San Diego", "CA", 93456};
    Address recipient{"Jane Doe", 2222, "Real St.", "Tuscon", "AZ", 91111};

    Package examplePackage{recipient, sender, 10, 3.0};

    EXPECT_EQ(examplePackage.getCost(), 3.0);
    EXPECT_EQ(examplePackage.getWeight(), 10);
    EXPECT_EQ(examplePackage.calculateCost(), 3.0 * 10);

    /* get recipient information */
    EXPECT_EQ(examplePackage.getRecipient().getPersonName(), "Jane Doe");
    EXPECT_EQ(examplePackage.getRecipient().getStreetNumber(), 2222);
    EXPECT_EQ(examplePackage.getRecipient().getStreetName(), "Real St.");
    EXPECT_EQ(examplePackage.getRecipient().getCityName(), "Tuscon");
    EXPECT_EQ(examplePackage.getRecipient().getStateName(), "AZ");
    EXPECT_EQ(examplePackage.getRecipient().getZipCode(), 91111);

    /* get sender information */
    EXPECT_EQ(examplePackage.getSender().getPersonName(), "Jon Doe");
    EXPECT_EQ(examplePackage.getSender().getStreetNumber(), 1234);
    EXPECT_EQ(examplePackage.getSender().getStreetName(), "Fake St.");
    EXPECT_EQ(examplePackage.getSender().getCityName(), "San Diego");
    EXPECT_EQ(examplePackage.getSender().getStateName(), "CA");
    EXPECT_EQ(examplePackage.getSender().getZipCode(), 93456);

    std::ostringstream output;
    output << "To:\n" << examplePackage.getRecipient().getPersonName() << "\n";
    output << examplePackage.getRecipient().getStreetNumber() << " " << examplePackage.getRecipient().getStreetName() << "\n";
    output << examplePackage.getRecipient().getCityName() << ", " << examplePackage.getRecipient().getStateName() << "\n";
    output << examplePackage.getRecipient().getZipCode() << "\n\n";

    output << "From:\n" << examplePackage.getSender().getPersonName() << "\n";
    output << examplePackage.getSender().getStreetNumber() << " " << examplePackage.getSender().getStreetName() << "\n";
    output << examplePackage.getSender().getCityName() << ", " << examplePackage.getSender().getStateName() << "\n";
    output << examplePackage.getSender().getZipCode() << "\n\n";

    output << "Weight: " << examplePackage.getWeight() << " oz\n";
    output << std::fixed << std::setprecision(2);
    output << "Cost: $" << examplePackage.calculateCost();

    EXPECT_EQ(output.str(), examplePackage.toString());
}
