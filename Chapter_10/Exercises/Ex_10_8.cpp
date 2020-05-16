/**
 * @file Ex_10_8.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Implementation of the Enhanced MotorVehicle class
 * @version 0.1
 * @date 2020-05-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <Ex_10_8.h>

/**
 * @brief Construct a new Motor Vehicle object
 * 
 * @param make         Make of vehicle
 * @param year         Year of manufacture
 * @param color        Color of exterior
 * @param fuelType     Fuel Type (deisel, regular)
 * @param fuelCapacity Size of fuel tank (US gallons)
 */
MotorVehicle::MotorVehicle(std::string make, 
                           int year,
                           std::string color,
                           std::string fuelType,
                           int fuelCapacity) {
                               setMake(make);
                               setYear(year);
                               setColor(color);
                               setFuelType(fuelType);
                               setFuelCapacity(fuelCapacity);
                           }

/**
 * @brief Set the year of manufacture of the vehicle.
 * 
 * @param year Year of manufacture, must at or during first year of Model T (1908).
 */
void MotorVehicle::setYear(const int year) {

    if (year < YEAR_OF_MODEL_T)
        throw std::invalid_argument("Year of manufacture must be after the Model T");
    else
        m_iYearOfManufacture = year;
}

/**
 * @brief Set the fule type of the vehicle.
 * 
 * @param fuelType Fuel type of the vehicle (deisel/regular).
 */
void MotorVehicle::setFuelType(const std::string &fuelType) {

    if (fuelType.compare(regularFuel) && fuelType.compare(deiselFuel))
        throw std::invalid_argument("Fuel type must be regular of deisel");
    else
        m_sFuelType = fuelType;
}

/**
 * @brief Set the engine capacity of the vehicle (US gallons).
 * 
 * @param fuelCapacity Fuel capacity of the vehicle (US gallons).
 */
void MotorVehicle::setFuelCapacity(const int fuelCapacity) {
    if (fuelCapacity <= 0)
        throw std::invalid_argument("Fuel capacity must be greater than zero");
    else
        m_iFuelCapacity = fuelCapacity;
}

/**
 * @brief Equality operator
 * 
 * @param other Other MotorVehicle operand
 * @return true All data for both MotorVehicle operands are equal.
 * @return false 
 */
bool MotorVehicle::operator==(MotorVehicle &other) {

    if (this->m_sMake == other.m_sMake &&
        this->m_iYearOfManufacture == other.m_iYearOfManufacture &&
        this->m_sColor == other.m_sColor &&
        this->m_sFuelType == other.m_sFuelType &&
        this->m_iFuelCapacity == other.m_iFuelCapacity)
        return true; 
    return false;
}