/**
 * @file Fig_22_25.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Using strtok
 * @version 0.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <cstring>

using namespace std;

int main(void) {

    char sentence[]{"This is a sentence with 7 tokens"};

    cout << "The string to be tokenized is: " << sentence
        << "\n\nThe tokens are:\n";
    
    char *tokenPtr{strtok(sentence, " ")};

    // continue tokenizing sentence until tokenPtr becomes NULL
    while (tokenPtr != NULL) {
        cout << tokenPtr << '\n';
        tokenPtr = strtok(NULL, " ");
    }

    cout << endl;

    return EXIT_SUCCESS;
}