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
#include <Ex_7_28.h>

/* isPalindrome: recursive solution to check if a string str is a palindrome */
bool isPalindrome(std::string &str, size_t b_index, size_t e_index) {

    /* Exit criteria */
    if (b_index > e_index)
        return true;
    else if (b_index == e_index)
        return tolower(str[b_index]) == tolower(str[e_index-1]);

    /* Skip through non alpha characters */
    while (!isalpha(str[b_index]) && b_index < e_index)
        ++b_index;
    while (!isalpha(str[e_index-1]) && e_index - 1 > 0)
        --e_index;

    /* Recursive call */
    if (tolower(str[b_index]) == tolower(str[e_index-1]))
        return isPalindrome(str, b_index+1, e_index-1);
    else
        return false;
}
