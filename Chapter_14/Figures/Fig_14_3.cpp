/**
 * @file Fig_14_3.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Credit inquiry program
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

enum class RequestType {
    ZERO_BALANCE = 1, CREDIT_BALANCE, DEBIT_BALANCE, END
};

RequestType getRequest();
bool shouldDisplay(RequestType, double);
void outputLine(int, const std::string&, double);

int main() {

    // ifstream constructor opens the file
    std::ifstream inClientFile{"clients.txt", std::ios::in};

    // exit program if ifstream could not open file
    if (!inClientFile) {
        std::cerr << "File could not be opened" << std::endl;
        exit(EXIT_FAILURE);
    }

    // get user's request (e.g., zero, credit or debit balance)
    RequestType request{getRequest()};

    // process user's request
    while (request != RequestType::END) {
        switch(request) {
            case RequestType::ZERO_BALANCE:
                std::cout << "\nAccounts with zero balances:\n";
                break;
            case RequestType::CREDIT_BALANCE:
                std::cout << "\nAccounts with credit balances:\n";
                break;
            case RequestType::DEBIT_BALANCE:
                std::cout << "\nAccounts with debit balances:\n";
                break;
            case RequestType::END:
                break;
        }

        int account; // the acocunt number
        std::string name; // the account owner's name
        double balance; // the account balance

        // read account, name and balance from file
        inClientFile >> account >> name >> balance;

        // display file contents (until eof)
        while (!inClientFile.eof()) {
            // display record
            if (shouldDisplay(request, balance)) {
                outputLine(account, name, balance);
            }

            // read account, name, and balance from file
            inClientFile >> account >> name >> balance;
        }

        inClientFile.clear(); // reset eof for next input
        inClientFile.seekg(0); // reposition to beginning of file
        request = getRequest(); // get additional request from user
    }

    std::cout << "End of run." << std::endl;

    return EXIT_SUCCESS;
}

// obtain request from user
RequestType getRequest() {

    // display request options
    std::cout << "\nEnter request\n"
        << " 1 - List accounts with zero balances\n"
        << " 2 - List accounts with credit balances\n"
        << " 3 - List accounts with debit balances\n"
        << " 4 - End of run" << std::fixed << std::showpoint;
    
    int type; // request from user

    do { // input user request
        std::cout << "\n?";
        std::cin >> type;
    } while (type < static_cast<int>(RequestType::ZERO_BALANCE) || type > static_cast<int>(RequestType::END));

    return static_cast<RequestType>(type);
}

// determine whether to display given record
bool shouldDisplay(RequestType type, double balance) {
    
    // determine whether to display zero balances
    if (type ==  RequestType::ZERO_BALANCE && balance == 0) {
        return true;
    }

    // determine whether to display credit balances
    if (type ==  RequestType::CREDIT_BALANCE && balance < 0) {
        return true;
    }

    // determine whether to display debit balances
    if (type ==  RequestType::DEBIT_BALANCE && balance > 0) {
        return true;
    }

    return false;
}

// display single record from file
void outputLine(int account, const std::string & name, double balance) {
    std::cout << std::left << std::setw(10) << account
        << std::setw(13) << name << std::setw(7) << std::setprecision(2)
        << std::right << balance << std::endl;
}