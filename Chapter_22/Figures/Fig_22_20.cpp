/**
 * @file Fig_22_20.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Using functions isspace, iscntrl, ispunct, isprint, and isgraph.
 * @version 0.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <cctype>

using namespace std;

int main() {

    cout << "\nAccording to isspace:\nNewline "
        << (isspace('\n') ? "is a" : "is not a") << " whitespace character\nHorizontal tab "
        << (isspace('\t') ? "is a" : "is not a") << " whitespace character\n"
        << (isspace('%') ? "% is a" : "% is not a") << " whitespace character\n";

    cout << "\nAccording to iscntrl:\nNewline "
        << (iscntrl('\n') ? "is a" : "is not a") << " control character\n"
        << (iscntrl('$') ? "$ is a" : "$ is not a") << " control character\n";

    cout << "\nAccording to ispunct:\n"
        << (ispunct(';') ? "; is a" : "; is not a") << " punctuation character\n"
        << (ispunct('Y') ? "Y is a" : "Y is not a") << " punctuation character\n"
        << (ispunct('#') ? "# is a" : "# is not a") << " punctuation character\n";

    cout << "\nAccording to isprint:\n"
        << (isprint('$') ? "$ is a" : "$ is not a") << " printing character\nAlert "
        << (isprint('\a') ? "is a" : "is not a") << " printing character\nSpace "
        << (isprint(' ') ? "is a" : "is not a") << " printing character\n";

    cout << "\nAccording to isgraph:\n"
        << (isgraph('Q') ? "Q is a" : "Q is not a") << " printing character other than a space\nSpace "
        << (isgraph(' ') ? "is a" : "is not a") << " printing character other than a space\n";

    cout << endl;

    return EXIT_SUCCESS;
}