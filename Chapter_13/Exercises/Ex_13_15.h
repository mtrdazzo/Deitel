/**
 * @file Ex_13_15.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Point class definition
 * @version 0.1
 * @date 2020-08-01
 * 
 * Exercise 13-15 Point Class
 * 
 * Write a program that accomplishes each of the following:
 * 
 * a) Create a user-defined class Point that contains the private integer data members xCoordinate and yCoordinate
 *    and declares stream insertion and stream extraction overloaded operator functions as friends of the class.
 * 
 * b) Defined the stream insertion and stream extraction operator functions. The stream extraction operator function
 *    should determine whether the data entered is valid, and, if not, should set the failbit to indicate proper
 *    input. The stream insertion operator should not be able to display the point after an input error occured.
 * 
 * c) Write a main function that tests input and output of user-defined class Point, using the overloaded stream
 *    extraction adn stream insertion operators.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef EX_13_15_H
#define EX_13_15_H

#include <iostream>
#define MAX_INPUT_LEN 50

class Point {

    /* Stream insertion and extraction operators */
    friend std::ostream& operator<<(std::ostream&, const Point&);
    friend std::istream& operator>>(std::istream&, Point&);

    public:

        /**
         * @brief Construct a new Point object
         * 
         */
        Point(int = 0, int = 0);

        /**
         * @brief Return the X Coordinate
         * 
         * @return int 
         */
        int getXCoordinate() const { return xCoordinate; }

        /**
         * @brief Set the X Coordinate
         * 
         * @param xCoordinate 
         */
        void setXCoordinate(int xCoordinate) { this->xCoordinate = xCoordinate; }

        /**
         * @brief Return the Y Coordinate
         * 
         * @return int 
         */
        int getYCoordinate() const { return yCoordinate; }

        /**
         * @brief Set the Y Coordinate
         * 
         * @param yCoordinate 
         */
        void setYCoordinate(int yCoordinate) { this->yCoordinate = yCoordinate; }

        /**
         * @brief Return the string representation of the Point
         * 
         * @return std::string 
         */
        std::string toString() const;

    private:
        int xCoordinate;
        int yCoordinate;

};

#endif /* EX_13_15_H */