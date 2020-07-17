/**
 * @file tst_Ex_12_12.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Test the implementation of the Package class hierarchy
 * @version 0.1
 * @date 2020-07-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iomanip>
#include <vector>
#include <typeinfo>
#include <stdexcept>
#include <gtest/gtest.h>
#include <Ex_12_12.h>

/**
 * @brief Test polymorphic behavior of Package class hierarchy
 * 
 */
TEST(PackageHierarchy, Polymorphism) {

    std::vector<Package*> packages;
    const int numPackages{10};
    const double overnightFee{10.4};
    const int twoDayFee{100};
    const int weight{45};
    const double costPerOunce{1.25};

    Address from{"The Seller", 860, "Sequioa St", "Gardena", "CA", 93342};
    Address to{"The Buyer", 861, "What St", "San Diego", "AZ", 92226};

    for (size_t packageNum{0}; packageNum < numPackages; ++packageNum) {
        if (packageNum % 2) {
            packages.push_back(new OvernightPackage{from, to, weight, costPerOunce, overnightFee});
        }
        else
        {
            packages.push_back(new TwoDayPackage{from, to, weight, costPerOunce, twoDayFee});
        }
    }

    /* expected values */
    OvernightPackage expectedOvernight{from, to, weight, costPerOunce, overnightFee};
    TwoDayPackage expectedTwoDay{from, to, weight, costPerOunce, twoDayFee};

    for (auto & package : packages) {

        if (dynamic_cast<OvernightPackage*>(package) != nullptr) {
            EXPECT_EQ(package->toString(), expectedOvernight.toString());
            EXPECT_EQ(package->calculateCost(), expectedOvernight.calculateCost());
        }
        else if (dynamic_cast<TwoDayPackage*>(package) != nullptr) {
            EXPECT_EQ(package->toString(), expectedTwoDay.toString());
            EXPECT_EQ(package->calculateCost(), expectedTwoDay.calculateCost());
        }
        else {
            delete package;
            throw std::invalid_argument("invalid class pointer type");
        }

        /* clean up */
        delete package;
    }
}

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
TEST(PackageClass, AllMethods) {

    Address sender{"Jon Doe", 1234, "Fake St.", "San Diego", "CA", 93456};
    Address recipient{"Jane Doe", 2222, "Real St.", "Tuscon", "AZ", 91111};

    Package examplePackage{recipient, sender, 10, 3.0};

    /* invalid weight */
    try {
        Package failPackage{recipient, sender, 0, 3.0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid weight");
    }

    /* invalid cost per ounce */
    try {
        Package failPackage{recipient, sender, 10, 0.0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid cost per ounce");
    }

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
    std::ostringstream actual;
    actual << examplePackage;

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

    EXPECT_EQ(output.str(), actual.str());
}

/**
 * @brief Test functionality of the TwoDayPackage class
 * 
 */
TEST(TwoDayPackageClass, AllMethods) {

    Address sender{"Jon Doe", 1234, "Fake St.", "San Diego", "CA", 93456};
    Address recipient{"Jane Doe", 2222, "Real St.", "Tuscon", "AZ", 91111};

    TwoDayPackage examplePackage{recipient, sender, 10, 3.0, 5.0};

    EXPECT_EQ(examplePackage.getCost(), 3.0);
    EXPECT_EQ(examplePackage.getWeight(), 10);
    EXPECT_EQ(examplePackage.calculateCost(), 3.0 * 10 + 5.0);
    EXPECT_EQ(examplePackage.getFlatFee(), 5.0);

    /* invalid weight */
    try {
        TwoDayPackage failPackage{recipient, sender, 0, 3.0, 5.0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid weight");
    }

    /* invalid cost per ounce */
    try {
        TwoDayPackage failPackage{recipient, sender, 10, 0.0, 5.0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid cost per ounce");
    }

    /* inavlid flat fee */
    try {
        TwoDayPackage failPackage{recipient, sender, 10, 3.0, 0.0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid flat fee");
    }

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
    output << "\nFlat fee: $" << examplePackage.getFlatFee();

    std::ostringstream actual;
    actual << examplePackage;
    EXPECT_EQ(output.str(), actual.str());
}

/**
 * @brief Test functionality of the OvernightPackage class
 * 
 */
TEST(OvernightPackageClass, AllMethods) {

    Address sender{"Jon Doe", 1234, "Fake St.", "San Diego", "CA", 93456};
    Address recipient{"Jane Doe", 2222, "Real St.", "Tuscon", "AZ", 91111};

    OvernightPackage examplePackage{recipient, sender, 10, 3.0, 5.0};

    EXPECT_EQ(examplePackage.getCost(), 3.0);
    EXPECT_EQ(examplePackage.getWeight(), 10);
    EXPECT_EQ(examplePackage.calculateCost(), 3.0 * 10 + 10 * 5.0);
    EXPECT_EQ(examplePackage.getOvernightFee(), 5.0);

    /* invalid weight */
    try {
        OvernightPackage failPackage{recipient, sender, 0, 3.0, 5.0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid weight");
    }

    /* invalid cost per ounce */
    try {
        OvernightPackage failPackage{recipient, sender, 10, 0.0, 5.0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid cost per ounce");
    }

    /* inavlid flat fee */
    try {
        OvernightPackage failPackage{recipient, sender, 10, 3.0, 0.0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid flat fee");
    }

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
    output << "\nOvernight fee: $" << examplePackage.getOvernightFee();

    std::ostringstream actual;
    actual << examplePackage;
    EXPECT_EQ(output.str(), actual.str());
}
