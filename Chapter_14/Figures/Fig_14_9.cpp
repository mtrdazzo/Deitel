/**
 * @file Fig_14_10.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Creating a randomly accessed file
 * @version 0.1
 * @date 2020-09-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "ClientData.h"

int main() {

    std::ofstream outCredit{"credit.dat", std::ios::out | std::ios::binary};

    if (!outCredit) {
        std::cerr << "File could not be opened" << std::endl;
        exit(EXIT_FAILURE);
    }

    ClientData blankClient; // constructor zeroes out each member

    for (int i{0}; i < 100; ++i) {
        outCredit.write(reinterpret_cast<const char *>(&blankClient), sizeof(blankClient));
    }
}