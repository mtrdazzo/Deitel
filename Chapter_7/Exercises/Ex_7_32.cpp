/*
 * Exercise 7-32 Find the Maximum Value in an array
 *
 * Write a recursive function recursiveMaximum that takes an integer array, a
 * starting subscript and an ending subscript as arguments, and returns the
 * largest element of the array. The funtion shold stop processing and return
 * when the starting subscript equals the ending subscript.
 *
 */

#include <iostream>
#include "Ex_7_32.h"

/**
 * Return the maximum value in an array. (Recursive edition)
 *
 * @param arr Input array of integers
 * @param s   Starting subscript of the array
 * @param t   Ending subscript of the array
 * @return void
 */
template<std::size_t SIZE>
int32_t recursiveMaximum(std::array<int, SIZE>& arr, size_t s, size_t t) {

    /* Invalid input indices */
    if (s > t || s > arr.size() || t > arr.size())
        throw;

    if (s < t)
        return std::max(arr[s], recursiveMaximum(arr, s+1, t));
    else
        return arr[t];
}