/**
 * @file Fig_14_2.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Reading and printing a sequential file
 * @version 0.1
 * @date 2020-08-17
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

void outputLine(int, const std::string&, double); // prototype

int main() {

    // ifstream constructor opens the file
    std::ifstream inClientFile{"clients.txt", std::ios::in};

    // exit program if ifstream could not open file
    if (!inClientFile) {
        std::cerr << "File could not be opened" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << std::left << std::setw(10) << "Account" << std::setw(13)
        << "Name" << "Balance\n" << std::fixed << std::showpoint;
    
    int account; // the account number
    std::string name; // the account owner's name
    double balance; // the account balance

    // display each record in file
    while (inClientFile >> account >> name >> balance) {
        outputLine(account, name, balance);
    }

    return EXIT_SUCCESS;
}

// display single record from file
void outputLine(int account, const std::string & name, double balance) {
    std::cout << std::left << std::setw(10) << account
        << std::setw(13) << name << std::setw(7) << std::setprecision(2)
        << std::right << balance << std::endl;
}