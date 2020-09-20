/**
 * @file ClientData.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Class ClientData definition
 * @version 0.1
 * @date 2020-09-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef CLIENTDATA_H
#define CLIENTDATA_H

#include <string>

constexpr int8_t NUM_RECORDS{10};
constexpr size_t MAX_FIRST_NAME_LENGTH{10};
constexpr size_t MAX_LAST_NAME_LENGTH{15};
class ClientData {

    public:

        // default ClientData constructor
        ClientData(int accountNumberValue=0, const std::string& lastName="",
            const std::string& firstName="", double balanceValue=0.0) 
            : accountNumber(accountNumberValue), balance(balanceValue) {
                setLastName(lastName);
                setFirstName(firstName);
        }

        // get account-number value
        int getAccountNumber() const { return accountNumber; }

        // set account-number value
        void setAccountNumber(int accountNumberValue) {
            accountNumber = accountNumberValue;
        }

        // get last-name value
        std::string getLastName() const { return lastName; }

        // set last-name value
        void setLastName(const std::string& lastNameString) {
            size_t length{lastNameString.size()};
            length = (length < MAX_LAST_NAME_LENGTH ? length : MAX_LAST_NAME_LENGTH - 1);
            lastNameString.copy(lastName, length);
            lastName[length] = '\0';
        }

        // get first-name value
        std::string getFirstName() const { return firstName; }

        // set first-name value
        void setFirstName(const std::string& firstNameString) {
            size_t length{firstNameString.length()};
            length = (length < MAX_FIRST_NAME_LENGTH ? length : MAX_FIRST_NAME_LENGTH - 1);
            firstNameString.copy(firstName, length);
            firstName[length] = '\0';
        }

        // get balance value
        double getBalance() const { return balance; }

        // set balance value
        void setBalance(double balanceValue) { balance = balanceValue; }
    
    private:
        int accountNumber;
        char lastName[15];
        char firstName[10];
        double balance;
};

#endif /* CLIENTDATA_H */