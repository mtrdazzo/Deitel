/**
 * @file Ex_13_17.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-08-09
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <limits>
#include <stdexcept>
#include <cmath>
#include "Ex_13_17.h"

/**
 * @brief Stream extraction operator to input values to integer vector
 * 
 * @param input Input stream
 * @param stats Statistics object
 * @return std::istream& Input stream for cascading calls
 */
std::istream& operator>>(std::istream& input, Statistics &stats) {

    char inputArray[100];
    long tempValue{0};
    bool numberStarted{false};
    bool isNegative{false};

    input.get(inputArray, 100, '\n');

    while (!stats._isEmpty())
        stats.numbers.pop_back();

    for (int index{0}; index < input.gcount(); ++index) {
        if (inputArray[index] == ' ') {
            if (numberStarted) {
                if (isNegative)
                    tempValue *= -1;
                stats.numbers.push_back(tempValue);
                tempValue = 0;
                numberStarted = false;
                isNegative = false;
            }
        }
        else if (isdigit(inputArray[index])) {
            if (!numberStarted)
                numberStarted = true;
            tempValue *= 10;
            tempValue += inputArray[index] - '0';

            if (!isNegative && tempValue > std::numeric_limits<int>::max())
                throw std::invalid_argument("value too large");
            else if (isNegative && tempValue * -1 < std::numeric_limits<int>::min())
                throw std::invalid_argument("value too small");
        }
        else if (inputArray[index] == '-') {
            if (!isNegative) {
                isNegative = true;
            }
            else
            {
                throw std::invalid_argument("invalid symbol");
            }
        }
        else {
            throw std::invalid_argument("invalid character");
        }
    }

    if (numberStarted) {
        if (!isNegative) {
            if ( tempValue > std::numeric_limits<int>::max())
                throw std::invalid_argument("value too large");
        }
        else {
            tempValue *= -1;
            if (tempValue < std::numeric_limits<int>::min())
                throw std::invalid_argument("value too small");
        }
        stats.numbers.push_back(tempValue);
    }

    stats._bubbleSort();

    return input;
}

/**
 * @brief Get the minimum number in the vector
 * 
 * @return int 
 */
int Statistics::min() const {

    if (_isEmpty())
        throw std::invalid_argument("empty vector");
    else
    {
        return numbers.front();
    }
}

/**
 * @brief Get the maximum number in the vector
 * 
 * @return int 
 */
int Statistics::max() const {

    if (_isEmpty())
        throw std::invalid_argument("empty vector");
    else
        return numbers.back();
}

/**
 * @brief Return the mean of the number set in the vector
 * 
 * @return double 
 */
double Statistics::mean() const {

    if (_isEmpty())
        throw std::invalid_argument("empty vector");

    long total{0};

    for (auto number: numbers)
        total += number;
    
    return static_cast<double>(total) / numbers.size();
}

/**
 * @brief Calculate the median of the number set in the vector
 * 
 * @return double 
 */
double Statistics::median() const {

    if (_isEmpty())
        throw std::invalid_argument("empty vector");

    size_t numbersSize{numbers.size()};

    if (numbersSize % 2)
        return static_cast<double>(numbers[numbersSize / 2 ]);
    else
    {
        return static_cast<double>(numbers[numbersSize / 2] + numbers[numbersSize / 2 - 1]) / 2;
    }
}

/**
 * @brief 
 * 
 */
void Statistics::_bubbleSort() {

    int temp;
    for (size_t index{0}; index < numbers.size() - 1; ++index) {
        for (size_t index_other{0}; index_other < (numbers.size() - 1 - index); ++index_other) {
            if (numbers[index_other] > numbers[index_other + 1]) {
                temp = numbers[index_other];
                numbers[index_other] = numbers[index_other + 1];
                numbers[index_other + 1] = temp;
            }
        }
    }
}

/**
 * @brief Calculate the standard deviation of the set of numbers
 * 
 * @return double 
 */
double Statistics::standardDeviation() const {

    if (_isEmpty())
        throw std::invalid_argument("empty vector");
    else if (numbers.size() == 1)
        return 0.0;

    double mean = this->mean();
    double differences{0};

    for (auto number : numbers)
        differences += (number - mean) * (number - mean);
    
    differences /= numbers.size() - 1;

    return std::sqrt(differences);
}