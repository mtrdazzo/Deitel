/* 
 * Exercise 7-28 Palindromic Sequences
 * 
 * A palindrome is a string that's spelled the same way forward and backward.
 * Examples of palindromes include "radar" and "Able was I ere I saw Elba." A
 * palindromic sentences is a palindrome if the punctuation marks and spaces
 * are ignored. Write a recursive function testPalindrome that returns true if
 * a string is a palindrome, and false otherwise. Ignore all spaces, commas,
 * full stops, and question marks in the sentence. Hence "red roses run no risk,
 * sir, on nurses order." is considered a palindrome. Note that like an array, the
 * square brackets ([]) operator can be used to iterate through the characters in
 * a string.
 * 
 */

#include <iostream>
#include <array>
using namespace std;

bool isPalindrome(string&, size_t, size_t);

int main(int argc, char **argv) {

    array<string, 7> palindrome_strings{ "",  /* empty string */
                                   "aa", /* single character string */
                                   "a",  /* even numbered character string */
                                   "radar", /* odd numbered character string */
                                   "Able was I ere I saw Elba.", /* palindrome with capitols */
                                   "red roses run no risk, sir, on nurses order." /* palindrome sentence with punctuation even */
                                   "red roses run no risk, sir, on nurses order." }; /* palindrome sentence with punctuation odd */

    array<string, 4> non_palindrome_strings{ "ab", /* even character string */
                                             "raars", /* odd numbered character string */
                                             "Able was I sere I saw Elba.", /* palindrome with capitols */
                                             "red roses run lno risk, sir, on nurses order."}; /* palindrome sentence with punctuation even */

    for (size_t index{0}; index < palindrome_strings.size(); index++)
        cout << isPalindrome(palindrome_strings[index], 0, palindrome_strings[index].size()) << endl;

    for (size_t index{0}; index < non_palindrome_strings.size(); index++)
        cout << isPalindrome(non_palindrome_strings[index], 0, non_palindrome_strings[index].size()) << endl;

    return EXIT_SUCCESS;
}

/* isPalindrome: recursive solution to check if a string str is a palindrome */
bool isPalindrome(string &str, size_t beg, size_t end) {
    
    /* Exit criteria */
    if (beg > end)
        return true;
    else if (beg == end)
        return tolower(str[beg]) == tolower(str[end-1]);

    /* Skip through non alpha characters */
    while (!isalpha(str[beg]) && beg < end)
        ++beg;
    while (!isalpha(str[end-1]) && end - 1 >= 0)
        --end;
    
    /* Recursive call */
    if (tolower(str[beg]) == tolower(str[end-1]))
        return isPalindrome(str, beg+1, end-1);
    else
        return false;
}