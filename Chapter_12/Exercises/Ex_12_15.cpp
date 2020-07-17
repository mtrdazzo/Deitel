/**
 * @file Ex_12_15.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Class method definitions for the CarbonFootprint class hierarchy
 * @version 0.1
 * @date 2020-07-17
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdexcept>
#include "Ex_12_15.h"

/* kg to lbs conversion */
double constants::kgToLbs{2.2};

/* According to https://slate.com/technology/2011/08/how-soon-does-a-bike-pay-back-its-initial-carbon-footprint.html
a bicycle produces a carbon footprint of one ton (2000 lbs) per $1000 manufactured cost or 0.5 $ per lb.
*/
double Bicycle::poundsGreenhousePerDollar{0.5};

/**
 * @brief Estimated profit margin of a manufactured bicycle
 * 
 */
double Bicycle::profitMargin{0.36};

/**
 * @brief Construct a new Bicycle
 * 
 * @param cost Cost of bicycle
 */
Bicycle::Bicycle(double cost) {
    setCost(cost);
}

/**
 * @brief Set the cost of the bicycle
 * 
 * @param cost Cost of bicycle
 */
void Bicycle::setCost(double cost) {
    if (cost <= 0.0)
        throw std::invalid_argument("invalid cost, must be > 0.0");
    this->cost = cost;
}

/**
 * @brief Get the carbon footprint of the bicycle
 * 
 * @return double 
 */
double Bicycle::getCarbonFootprint() const {
    return getCost() * (1 - profitMargin) * poundsGreenhousePerDollar;
}

/* Gasoline emissions factor in units of kg CO2e/US gal */
double Car::gasolineEmissionsFactor{8.78};

/**
 * @brief Construct a new Car:: Car object
 * 
 * @param milesPerGallon 
 * @param milesDriven 
 */
Car::Car(double milesPerGallon, double milesDriven) {
    setMilesPerGallon(milesPerGallon);
    setMilesDriven(milesDriven);
}

/**
 * @brief Set the miles driven of the vehicle
 * 
 * @param milesDriven 
 */
void Car::setMilesDriven(double milesDriven) {
    if (milesDriven <= 0.0)
        throw std::invalid_argument("invalid miles driven, must be > 0.0");
    this->milesDriven = milesDriven;
}

/**
 * @brief Set the miles per gallon of the vehicle
 * 
 * @param milesPerGallon 
 */
void Car::setMilesPerGallon(double milesPerGallon) {
    if (milesPerGallon <= 0.0)
        throw std::invalid_argument("invalid miles per gallon, must be > 0.0");
    this->milesPerGallon = milesPerGallon;
}

/**
 * @brief Get the carbon footprint of the vehicles
 * 
 * @return double carbon footprint in lbs of greenhouse gases
 */
double Car::getCarbonFootprint() const {
    return gasolineEmissionsFactor / (milesDriven / milesPerGallon) * constants::kgToLbs;
}

/* buildings produce approximated 20 lb of C02 emissions per square foot of space */
double Building::carbonPerSquareFoot{20};

/**
 * @brief Construct a new Building:: Building object
 * 
 * @param squareFeet 
 */
Building::Building(double squareFeet) {
    setSquareFeet(squareFeet);
}

/**
 * @brief Set the square footage of the building (ft^2)
 * 
 * @param squareFeet 
 */
void Building::setSquareFeet(double squareFeet) {
    if (squareFeet <= 0.0)
        throw std::invalid_argument("invalid square footage, must be > 0.0");
    this->squareFeet = squareFeet;
}

/**
 * @brief Calculate the carbon footprint for the building
 * 
 * @return double 
 */
double Building::getCarbonFootprint() const {
    return squareFeet * carbonPerSquareFoot;
}