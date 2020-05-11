/**
 * @file Ex_10_7.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Implementation of overloaded () operator for DoubleSubcriptedArray class
 * @version 0.1
 * @date 2020-05-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <new>
#include <Ex_10_7.h>

/**
 * @brief Construct a new Double Subscripted Array:: DoubleSubscripted Array object
 * 
 * @param row Number of rows in the array
 * @param col Number of columns in the array
 */
DoubleSubscriptedArray::DoubleSubscriptedArray(int row, int col) {

    if (row <= 0 || col <= 0)
        throw std::invalid_argument("row and column must be greater than 0");

    array = new (std::nothrow) int[row * col]{}; 

    if (array == nullptr) {
        std::cout << "Array could not be allocated" << std::endl;
        exit(EXIT_FAILURE);
    }
    else {
        this->row =row;
        this->col = col;
    }
}

/**
 * @brief Access the row and column of the array
 * 
 * @param row row index of the array
 * @param col column index of the array
 * @return int& reference to the row and column of the array
 */
int& DoubleSubscriptedArray::operator()(int row, int col) {
    if (row < 0 || static_cast<uint32_t>(row) >= this->row)
        throw std::invalid_argument("invalid row");
    else if (col < 0 || static_cast<uint32_t>(col) >= this->col)
        throw std::invalid_argument("invalid column");
    else {
        return *(array + (row * col));
    }
}

/**
 * @brief Return the value of at row and column of the array
 * 
 * @param row row index of the array
 * @param col column index of the array
 * @return int value of the row and column of the array
 */
int DoubleSubscriptedArray::operator()(int row, int col) const {
    if (row < 0 || static_cast<uint32_t>(row) >= this->row)
        throw std::invalid_argument("invalid row");
    else if (col < 0 || static_cast<uint32_t>(col) >= this->col)
        throw std::invalid_argument("invalid column");
    else {
        return *(array + (row * col));
    }
}