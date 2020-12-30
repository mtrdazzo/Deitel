/**
 * @file tst_Ex_22_5.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Card Shuffling and Dealing
 * @version 0.1
 * @date 2020-12-29
 * 
 * Exercise 22-5
 * 
 * Modify Fig 22.16 to shuffle the cards using the shuffle algorithm in Fig. 22.3. 
 * Print the resulting deck in two-column format. Precede card with its color.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <gtest/gtest.h>
#include "Ex_22_5.h"

TEST(DeckOfCards, ShuffleDeck) {
    DeckOfCards deck;
    deck.Shuffle();
    deck.Deal();
}