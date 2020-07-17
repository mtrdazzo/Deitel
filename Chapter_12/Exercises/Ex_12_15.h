/**
 * @file Ex_12_15.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Class definitions for the CabonFootprint class hierarchy
 * @version 0.1
 * @date 2020-07-17
 * 
 * Exercise 12-15 CarbonFootprint Abstract Class: Polymorphism
 * 
 * Using an abstract class with only pure virtual functions, you can specify similar behaviors for possible disparate classes.
 * Governments and companies worldwide are becoming increasingly concerned with carbon footprints (annual releases of carbon
 * dioxide into the atmosphere) from buildings burning various types of fuels for heat, vehicles burning fuels for power, and
 * the like. Many scientist blame these greenhouse gases for the phenomenon called global warming. Create three small classes
 * unrelated by inheritance - classes Building, Car, and Bicycle. Give each class some unique appropriate attributes and behaviors
 * that it does not have in common with other classes. Write an abstract class CarbonFootprint with only a pure virtual getCarbonFootprint
 * member function. Have each of your classes inherit from that abstract class and implement the getCarbonFootprint member function
 * to calculate an appropriate cabon footprint for that class (check out a few websites that explain how to calculate carbon footprints).
 * Write an application that creates objects of each of the three classes, places pointers to those objects in a vector CarbonFootprint
 * pointers, then iterates through the vector, polymorphically invoking each object's getCarbonFootprint member function. For each
 * object, print some identifying information an dthe object's carbon footprint.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef EX_12_15_H
#define EX_12_15_H

#include <string>

namespace constants {
    extern double kgToLbs;
}

class CarbonFootprint {

    public:

        /**
         * @brief Get the Carbon Footprint in pounds of greenhouse gases
         * 
         * @return double 
         */
        virtual double getCarbonFootprint() const = 0;

};

class Building : public CarbonFootprint {

    public:

        /**
         * @brief Instantiate a new building
         * 
         */
        Building(double);

        /**
         * @brief Destroy the Building
         * 
         */
        ~Building() = default;

        /**
         * @brief Set the square footage of the building
         * 
         */
        void setSquareFeet(double);

        /**
         * @brief Get the square footage of the building
         * 
         * @return double square footage
         */
        double getSquareFeet() const { return squareFeet; }

        /**
         * @brief Get the Carbon Footprint of the building
         * 
         * @return double carbon footprint in lbs of greenhouse gases
         */
        virtual double getCarbonFootprint() const override;

        /**
         * @brief Get the Carbon Per Square Foot ratio
         * 
         * @return double 
         */
        static double getCarbonPerSquareFoot() { return carbonPerSquareFoot; }
    
    private:
        uint16_t squareFeet;
        static double carbonPerSquareFoot;
};

class Car : public CarbonFootprint {

    public:

        /**
         * @brief Instantiate a new car
         * 
         */
        Car(double, double);

        /**
         * @brief Destroy the Car object
         * 
         */
        ~Car() = default;

        /**
         * @brief Get the mpg of the vehicle
         * 
         * @return double mpg
         */
        double getMilesPerGallon() const { return milesPerGallon; }

        /**
         * @brief Set the mpg of the vehicle
         * 
         */
        void setMilesPerGallon(double);

        /**
         * @brief Get the miles driven in the vehicle
         * 
         * @return double miles driven
         */
        double getMilesDriven() const { return milesDriven; }

        /**
         * @brief Set the miles driven of the vehicle
         * 
         */
        void setMilesDriven(double);

        /**
         * @brief Get the Carbon Footprint of the vehicle
         * 
         * @return double carbon footprint in lbs of greenhouse gases
         */
        virtual double getCarbonFootprint() const override;

        /**
         * @brief Get the Gasoline Emissions Factor
         * 
         * @return double 
         */
        static double getGasolineEmissionsFactor() { return gasolineEmissionsFactor; }

    private:
        double milesPerGallon;
        double milesDriven;
        static double gasolineEmissionsFactor;
};

class Bicycle : public CarbonFootprint {

    public:

        /**
         * @brief Construct a new Bicycle
         * 
         */
        Bicycle(double);

        /**
         * @brief Destroy the Bicycle object
         * 
         */
        ~Bicycle() = default;

        /**
         * @brief Get the Cost of the bicycle
         * 
         * @return double 
         */
        double getCost() const { return cost; }

        /**
         * @brief Set the Cost of the bicycle
         * 
         */
        void setCost(double);

        /**
         * @brief Get the Carbon Footprint in pounds of greenhouse gases
         * 
         * @return double 
         */
        virtual double getCarbonFootprint() const override;

        /**
         * @brief Get the Pounds Per Greenhouse Per Dollar
         * 
         * @return double 
         */
        static double getPoundsPerGreenhousePerDollar() { return poundsGreenhousePerDollar; }

        /**
         * @brief Get the Profit Margin
         * 
         * @return double carbon footprint in lbs of greenhouse gases
         */
        static double getProfitMargin() { return profitMargin; }

    private:
        double cost;
        static double poundsGreenhousePerDollar;
        static double profitMargin;

};

#endif /* EX_12_15_H */