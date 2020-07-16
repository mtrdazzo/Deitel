/**
 * @file Ex_12_12.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Package class hierarchy definition
 * 
 * Exercise 12-12 Package Inheritance Hierarchy
 * 
 * Use the package inheritance hierarchy created in Exercise 11.9 to create a program that displays the
 * address information and calculates the shipping costs for several Packages. The program should contain
 * a vector of Package pointers to objects of classes TwoDayPackages and OvernightPackage. Loop through the
 * vector to process the Packages polymorphically. For each Package, invoke get functions to obtain the
 * address information of the sender and the recipient, then print the two addresses as they would appear on
 * mailing labels. Also, call each Package's calculateCost member function and print the result. Keep track of the
 * total shipping cost for all Packages in the vector, and display this total when the loop terminates.
 * 
 * @version 0.1
 * @date 2020-07-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef EX_12_12_H
#define EX_12_12_H

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
         * @brief Destroy the Package object
         * 
         */
        virtual ~Package() = default;

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
        virtual double calculateCost() const;

        /**
         * @brief Output the package information
         * 
         * @return std::string 
         */
        virtual std::string toString() const;

    private:
        Address recipient;
        Address sender;
        int weight;        /* weight in ounces */
        double costPerOunce;
};

class TwoDayPackage : public Package {

    friend std::ostream& operator<<(std::ostream&, const TwoDayPackage &);

    public:

        /**
         * @brief Construct a new Two Day Package object
         * 
         */
        TwoDayPackage(Address &, Address &, int, float, float);

        /**
         * @brief Destroy the Two Day Package object
         * 
         */
        virtual ~TwoDayPackage() = default;

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
        virtual std::string toString() const override;

        /**
         * @brief Calculate the cost of the package
         * 
         * @return double 
         */
        virtual double calculateCost() const override {
            return Package::calculateCost() + flatFee;
        }

    private:
        double flatFee;

};

class OvernightPackage : public Package {

    friend std::ostream& operator<<(std::ostream&, const OvernightPackage &);

    public:

        /**
         * @brief Construct a new OvernightPackage object
         * 
         */
        OvernightPackage(Address &, Address &, int, float, float);

        /**
         * @brief Destroy the Overnight Package object
         * 
         */
        virtual ~OvernightPackage() = default;

        /**
         * @brief Set the Overnight Fee
         * 
         */
        void setOvernightFee(double);

        /**
         * @brief Get the Overnight Fee
         * 
         * @return double 
         */
        double getOvernightFee() const {
            return overnightFee;
        }

        /**
         * @brief Output the package information
         * 
         * @return std::string 
         */
        virtual std::string toString() const;

        /**
         * @brief Calculate the cost of the package
         * 
         * @return double 
         */
        virtual double calculateCost() const {
            return Package::calculateCost() + overnightFee * getWeight();
        }

    private:
        double overnightFee;

};

#endif