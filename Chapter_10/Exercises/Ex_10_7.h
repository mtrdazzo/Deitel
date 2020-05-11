/**
 * @file Ex_10_7.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Interface for DoubleScriptedArray class
 * 
 * Exercise 10-7 Overloading the Parentheses Operator
 * 
 * One nice example of overloading the function call operator () is to allow another form of
 * double-array subscripting popular in some programming languages. Instead of saying
 * chessBoard[row][column] 
 * for an array of objects, overload the function call operator to allow the alternate form
 * chessBoard(row, column)
 * Create a class DoubleSubscriptedArray that has similar features to class Array in Fig. 10.10-10.11.
 * At construction time, the class should be able to create a DoubleSubscriptedArray of any number of
 * rows and columns. The class should supply operator() to perform double-subscripting operations.
 * For example, in a 3-by-5 DoubleSubscriptingArray called chessBoard, the user could write chessBoard(1,3)
 * to access the element at row 1 and column 3. Remember that operator() can receive any number of arguments.
 * The underlying representation of the DoubleSubscriptedArray could be a single-subscripted array of integers
 * with rows * columns number of elements. Function operator() should perform the proper pointer arithmetic
 * to access each element of the underlying array. There should be two versions of operator() - one that
 * returns int& (so that an element of a DoubleSubscriptArray can be used as an lvalue) and one that returns
 * int. The class should also provide the following operators: ==, !=, =, << (for outputting the DoubleScriptedArray)
 * in row and column (format) and >> (for inputting the entire DoubleSubscriptedArray contents.)
 * 
 * @version 0.1
 * @date 2020-05-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef EX_10_7_H
#define EX_10_7_H

#include <stdint.h>

class DoubleSubscriptedArray {

    public:

        /**
         * @brief Construct a new Double Subscripted Array object
         * 
         */
        DoubleSubscriptedArray(int, int);

        /**
         * @brief Destroy the Double Subscripted Array object
         * 
         */
        ~DoubleSubscriptedArray() {
            delete[] array;
        }

        /**
         * @brief Double scripted subscript operator for non-const objects, returns lvalue
         * 
         * @return int& 
         */
        int& operator()(int, int);

        /**
         * @brief Double scripted subscript operator for const objects, returns rvalue
         * 
         * @return int 
         */
        int operator()(int, int) const;

        /**
         * @brief Get the size of the array
         * 
         * @return uint32_t size of the array
         */
        uint32_t getSize() const { return row * col; }

    private:
        int   *array;
        uint32_t row;
        uint32_t col;
};

#endif 
