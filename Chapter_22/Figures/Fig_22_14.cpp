/**
 * @file Fig_22_14.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief DeckOfCards member function definitions
 * @version 0.1
 * @date 2020-12-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <iomanip>

#include "Fig_22_14.h"

int main(void) {

    DeckOfCards deckOfCards;
    deckOfCards.Deal();

    return EXIT_SUCCESS;
}

/**
 * @brief Construct a new Deck Of Cards:: Deck Of Cards object
 * 
 */
DeckOfCards::DeckOfCards() {
    for (size_t index{0}; index < deck.size(); ++index) {
        deck.at(index).face = index % faces;
        deck.at(index).suit = index / faces;
        deck.at(index).color = index / (colors * faces);
    }
    srand(static_cast<size_t>(time(nullptr)));
}

/**
 * @brief Shuffle cards in the deck
 * 
 */
void DeckOfCards::Shuffle(void) {
    Card temp;
    size_t randIndex;
    for (size_t index{0}; index < deck.size(); ++index) {
        randIndex = rand() % deck.size();
        temp = deck.at(randIndex);
        deck.at(randIndex) = deck.at(index);
        deck.at(index) = temp;
    }
}

/**
 * @brief Deal the cards in the deck
 * 
 */
void DeckOfCards::Deal(void) const {

    for (size_t index1{0}, index2{index1 + deck.size() / 2}; index1 < deck.size() / 2 -1; ++index1, ++index2) {
        std::cout << "Card" << std::setw(3) << deck.at(index1).face
            << " Suit:" << std::setw(2) << deck.at(index1).suit
            << " Color: " << std::setw(2) << deck.at(index1).color
            << "  " << "Card:" << std::setw(3) << deck.at(index2).face
            << "  Suit:" << std::setw(2) << deck.at(index2).suit
            << "  Color:" << std::setw(2) << deck.at(index2).color << std::endl;
    }
}