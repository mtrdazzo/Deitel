/**
 * @file Ex_13_18.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Function definitions for difference between get and getline
 * @version 0.1
 * @date 2020-08-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <sstream>
#include "Ex_13_18.h"

/**
 * @brief Stream extraction operator to show functionality of three argument get function
 * 
 * @param input Input stream
 * @param getExample GetCharactersFromGet object
 * @return std::istream& Input stream for cascading calls
 */
std::istream& operator>>(std::istream& input, GetCharactersFromGet & getExample) {
    input.get(getExample.buffer, MAX_BUFFER_SIZE, '\n');

    return input;
}

/**
 * @brief Stream extraction operator to show functionality of getline function
 * 
 * @param input Input stream
 * @param getExample GetCharactersFromGet object
 * @return std::istream& Input stream for cascading calls
 */
std::istream& operator>>(std::istream& input, GetCharactersFromGetline & getExample) {
    input.getline(getExample.buffer, MAX_BUFFER_SIZE);

    return input;
}

/**
 * @brief Get the Characters::to String object
 * 
 * @return std::string 
 */
std::string GetCharacters::toString() const {

    std::ostringstream output;
    output << buffer;

    return output.str();
}