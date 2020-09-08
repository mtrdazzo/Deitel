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

class ClientData {

    public:
        ClientData(int = 0, const std::string& = "", const std::string& = "", double = 0.0);

        // accessor functions for accountNumber
        void setAccountNumber(int);
        int getAccountNumber() const;

        // accessor functions for lastName
        void setLastName(const std::string &);
        std::string getLastName() const;

        // accessor functions for firstName
        void setFirstName(const std::string &);
        std::string getFirstName() const;

        // accessor functions for balance
        void setBalance(double);
        double getBalance() const;
    
    private:
        int accountNumber;
        char lastName[15];
        char firstName[10];
        double balance;
};

#endif /* CLIENTDATA_H */