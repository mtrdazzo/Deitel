/**
 * @file Fig_13_9.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Creating and testing user-defined, nonparameterized stream manipulators
 * @version 0.1
 * @date 2020-07-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
using namespace std;

/* bell manipulator (using escape sequence \a) */
ostream& bell(ostream& output) {
    return output << '\a'; // issue system beep;
}

/* carriageReturn manipulator (using escape sequence \r) */
ostream& carriageReturn(ostream& output) {
    return output << '\r'; // issue carriage return
}

/* tab manipulator (using escape sequence \t) */
ostream& tab(ostream& output) {
    return output << '\t'; // issue tab
}

/* endline manipulator (using escape sequence\n and flush stream manipulator to simulate endl */
ostream& endLine(ostream& output) {
    return output << '\n' << flush; // issue endl-line end of line
}

int main() {

    cout << "Testing the tab manipulator:" << endLine
        << 'a' << tab << 'b' << tab << 'c' << endLine;

    cout << "Testing the carriageReturn and bell manipulators:"
        << endLine << "..........";

    cout << bell; // use bell manipulator

    // use carriageReturn and endLine manipulators
    cout << carriageReturn << "------" << endLine;

    return EXIT_SUCCESS;
}