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
 * @brief Access the array at the specified row and column
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
 * @brief Return the value of the array at specified row and column
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

/**
 * @brief Equality operator, return true if internal data storages are the same length
 *        and contain the same data at each index.
 * 
 * @param other Other DoubleSubscriptedArray object
 * @return true 
 * @return false 
 */
bool DoubleSubscriptedArray::operator==(const DoubleSubscriptedArray& other) const {
    if (getSize() != other.getSize())
        return false;
    for (size_t index{0}; index < getSize(); index++)
        if (*(array + index) != *(other.array + index))
            return false;
    return true;
}

/**
 * @brief Inequality operator, return true if internal data storages are different length
 *        or do not contain the same data at each index.
 * 
 * @param other Other DoubleSubscriptedArray object
 * @return true 
 * @return false 
 */
bool DoubleSubscriptedArray::operator!=(const DoubleSubscriptedArray& other) const {
    return !(*this == other);
}

/**
 * @brief Copy the values of the elements of the other DoubleSubscriptedArray to this object.
 * 
 * @param other Other DoubleSubscriptedArray object
 */
void DoubleSubscriptedArray::operator=(const DoubleSubscriptedArray& other) {

    /* Call destructor explicitly */
    if (array != nullptr) {
        this->~DoubleSubscriptedArray();
    }

    array = new (std::nothrow) int[other.row * other.col]{}; 

    if (array == nullptr) {
        std::cout << "Array could not be allocated" << std::endl;
        exit(EXIT_FAILURE);
    }
    else {
        this->row = other.row;
        this->col = other.col;

        for (size_t index{0}; index < getSize(); index++)
            *(array + index) = *(other.array + index);
    }
}