/**
 * @file Fig_13_1.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Printing the address stored in a char * variable
 * @version 0.1
 * @date 2020-07-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>

int main() {

    const char *const word{"again"};

    /* display the value of char* variable word, then display the value of word
       after after a static_cast to void * */
    std::cout << "Value of word is: " << word
        << "\nValue of static_cast<const void *>(word) is: "
        << static_cast<const void *>(word) << std::endl;

    return EXIT_SUCCESS;
}