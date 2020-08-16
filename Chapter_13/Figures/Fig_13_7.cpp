/**
 * @file Fig_13_7.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Controlling precision of floating-point values.
 * @version 0.1
 * @date 2020-07-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <iomanip>
#include <cmath>

int main() {

    double root2{std::sqrt(2.0)}; // calculate the square root of 2

    std::cout << "Square root of 2 with precisions 0-9.\n"
        << "Precision set by ostream member function precision:\n";
    std::cout << std::fixed; // use fixed-point notation

    // display square root using ostream function precision
    for (int places{0}; places <= 9; ++places) {
        std::cout.precision(places);
        std::cout << root2 << "\n";
    }

    std::cout << "\nPrecision set by stream manipulator setprecision:\n";

    // set precision for each digit, then display square root
    for (int places{0}; places < 10; ++places) {
        std::cout << std::setprecision(places) << root2 << "\n";
    }

    return EXIT_SUCCESS;
}