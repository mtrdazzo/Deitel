/**
 * @file Fig_13_16.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Floating point values displayed in system default, scientific, and fixed formats
 * @version 0.1
 * @date 2020-07-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */

 #include <iostream>

 int main() {

     double x{0.001234567};
     double y{1.946e9};

     // display x and y in default format
     std::cout << "Displayed in default format:\n" << x << '\t' << y;

     // display x and y in scientific format
     std::cout << "\n\nDisplayed in scientific format:\n"
        << std::scientific << x << '\t' << y;

    // display x and y in fixed format, default six decimal places`
    std::cout << "\n\nDisplayed in fixed format:\n"
        << std::fixed << x << '\t' << y << std::endl;

     return EXIT_SUCCESS;
 }