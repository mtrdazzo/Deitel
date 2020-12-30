/**
 * @file Ex_22_12.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Determine the value
 * @version 0.1
 * @date 2020-12-30
 * 
 * Exercise 22-12 Determine the Value
 * 
 * The following program uses function multiple to determine whether the integer entered from the
 * keyboard is a multiple of some integer X. Examine function multiple, then determine the value of
 * X.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

bool multiple(int num) {

    bool mult{true};

    for (int i{0}, mask{1}; i < 10; ++i, mask <<= 1) {
        if ((num & mask) != 0) {
            mult = false;
            break;
        }
    }

    return mult;
}

