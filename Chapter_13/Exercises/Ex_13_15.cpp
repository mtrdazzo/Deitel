/**
 * @file Ex_13_15.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Point class method definitions
 * @version 0.1
 * @date 2020-08-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <limits>
#include <stdexcept>
#include <sstream>
#include "Ex_13_15.h"

/**
 * @brief Construct a new Point:: Point object
 * 
 * @param xCoordiante 
 * @param yCoordinate 
 */
Point::Point(int xCoordinate, int yCoordinate) {
    setXCoordinate(xCoordinate);
    setYCoordinate(yCoordinate);
}

/**
 * @brief Output Two dimensional point to stream
 * 
 * @param output Output stream
 * @param point  Point object
 * @return std::ostream& Output stream for cascading
 */
std::ostream& operator<<(std::ostream& output, const Point& point) {

    output << "xCoordinate: " << point.xCoordinate;
    output << "\nyCoordinate: " << point.yCoordinate;

    return output;
}

/**
 * @brief Input integers from stream to point
 * 
 * @param input Input stream
 * @param point Point object
 * @return std::istream& Input stream for cascading
 */
std::istream& operator>>(std::istream& input, Point & point) {

    static char inputArray[MAX_INPUT_LEN] = {0};
    bool isNegative{false};
    int index{0};
    long tempValue{0};

    input.getline(inputArray, MAX_INPUT_LEN);

    if (input.gcount() == 0) {
        throw std::invalid_argument("empty point");
    }

    if (inputArray[0] == '-') {
        isNegative = true;
        ++index;
    }

    for (int tempIndex{index}; isdigit(inputArray[tempIndex]); ++tempIndex, ++index) {
        tempValue = tempValue * 10 + inputArray[tempIndex] - '0';
    }

    if (isNegative)
        tempValue *= -1;

    if (tempValue < std::numeric_limits<int>::min())
        throw std::invalid_argument("value too small");
    else if (tempValue > std::numeric_limits<int>::max())
        throw std::invalid_argument("value too large");
    else {
        point.setXCoordinate(static_cast<int>(tempValue));
    }

    if (inputArray[index] != ' ')
        throw std::invalid_argument("invalid character");

    if (input.gcount() > index)
        while (inputArray[index] == ' ')
            ++index;

    if (inputArray[index] == '-') {
        isNegative = true;
        ++index;
    } else {
        isNegative = false;
    }

    if (inputArray[index] == '\0') {
        throw std::invalid_argument("no second value");
    }

    tempValue = 0;
    for (int tempIndex{index}; isdigit(inputArray[tempIndex]); ++tempIndex, ++index) {
        tempValue = tempValue * 10 + inputArray[tempIndex] - '0';
    }

    if (isNegative)
        tempValue *= -1;

    if (inputArray[index] != '\0')
        throw std::invalid_argument("invalid character");
    else if (tempValue < std::numeric_limits<int>::min())
        throw std::invalid_argument("value too small");
    else if (tempValue > std::numeric_limits<int>::max())
        throw std::invalid_argument("value too large");
    else
        point.setYCoordinate(static_cast<int>(tempValue));

    return input;
}

/**
 * @brief Return the string representation of the Point
 * 
 * @return std::string 
 */
std::string Point::toString() const {

    std::ostringstream output;

    output << *this;

    return output.str();
}