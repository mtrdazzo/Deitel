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
#include <iomanip>

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

std::ostream& operator<<(std::ostream &output, const Address &address) {
    output << address.toString();
    return output;
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

/**
 * @brief Construct a new Package:: Package object
 * 
 * @param _recipient 
 * @param _sender 
 * @param weight 
 * @param costPerOunce 
 */
Package::Package(Address & _recipient, Address & _sender, int weight, float costPerOunce) :
    recipient{_recipient},
    sender{_sender} {
        setWeight(weight);
        setCost(costPerOunce);
}

/**
 * @brief Set the weight of the package in ounces
 * 
 * @param _weight 
 */
void Package::setWeight(int _weight) {
    if (_weight <= 0)
        throw std::invalid_argument("invalid weight");
    weight = _weight;
}

/**
 * @brief Set the cost per ounce
 * 
 * @param _costPerOunce 
 */
void Package::setCost(double _costPerOunce) {
    if (_costPerOunce <= 0.0)
        throw std::invalid_argument("invalid cost per ounce");
    costPerOunce = _costPerOunce;
}

/**
 * @brief Calculate the cost of the package.
 * 
 * @return double 
 */
double Package::calculateCost() const {
    return weight * costPerOunce;
}

/**
 * @brief Output the package information
 * 
 * @return std::string 
 */
std::string Package::toString() const {
    std::ostringstream output;
    output << std::fixed << std::setprecision(2);
    output << "TO:\n" << sender << "\n";
    output << "FROM:\n" << recipient << "\n";
    output << "Weight: " << weight << " oz\n";
    output << "Cost: " << calculateCost();

    return output.str();
}