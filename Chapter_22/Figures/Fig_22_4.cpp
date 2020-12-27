/**
 * @file Fig22_04.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Card shuffling and dealing program.
 * @version 0.1
 * @date 2020-12-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "DeckOfCards.h"

int main() {
    DeckOfCards deckOfCards;
    deckOfCards.Deal();
    deckOfCards.Shuffle();
    deckOfCards.Deal();
}