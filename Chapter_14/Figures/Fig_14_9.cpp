/**
 * @file Fig_14_9.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief ClientData member definitions
 * @version 0.1
 * @date 2020-09-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <string>
#include "ClientData.h"

// default ClientData constructor
ClientData::ClientData(int accountNumberValue, const std::string& lastName,
    const std::string& firstName, double balanceValue) 
    : accountNumber(accountNumberValue), balance(balanceValue) {
        setLastName(lastName);
        setFirstName(firstName);
}

// get account-number value
int ClientData::getAccountNumber() const { return accountNumber; }

// set account-number value
void ClientData::setAccountNumber(int accountNumberValue) {
    accountNumber = accountNumberValue;
}

// get last-name value
std::string ClientData::getLastName() const { return lastName; }

// set last-name value
void ClientData::setLastName(const std::string& lastNameString) {
    size_t length{lastNameString.size()};
    length = (length < 15 ? length : 14);
    lastNameString.copy(lastName, length);
    lastName[length] = '\0';
}

// get first-name value
std::string ClientData::getFirstName() const { return firstName; }

// set first-name value
void ClientData::setFirstName(const std::string& firstNameString) {
    int length{firstNameString.length()};
    length = (length < 10 ? length : 9);
    firstNameString.copy(firstName, length);
    firstName[length] = '\0';
}

// get balance value
double ClientData::getBalance() const { return balance; }

// set balance value
void ClientData::setBalance(double balanceValue) { balance = balanceValue; }