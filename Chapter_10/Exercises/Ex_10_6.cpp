/**
 * @file Ex_10_6.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Memory Allocation and Deallocation Operators
 * 
 * How new and delete operators are used to allocate and deallocate memory dynamically to
 * built-in array of objects?
 * 
 * @version 0.1
 * @date 2020-05-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "Ex_10_6.h"

int allocateMemoryArray(const unsigned int size) {

    /* must use size defined before run time */
    int arrayOnStack[STACK_SIZE];

    /* dynamic allocation allows for size to be determined during run time */
    int *arrayOnHeap{new int[size]};

    /* free up heap space to prevent memory leaks */
    delete[] arrayOnHeap;

    /* for built in arrays, sizeof can determine size of array */
    return sizeof(arrayOnStack) / sizeof(arrayOnStack[0]);
}