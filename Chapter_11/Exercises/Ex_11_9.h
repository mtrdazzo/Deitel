/**
 * @file Ex_11_9.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Shapes Hierarchy class definitions
 * @version 0.1
 * @date 2020-07-08
 * 
 * Exercise 11-9 Richer Shape Hierarchy
 * 
 * Create an inheritance hierarchy for different types of packages. Use class Package as the base
 * class of the hierarchy, then include TwoDayPackage and OvernightPackage the derive from Package.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef EX_11_9_H
#define EX_11_9_H

#include <string>
#include <stdexcept>
#include <sstream>

class Address {

    public:
        /**
         * @brief Construct a new Address object
         * 
         */
        Address(std::string, int, std::string, std::string, std::string, int);

        /**
         * @brief Set the Person Name
         * 
         * @param name 
         */
        void setPersonName(std::string name) {
            if (name.length() == 0)
                throw std::invalid_argument("invalid name");
            personName = name;
        }

        /**
         * @brief Get the Person Name
         * 
         * @return std::string 
         */
        std::string getPersonName() const {
            return personName;
        }

        /**
         * @brief Set the Street Number
         * 
         * @param number 
         */
        void setStreetNumber(int number) {
            if (number <= 0)
                throw std::invalid_argument("invalid street number");
            streetNumber = number;
        }

        /**
         * @brief Get the Street Number
         * 
         * @return uint16_t 
         */
        uint16_t getStreetNumber() const {
            return streetNumber;
        }

        /**
         * @brief Get the Street Name
         * 
         * @return std::string 
         */
        std::string getStreetName() const {
            return streetName;
        }

        /**
         * @brief Set the Street Name
         * 
         * @param number 
         */
        void setStreetName(std::string name) {
            if (name.length() == 0)
                throw std::invalid_argument("invalid street name");
            streetName = name;
        }

        /**
         * @brief Get the City Name
         * 
         * @return std::string 
         */
        std::string getCityName() const {
            return cityName;
        }

        /**
         * @brief Set the City Name
         * 
         * @param number 
         */
        void setCityName(std::string city) {
            if (city.length() == 0)
                throw std::invalid_argument("invalid city name");
            cityName = city;
        }

        /**
         * @brief Get the State Name
         * 
         * @return std::string 
         */
        std::string getStateName() const {
            return stateName;
        }

        /**
         * @brief Set the City Name
         * 
         * @param number 
         */
        void setStateName(std::string state) {
            if (state.length() == 0)
                throw std::invalid_argument("invalid state name");
            stateName = state;
        }

        /**
         * @brief Set the zip code
         * 
         * @param number 
         */
        void setZipCode(int zip) {
            if (zip <= 0)
                throw std::invalid_argument("invalid zip code");
            zipCode = zip;
        }

        /**
         * @brief Get the zip code
         * 
         * @return int 
         */
        int getZipCode() const {
            return zipCode;
        }

        /**
         * @brief Produce the string representation of the address
         * 
         * @return std::string 
         */
        std::string toString() const;

    private:
        std::string personName;
        int streetNumber;
        std::string streetName;
        std::string cityName;
        std::string stateName;
        int zipCode;
};

class Package {

};

class TwoDayPackage : public Package {

};

class OvernightPackage : public Package {

};

#endif