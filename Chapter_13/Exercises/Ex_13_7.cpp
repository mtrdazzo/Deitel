/**
 * @file Ex_13_7.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-07-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "Ex_13_7.h"
#include <stdexcept>

/**
 * @brief Input value from input  stream
 * 
 * @param input Input stream
 * @param num Number object
 * @return std::istream& Input stream for cascading
 */
std::istream& operator>>(std::istream& input, Number & num) {

    char buffer[INPUT_MAX_LEN];
    input.get(buffer, INPUT_MAX_LEN);

    if (buffer[0] == '0') {
        if (input.gcount() > 1) {
            if (buffer[1] == 'x' || buffer[1] == 'X')
                num.hexToDec(buffer);
            else if (isdigit(buffer[1]))
                num.octToDec(buffer);
            else
                throw std::invalid_argument("invalid input for number representation");
        }
        else {
            num.value = 0;
        }
    }
    else {
        num.stringToDec(buffer);
    }

    return input;
}

/**
 * @brief Output the number to the stream in decimal format
 * 
 * @param output Output stream
 * @param num Number object
 * @return std::ostream& Output stream for cascading
 */
std::ostream& operator<<(std::ostream& output, const Number &num) {
    return output << num.value;
}

/**
 * @brief Convert hexadecimal representation to decimal
 * 
 * @param inputStr Character string
 */
void Number::hexToDec(const char *inputStr) {
    value = 0;
    for (const char *hexPtr{inputStr+2}; *hexPtr != '\0'; ++hexPtr) {
        value *= 16;
        if (isdigit(*hexPtr))
            value += *hexPtr - '0';
        else if (isalpha(*hexPtr) && *hexPtr >= 'a')
            value += *hexPtr - 'a' + 10;
        else if (isalpha(*hexPtr) && *hexPtr >= 'A')
            value += *hexPtr - 'A' + 10;
        else
            throw std::invalid_argument("invalid hex character");
    }
}

/**
 * @brief Convert octal representation to decimal
 * 
 * @param inputStr Character string
 */
void Number::octToDec(const char *inputStr) {
    value = 0;

    for (const char *octalPtr{inputStr+1}; *octalPtr != '\0'; ++octalPtr) {
        value *= 8;
        if (isdigit(*octalPtr))
            value += *octalPtr - '0';
        else
            throw std::invalid_argument("invalid octal character");
    }
}

/**
 * @brief Convert decimal representation to decimal
 * 
 * @param inputStr Character string
 */
void Number::stringToDec(const char *inputStr) {
    value = 0;

    for (const char *decPtr{inputStr}; *decPtr != '\0'; ++decPtr) {
        value *= 10;
        if (isdigit(*decPtr))
            value += *decPtr - '0';
        else
            throw std::invalid_argument("invalid decimal character");
    }
}

/**
 * @brief Get the Value object
 * 
 * @return int 
 */
int Number::getValue() const {
    return value;
}
