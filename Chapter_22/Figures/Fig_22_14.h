/**
 * @file Fig_22_14.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Definition of DeckOfCards using bit fields
 * @version 0.1
 * @date 2020-12-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef _FIG_22_4_INCLUDE_
    #define _FIG_22_4_INCLUDE_

#include <array>

/**
 * @brief Bit field representing a playing card
 * 
 */
struct Card {
    unsigned face : 4; // 4 bits: 0-15
    unsigned suit : 2; // 2 bits: 0-3
    unsigned color : 1; // 1 bit: 0-1
};

/**
 * @brief Class representing a deck of cards
 * 
 */
class DeckOfCards {

    public:
        /**
         * @brief Construct a new Deck Of Cards object
         * 
         */
        DeckOfCards();

        /**
         * @brief Shuffle the deck of cards
         * 
         */
        void Shuffle();

        /**
         * @brief Deal the deck of cards
         * 
         */
        void Deal() const;

    private:
        static const int faces{13};
        static const int colors{2};
        static const int numberOfCards{52};
        std::array<Card, numberOfCards> deck;
};

#endif // _FIG_22_4_INCLUDE_