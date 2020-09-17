/**
 * @file Fig_14_1.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Creating a sequential file
 * @version 0.1
 * @date 2020-08-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <string>
#include <fstream> // contains file stream processing types
#include <cstdlib> // exit function prototype

int main() {

    std::ofstream outClientFile{"clients.txt", std::ios::app};

    // exit program if unable to create file
    if (!outClientFile) {
        std::cerr << "File could not be opened" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Enter the account, name, and balance.\n"
        << "Enter end-of-file to end input.\n?";
    
    int account; // the account number
    std::string name; // the account owner's name
    double balance; // the account balance

    // read account, name and balance from cin, then place in a file
    while (std::cin >> account >> name >> balance) {
        outClientFile << account << ' ' << name << ' ' << balance << std::endl;
        std::cout << "?";
    }

    return EXIT_SUCCESS;
}

