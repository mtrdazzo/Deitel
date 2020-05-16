/**
 * @file Ex_10_8.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Interface for the Enhanced MotorVehicle Class
 * 
 * Exercise 10-8 Enhanced MotorVehicle Class
 * 
 * Enhance the MotorVehicle class of Exercise 3.11 by overloading the following operators:
 * 
 * a) Equality (==) : two MotorVehicle objects are equal (identical) if all their attributes are identical,
 *    that is, they of the same make, they use the same type of fuel, they were manufactured in the same year,
 *    they are of the same color and they have the same engine capacity.
 * 
 * b) Not equal (!=) : two MotorVehicle objets are not equal (not identical) if any of their attributes do not
 *    match.
 * 
 * c) Greater than (>) : A MotorVehicle object is greater than another MotorVehicle object if the former was
 *    manufactured before the latter.
 * 
 * d) Output operator (<<) : displays a MotorVehicle in a similar fashion to the displayCarDetail's function.
 * 
 * @version 0.1
 * @date 2020-05-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef EX_10_8_H
#define EX_10_8_H

#include <iostream>
#include <string>
#include <stdint.h>

class MotorVehicle {

    /**
     * @brief Output MotorVehicle class data to a public stream
     * 
     * @return std::ostream 
     */
    friend std::ostream operator<<(std::ostream &, MotorVehicle &);

    public:

        /**
         * @brief Construct a new Motor Vehicle object
         * 
         * @param make         Make of vehicle
         * @param year         Year of manufacture
         * @param color        Color of exterior
         * @param fuelType     Fuel Type (deisel, regular)
         * @param fuelCapacity Size of fuel tank (US gallons)
         */
        MotorVehicle(std::string make, 
                     int year,
                     std::string color,
                     std::string fuelType,
                     int fuelCapacity);

        /**
         * @brief Equality operator
         * 
         * @return true All data for both MotorVehicle operands are equal.
         * @return false 
         */
        bool operator==(MotorVehicle &);

        /**
         * @brief Inequality operator
         * 
         * @return true Data for both MotorVehicle operands are not equal.
         * @return false 
         */
        bool operator!=(MotorVehicle &);

        /**
         * @brief Greater than operator
         * 
         * @return true Manufacture date of the former operand was manufactured before the latter.
         * @return false 
         */
        bool operator>(MotorVehicle &);

    private:

        std::string m_sMake;
        int m_iYearOfManufacture;
        std::string m_sColor;
        std::string m_sFuelType;
        int m_iEngineCapacity;

};

#endif