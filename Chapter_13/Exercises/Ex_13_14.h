/**
 * @file Ex_13_14.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-08-01
 * 
 * Exercise 13-14 Reading Phone Numbers with an Overloaded Stream Extraction Operator
 * 
 * Rewrite the stream extraction operator of the PhoneNumber class to perform the following error
 * checking on input. The operator >> function will need to reimplemented.
 * 
 * a) Input the entire phone number into an array. Test that the proper number of characters has been
 *    entered. There shoudl be a total of 14 characters read for a phone number of the form (800) 555-1212.
 *    Use istream member-function clear to set failbit for inproper input.
 * 
 * b) The area code and exchange do not begin with 0 or 1. Test the first digit of the area-code and exchange
 *    portions of the phone number to be sure that neither begins with 0 or 1. Use istream member-function clear
 *    to set  failbit for inproper input.
 * 
 * c) The middle digit of an area code used to be limited to 0 or 1. Test the middle digit for a value of 0 or 1.
 *    If none of the above operations  results in an error, copy the parts into the PhoneNumber object's areaCode,
 *    exchange, and line members.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef EX_13_14_H
#define EX_13_14_H

#include <iostream>
#include <string>

#define PHONENUMBER_LENGTH 20

class PhoneNumber {

    friend std::ostream& operator<<(std::ostream&, const PhoneNumber&);
    friend std::istream& operator>>(std::istream&, PhoneNumber&);

    private:

        std::string areaCode; // 3-digit
        std::string exchange; // 3-digit exchange
        std::string line;     // 4-digit lines

};

#endif /* EX_13_14_H */