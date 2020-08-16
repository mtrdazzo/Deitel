/**
 * @file Ex_13_13.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-08-01
 * 
 * Exercise 13-13 Dealing with extra input characters
 * 
 * Write a program that asks a user for their first name, last name, and year of birth, one
 * after another in this order, and try to supply extra characters after you type the last
 * name. Can you explain what is going on here? Correct this problem by discarding all
 * characters up to the end of the line after you read the first name and last name.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef EX_13_13_H
#define EX_13_13_H

#include <string>

/**
 * @brief Function does not account for extra input characters after first and last name.
 * 
 * @return std::string ${firstName} ${lastName} ${birthYear}
 */
std::string uncorrectedInput(void);

/**
 * @brief Function takes accounts for extra input characters after first and last name.
 * 
 * @return std::string ${firstName} ${lastName} ${birthYear}
 */
std::string correctedInput(void);

#endif /* EX_13_13_H */
