/**
 * @file tst_Ex_12_15.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Test the CarbonFootprint class hierarchy
 * @version 0.1
 * @date 2020-07-17
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdexcept>
#include <typeinfo>
#include <vector>
#include <gtest/gtest.h>
#include <Ex_12_15.h>

/**
 * @brief Test instantiating a Carbon Footprint object
 * 
 */
TEST(CarbonFootprintHierarchy, Polymorphism) {

    std::vector<CarbonFootprint*> footprintObjs;

    double bicycleCost{400.0};
    double squareFootage{1000};
    double mpg{32};
    double milesDriven{100};

    footprintObjs.push_back(new Bicycle(bicycleCost));
    footprintObjs.push_back(new Building(squareFootage));
    footprintObjs.push_back(new Car(mpg, milesDriven));

    Bicycle expectedBicycle{bicycleCost};
    Car expectedCar{mpg, milesDriven};
    Building expectedBuilding{squareFootage};

    for (auto & footprint : footprintObjs) {

        if (dynamic_cast<Car*>(footprint) != nullptr)
            EXPECT_EQ(footprint->getCarbonFootprint(), expectedCar.getCarbonFootprint());
        else if (dynamic_cast<Bicycle*>(footprint) != nullptr)
            EXPECT_EQ(footprint->getCarbonFootprint(), expectedBicycle.getCarbonFootprint());
        else if (dynamic_cast<Building*>(footprint) != nullptr)
            EXPECT_EQ(footprint->getCarbonFootprint(), expectedBuilding.getCarbonFootprint());
        else {
            /* should not be here */;
        }

        delete footprint;
    }

}

/**
 * @brief Test instantiating a Bicycle object
 * 
 */
TEST(ClassBicycle, Constructor) {

    /* attempt to intantiate a free bicycle */
    try {
        Bicycle{0.0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid cost, must be > 0.0");
    }

    /* attempt to intantiate a bicycle worth negative dollars */
    try {
        Bicycle{-10.0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid cost, must be > 0.0");
    }

    double sampleCost{345.99};
    Bicycle schwinn{sampleCost};

    EXPECT_EQ(schwinn.getCost(), sampleCost);
}

/**
 * @brief Calculate the carbon footprint of the bicycle
 * 
 */
TEST(ClassBicycle, CalculateCarbonFootprint) {

    double sampleCost{500};
    Bicycle example{sampleCost};

    EXPECT_EQ(example.getCarbonFootprint(), sampleCost * (1 - Bicycle::getProfitMargin()) * Bicycle::getPoundsPerGreenhousePerDollar());

}

/**
 * @brief Test instantiating a Car object
 * 
 */
TEST(ClassCar, Constructor) {

    /* attempt to intantiate a car with no miles per gallon */
    try {
        Car{0.0, 35.0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid miles per gallon, must be > 0.0");
    }

    /* attempt to intantiate a car with negative miles per gallon */
    try {
        Car{-10.0, 35.0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid miles per gallon, must be > 0.0");
    }

    /* attempt to intantiate a car with no miles driven */
    try {
        Car{10.0, 0.0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid miles driven, must be > 0.0");
    }

    /* attempt to intantiate acar  with negative miles driven */
    try {
        Car{10.0, -35.0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid miles driven, must be > 0.0");
    }

    double sampleMPG{32};
    double sampleMilesDriven{10};
    Car Honda{sampleMPG, sampleMilesDriven};

    EXPECT_EQ(Honda.getMilesPerGallon(), sampleMPG);
    EXPECT_EQ(Honda.getMilesDriven(), sampleMilesDriven);
}

/**
 * @brief Calculate the carbon footprint of the car
 * 
 */
TEST(ClassCar, CalculateCarbonFootprint) {

    double sampleMPG{32};
    double sampleMilesDriven{10};
    Car example{sampleMPG, sampleMilesDriven};

    double expectedFootprint = Car::getGasolineEmissionsFactor() / (sampleMilesDriven / sampleMPG) * constants::kgToLbs;

    EXPECT_EQ(example.getCarbonFootprint(), expectedFootprint);

}

/**
 * @brief Test instantiating a Building object
 * 
 */
TEST(ClassBuilding, Constructor) {

    /* attempt to intantiate a building with no square footage */
    try {
        Building{0.0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid square footage, must be > 0.0");
    }

    /* attempt to intantiate a building with negative footage */
    try {
        Building{-10.0};
    } catch (std::invalid_argument & err) {
        EXPECT_STREQ(err.what(), "invalid square footage, must be > 0.0");
    }

    double sampleSquareFootage{32};
    Building home{sampleSquareFootage};

    EXPECT_EQ(home.getSquareFeet(), sampleSquareFootage);
}

/**
 * @brief Calculate the carbon footprint of the building
 * 
 */
TEST(ClassBuilding, CalculateCarbonFootprint) {

    double sampleSquareFootage{32};
    Building example{sampleSquareFootage};

    double expectedFootprint = Building::getCarbonPerSquareFoot() * sampleSquareFootage;

    EXPECT_EQ(example.getCarbonFootprint(), expectedFootprint);

}