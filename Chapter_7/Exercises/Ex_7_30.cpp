/**
 * Exercise 7-30 Print an array
 *
 * Write a recursive function printArray that takes an array, a starting subscript
 * and an ending subscript as arguments, returns nothing and prints the array. The
 * function should stop processing and return when the starting subscript equals
 * the ending subcript.
 *
 */

#include <iostream>
#include <array>
#include <Ex_7_30.h>

/**
 * Recursively prints the elements of an array in reverse.
 *
 * @param arr     Example array type with 10 integers
 * @param b_index Beginning index of the array
 * @param e_index Ending index of the array
 * @return void
 */
void printArray(example_array& arr, size_t b_index, size_t e_index) {
    /* empty array */
    if (arr.size() == 0)
        return;

    if (b_index < e_index)
        printArray(arr, b_index+1, e_index);
    std::cout << arr[b_index] << " ";
}
