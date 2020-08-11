/**
 * @file Ex_13_17.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Statistics class definition
 * @version 0.1
 * @date 2020-08-09
 * 
 * Exercise 13-17 Computing descriptive statistics for a data set
 * 
 * Write a program that reads a sequence of numbers from the user into a vector and then calculates the mean, median,
 * standard deviation, minimum, maximum of the numbers. Consult a statistics book for formulas for mean, mode,
 * and standard deviation. The program should display the numbers in two digits of precision.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef EX_13_17_H
#define EX_13_17_H

#include <iostream>
#include <vector>

constexpr size_t MAX_INPUT_SIZE{100};
class Statistics {

    friend std::istream& operator>>(std::istream&, Statistics &);

    public:

        /**
         * @brief Construct a new Statistics object
         * 
         */
        Statistics() = default;

        /**
         * @brief Calculate the mean of the numbers
         * 
         * @return double 
         */
        double mean() const;

        /**
         * @brief Calculate the median of the numbers
         * 
         * @return double 
         */
        double median() const;

        /**
         * @brief Calculate the standard deviation of the numbers
         * 
         * @return double 
         */
        double standardDeviation() const;

        /**
         * @brief Return the minimum of the numbers
         * 
         * @return int 
         */
        int min() const;

        /**
         * @brief Return the maximum of the numbers
         * 
         * @return int 
         */
        int max() const;

    private:
        std::vector<int> numbers;

        bool _isEmpty() const { return !numbers.size(); }
        void _bubbleSort();
};

#endif /* EX_13_17_H */