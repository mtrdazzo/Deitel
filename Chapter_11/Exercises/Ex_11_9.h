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
 * Base-class Package should include data members representing the name, address, city, state, and
 * ZIP code for both the sender and recipient of the package, in addition to members that store the
 * weight (in ounces) and cost per ounce to ship the package. Package's constructor shoudl intialize
 * these data members. Ensure that the weight and cost per ounce contain positive values. Package
 * should provide a public member function calculateCost that returns a double indicating the cost
 * associated with shipping the package. Package's calculateCost function should determine the cost
 * by multiplying the weight by the cost per ounce.
 * 
 * Derived-class TwoDayPackage should inherit the functionality of base-class Package, but also include
 * a data member that represents a flat fee that the shipping company charges for two-day-delivery
 * service. TwoDayPackage's constructor should receive a value to initialize this data member.
 * TwoDayPackage should redefine member function calculateCost so that it computes the shipping cost by
 * adding the flat fee to the weight-based cost calculated by base-class Package's calculateCost function.
 * 
 * Class OvernightPackage should inherit directly from class Package and contain an additional data member
 * representing an additional fee per ounce charged for overnight-delivery service. OvernightPackage
 * should redefine member function calculateCost so that it adds the additional fee per ounce to the
 * standard cost per ounce before calculating the shipping cost. Write a test program that creates objects
 * of each type of Package and tests member function calculateCost.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef EX_11_9_H
#define EX_11_9_H

#include <string>
#include <stdexcept>
#include <sstream>
#include <iostream>

class Address {

    friend std::ostream& operator<<(std::ostream&, const Address &);

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

    friend std::ostream& operator<<(std::ostream&, const Package &);

    public:
        /**
         * @brief Construct a new Package object
         * 
         */
        Package(Address &, Address &, int, float);

        /**
         * @brief Set the Weight in ounces
         * 
         */
        void setWeight(int);

        /**
         * @brief Get the Weight in ounces
         * 
         * @return int 
         */
        int getWeight() const {
            return weight;
        }

        /**
         * @brief Set the cost per ounce
         * 
         * @param cost 
         */
        void setCost(double cost);

        /**
         * @brief Get the cost per ounce
         * 
         * @return double 
         */
        double getCost() const {
            return costPerOunce;
        }

        /**
         * @brief Get the recipient
         * 
         */
        const Address & getRecipient() const {
            return recipient;
        }

        /**
         * @brief Get the sender
         * 
         */
        const Address & getSender() const {
            return sender;
        }

        /**
         * @brief Calculate the cost of the package
         * 
         * @return double 
         */
        double calculateCost() const;

        /**
         * @brief Output the package information
         * 
         * @return std::string 
         */
        std::string toString() const;

    private:
        Address recipient;
        Address sender;
        int weight;        /* weight in ounces */
        double costPerOunce;
};

class TwoDayPackage : public Package {

    friend std::ostream& operator<<(std::ostream&, const Package &);

    public:

        /**
         * @brief Construct a new Two Day Package object
         * 
         */
        TwoDayPackage(Address &, Address &, int, float, float);

        /**
         * @brief Set the Flat Fee
         * 
         */
        void setFlatFee(double);

        /**
         * @brief Get the Flat Fee
         * 
         * @return double 
         */
        double getFlatFee() const {
            return flatFee;
        }

        /**
         * @brief Output the package information
         * 
         * @return std::string 
         */
        std::string toString() const;

        /**
         * @brief Calculate the cost of the package
         * 
         * @return double 
         */
        double calculateCost() const {
            return Package::calculateCost() + flatFee;
        }

    private:
        double flatFee;

};

class OvernightPackage : public Package {

};

#endif