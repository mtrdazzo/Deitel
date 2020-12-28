/**
 * @file Fig_22_2.cpp
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Member-function definitions of DeckOfCards class
 * @version 0.1
 * @date 2020-12-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <iomanip>
#include <cstdlib> // prototypes for rand and srand
#include <ctime> // prototype for time

#include "Fig_22_2.h"

int main() {
    DeckOfCards deckOfCards;
    deckOfCards.Deal();
    deckOfCards.Shuffle();
    deckOfCards.Deal();
}

/**
 * @brief Construct a new Deck Of Cards:: Deck Of Cards object
 * 
 */
DeckOfCards::DeckOfCards() {

    static std::string suit[suits]{"Hearts", "Diamonds", "Clubs", "Spades"};

    static std::string face[faces]{"Ace", "Deuce", "Three", "Four", "Five", "Six",
                                    "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    for (size_t index{0}; index < deck.size(); ++index) {
        deck[index].face = face[index % faces];
        deck[index].suit = suit[index / faces];
    }

    srand(static_cast<size_t>(time(nullptr))); // seed
}

/**
 * @brief Shuffle cards in the deck
 * 
 */
void DeckOfCards::Shuffle() {
    size_t randIndex{0};
    for (size_t index{0}; index < deck.size(); ++index) {
        Card temp = deck.at(index);
        randIndex = rand() % deck.size();
        deck.at(index) = deck.at(randIndex);
        deck.at(randIndex) = temp;
    }
}

/**
 * @brief Display each card in the deck
 * 
 */
void DeckOfCards::Deal() const {
    Card tempCard;
    for (size_t index{0}; index < deck.size(); ++index) {
        tempCard = deck.at(index);
        std::cout << std::right << std::setw(5) << tempCard.face
        << " of " << std::left << std::setw(8) << tempCard.suit <<
        ((index + 1) % 2 ? '\t' : '\n');
    }
    std::cout << std::endl;
}