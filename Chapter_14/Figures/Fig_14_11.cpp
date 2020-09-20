/**
 * @file Fig_14_11.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Writing to random-access file
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

void outputLine(std::ostream&, const ClientData&);

int main(int argc, char **argv) {

    if (argc == 1)
        return EXIT_FAILURE;

    std::fstream outCredit{*++argv, std::ios::in | std::ios::out | std::ios::binary};

    // exit program if fstream cannot open file
    if (!outCredit) {
        std::cerr << "File could not be opened" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Enter account number (1 to 100, 0 to end input)\n? ";

    int accountNumber;
    std::string lastName;
    std::string firstName;
    double balance;

    std::cin >> accountNumber;

    // user enters information, which is copied into file
    while (accountNumber > 0 && accountNumber <= NUM_RECORDS) {
        // user enters last name, first name and balance
        std::cout << "Enter lastname, firstname and balance\n? ";
        std::cin >> lastName >> firstName >> balance;

        // create ClientData object
        ClientData client{accountNumber, lastName, firstName, balance};

        outCredit.seekp((client.getAccountNumber() - 1) * sizeof(ClientData));

        // write user-specified information in file
        outCredit.write(reinterpret_cast<const char *>(&client), sizeof(client));

        // enable user to enter another account
        std::cout << "Enter account number\n? ";
        std::cin >> accountNumber;
    }

    return EXIT_SUCCESS;
}
