/**
 * @file Ex_11_9.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Package hierarchy class-method defintions
 * @version 0.1
 * @date 2020-07-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "Ex_11_9.h"

/**
 * @brief Construct a new Address:: Address object
 * 
 * @param fullName 
 * @param streetNumber 
 * @param streetName 
 * @param cityName 
 * @param stateName 
 * @param zipCode 
 */
Address::Address(std::string fullName, int streetNumber, std::string streetName, std::string cityName, std::string stateName, int zipCode) {
    setPersonName(fullName);
    setStreetNumber(streetNumber);
    setStreetName(streetName);
    setCityName(cityName);
    setStateName(stateName);
    setZipCode(zipCode);
}

/**
 * @brief Produce the string representation of the address
 * 
 * @return std::string 
 */
std::string Address::toString() const {

    std::ostringstream output;

    output << personName << "\n";
    output << streetNumber << " " + streetName + "\n";
    output << cityName << ", " << stateName << "\n";
    output << zipCode;

    return output.str();
}
