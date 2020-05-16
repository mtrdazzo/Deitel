#include <gtest/gtest.h>
#include <Ex_10_8.h>

/**
 * @brief Sunny day create vehicle and confirm instance's member values.
 * 
 */
TEST(Constructor, SunnyDayMotorVehicle) {
    
    MotorVehicle myCar("Honda", 2015, "white", "regular", 11);

    EXPECT_STREQ(myCar.getMake().c_str(), "Honda");
    EXPECT_EQ(myCar.getYear(), 2015);
    EXPECT_STREQ(myCar.getColor().c_str(), "white");
    EXPECT_STREQ(myCar.getFuelType().c_str(), "regular");
    EXPECT_EQ(myCar.getFuelCapacity(), 11);
}

/**
 * @brief Attempt to create a vehicle with bad initializers.
 * 
 */
TEST(Constructor, BadInitializers) {

    try {
        MotorVehicle myCar("Honda", YEAR_OF_MODEL_T - 1, "white", "regular", 11);\
    }
    catch (std::invalid_argument &err) {
        EXPECT_STREQ(err.what(), "Year of manufacture must be after the Model T");
    }

    try {
        MotorVehicle myCar("Honda", YEAR_OF_MODEL_T, "white", "regular", 0);\
    }
    catch (std::invalid_argument &err) {
        EXPECT_STREQ(err.what(), "Fuel capacity must be greater than zero");
    }

    try {
        MotorVehicle myCar("Honda", YEAR_OF_MODEL_T, "white", "both", 11);\
    }
    catch (std::invalid_argument &err) {
        EXPECT_STREQ(err.what(), "Fuel type must be regular of deisel");
    }
}

/**
 * @brief Test functionality of all getters/setters.
 * 
 */
TEST(SettersGetters, SetAllMembers) {

    MotorVehicle myCar("Honda", 2015, "white", "regular", 11);

    EXPECT_STREQ(myCar.getMake().c_str(), "Honda");
    EXPECT_EQ(myCar.getYear(), 2015);
    EXPECT_STREQ(myCar.getColor().c_str(), "white");
    EXPECT_STREQ(myCar.getFuelType().c_str(), "regular");
    EXPECT_EQ(myCar.getFuelCapacity(), 11);

    myCar.setMake("Nissan");
    EXPECT_STREQ(myCar.getMake().c_str(), "Nissan");

    int validYear{2014};

    myCar.setYear(validYear);
    EXPECT_EQ(myCar.getYear(), validYear);

    try {
        myCar.setYear(YEAR_OF_MODEL_T - 1);
    }
    catch (std::invalid_argument &err) {
        EXPECT_STREQ(err.what(), "Year of manufacture must be after the Model T");
    }
    EXPECT_EQ(myCar.getYear(), validYear);

    myCar.setColor("black");
    EXPECT_STREQ(myCar.getColor().c_str(), "black");

    myCar.setFuelType("deisel");
    EXPECT_EQ(myCar.getFuelType(), "deisel");

    try {
        myCar.setFuelType("electric");
    }
    catch (std::invalid_argument &err) {
        EXPECT_STREQ(err.what(), "Fuel type must be regular of deisel");
    }
    EXPECT_EQ(myCar.getFuelType(), "deisel");

    int validFuelCapacity{15};

    myCar.setFuelCapacity(validFuelCapacity);
    EXPECT_EQ(myCar.getFuelCapacity(), validFuelCapacity);

    try {
        myCar.setFuelCapacity(0);
    }
    catch (std::invalid_argument &err) {
        EXPECT_STREQ(err.what(), "Fuel capacity must be greater than zero");
    }
    EXPECT_EQ(myCar.getFuelCapacity(), validFuelCapacity);

}

/**
 * @brief Test the equality and inequality operators.
 * 
 */
TEST(Operators, EqualityOperator) {

    MotorVehicle myCar1("Honda", 2015, "white", "regular", 11);
    MotorVehicle myCar2("Honda", 2015, "white", "regular", 11);

    EXPECT_TRUE(myCar1 == myCar2);
    EXPECT_TRUE(myCar2 == myCar1);

    myCar2.setMake("Nissan");
    EXPECT_TRUE(myCar1 != myCar2);
    EXPECT_TRUE(myCar2 != myCar1);
    myCar2.setMake("Honda");
    EXPECT_TRUE(myCar1 == myCar2);
    EXPECT_TRUE(myCar2 == myCar1);

    myCar2.setYear(2014);
    EXPECT_TRUE(myCar1 != myCar2);
    EXPECT_TRUE(myCar2 != myCar1);
    myCar2.setYear(2015);
    EXPECT_TRUE(myCar1 == myCar2);
    EXPECT_TRUE(myCar2 == myCar1);

    myCar2.setColor("black");
    EXPECT_TRUE(myCar1 != myCar2);
    EXPECT_TRUE(myCar2 != myCar1);
    myCar2.setColor("white");
    EXPECT_TRUE(myCar1 == myCar2);
    EXPECT_TRUE(myCar2 == myCar1);

    myCar2.setFuelType("deisel");
    EXPECT_TRUE(myCar1 != myCar2);
    EXPECT_TRUE(myCar2 != myCar1);
    myCar2.setFuelType("regular");
    EXPECT_TRUE(myCar1 == myCar2);
    EXPECT_TRUE(myCar2 == myCar1);

    myCar2.setFuelCapacity(10);
    EXPECT_TRUE(myCar1 != myCar2);
    EXPECT_TRUE(myCar2 != myCar1);
    myCar2.setFuelCapacity(11);
    EXPECT_TRUE(myCar1 == myCar2);
    EXPECT_TRUE(myCar2 == myCar1);
}

/**
 * @brief Test the greather than operator.
 * 
 */
TEST(Operators, GreaterThanOperator) {

    int year{2015};
    MotorVehicle myCar1("Honda", year, "white", "regular", 11);
    MotorVehicle myCar2("Honda", year, "white", "regular", 11);

    EXPECT_FALSE(myCar1 > myCar2);

    myCar1.setYear(year - 1);

    EXPECT_TRUE(myCar1 > myCar2);

    myCar1.setYear(year + 1);

    EXPECT_FALSE(myCar1 > myCar2);
}