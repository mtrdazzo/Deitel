/*
 * The Sieve of Eratosthenes
 *
 * A prime integer is any integer that's evenly divisible only by itself and 1. The Sieve of
 * Eratosthenes is a method of finding prime numbers. It operates as follows:
 *
 * a) Create an array with all elements initialized to 1 (true). array elements with prime
 *    subscripts will remain 1. All other array elements will eventually be set to zero. You'll
 *    ignore elements 0 and 1 in this exercise.
 *
 * b) Starting with array subscript 2, every time an array element is found whose value is 1,
 *    loop through the remainder of the array and set to zero every element whose subscript
 *    is a multipl eof the subscript for the element with value 1. For array subscript 2, all
 *    elements beyond 2 in the array that are multiples of 2 will be set to zero (subsripts 4,
 *    6, 8, 10, etc.); for array subsript 3, all elements beyond 3 in the array that are
 *    multiples of 3 will be set to zero (subscripts 6, 9, 12, 15, etc.) and so on.
 *
 * When this process is complete the array element that are still set to one indicate that the
 * subsript is a prime number. These can be printed. Write a program that uses an array of 1000
 * elements to determine and print the prime numbers between 2 and 999.
 *
 */

#include <iostream>
#include <array>

#define ARRAY_SIZE 1000

int main(void) {

    std::array<uint16_t, ARRAY_SIZE> prime_numbers{0};

    /* Set all elements in array to value of index */
    for(size_t index{0}; index < ARRAY_SIZE; index++)
        prime_numbers[index] = index;

    /* Iterate through array, set each element to zero if it can be evenly divided */
    for(size_t index1{2}; index1 < ARRAY_SIZE; index1++) {

        /* Skip previously found non-prime numbers */
        if (prime_numbers[index1] == 0)
            continue;
        for(size_t index2{index1+1}; index2 < ARRAY_SIZE; index2++) {
            /* Skip previously found non-prime numbers */
            if (prime_numbers[index2] != 0 && prime_numbers[index2] % prime_numbers[index1] == 0)
                prime_numbers[index2] = 0;
        }
    }

    /* Only print prime numbers */
    for(size_t index{0}; index < ARRAY_SIZE; index++)
        if (prime_numbers[index])
            std::cout << prime_numbers[index] << " ";
    std::cout << std::endl;

    return EXIT_SUCCESS;
}