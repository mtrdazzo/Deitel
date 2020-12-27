/**
 * @file DeckOfCards.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Definition of class DeckOfCards that represents a deck of playing cards
 * @version 0.1
 * @date 2020-12-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef _DECK_OF_CARDS_INCLUDE
    #define _DECK_OF_CARDS_INCLUDE

#include <string>
#include <array>

/**
 * @brief Card structure definition
 * 
 */
struct Card {
    std::string face;
    std::string suit;
};

/**
 * @brief DeckOfCards class definition
 * 
 */
class DeckOfCards {

    public:
        static const int numberOfCards{52};
        static const int faces{13};
        static const int suits{4};

        /**
         * @brief Construct a new Deck Of Cards object, initializes deck
         * 
         */
        DeckOfCards();

        /**
         * @brief Shuffles cards in deck
         * 
         */
        void Shuffle();

        /**
         * @brief Deals cards in deck
         * 
         */
        void Deal() const;

    private:
        std::array<Card, numberOfCards> deck; // represents deck of cards
};

#endif // ! _DECK_OF_CARDS_INCLUDE