/**
 * @file Fig_14_12.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Reading a random-access file
 * @version 0.1
 * @date 2020-09-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "ClientData.h"

void outputLine(std::ostream&, const ClientData&);

int main(int argc, char **argv) {

    if (argc == 1)
        return EXIT_FAILURE;

    std::fstream inCredit{*++argv, std::ios::in | std::ios::binary};

    if (!inCredit) {
        std::cerr << "File could not be opened." << std::endl;
        exit(EXIT_FAILURE);
    }

    // output column heads
    std::cout << std::left << std::setw(10) << "Account" << std::setw(16) << "Last Name"
        << std::setw(11) << "First Name" << std::setw(10) << std::right << "Balance\n";
    
    ClientData client; // create record

    // read first record from file
    inCredit.read(reinterpret_cast<char*>(&client), sizeof(ClientData));

    // read all records from file
    while (inCredit) {
        // display record
        if (client.getAccountNumber() != 0) {
            outputLine(std::cout, client);
        }

        // read next from file
        inCredit.read(reinterpret_cast<char*>(&client), sizeof(ClientData));
    }

    return EXIT_SUCCESS;
}

void outputLine(std::ostream& output, const ClientData& record) {
    output << std::left << std::setw(10) << record.getAccountNumber()
        << std::setw(MAX_LAST_NAME_LENGTH) << record.getLastName()
        << std::setw(MAX_FIRST_NAME_LENGTH) << record.getFirstName()
        << std::setw(10) << std::setprecision(2) << std::right << std::fixed
        << std::showpoint << record.getBalance() << std::endl;
}