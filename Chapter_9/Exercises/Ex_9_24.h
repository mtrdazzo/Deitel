/**
 * @file Ex_9_24.h
 *
 * @brief This file contains the class definitions for Card, DeckOfCards, and PlayerHand to
 *        deal a five-card poker hand.
 *
 * @mainpage Exercise 9-24 Card Shuffling and Dealing
 *
 * Modify the program you developed in Exercise 9.23 so that it deals a five-card poker hand.
 * Then write functions to accomplish the following:
 *
 * a) Determine whether the hand contains a pair
 * b) Determine whether the hand contains two pairs.
 * c) Determine whether the hand contains three of a kind (e.g., three jacks).
 * d) Determine whether the hand contains four of a kind (e.g., four aces).
 * e) Determine whether the hand contains a flush (i.e., all five cards of the same suit).
 * f) Determine whether the hand contains a straight (i.e., all five cards of consecutive face values).
 *
 * @author Matt Randazzo
 */

#ifndef EX_9_24_H
#define EX_9_24_H

/* Includes */
#include <cstdint>
#include <cstddef>
#include <vector>
#include <array>
#include <algorithm> /* for sort function */

#define CARDS_IN_DECK 52
#define CARDS_IN_HAND 5

class Card {

    public:

        /* declarations for suits and faces strings */
        static const char *g_suits[];
        static const char *g_faces[];

        /**
         * Suits of Cards Enum
         */
        enum eSuits {
            eHEARTS = 0,
            eDIAMONDS,
            eSPADES,
            eCLUBS,
            eNumSuits
        };

        /**
         * Card Faces Enum Values
         */
        enum eFaces {
            e2 = 0,
            e3,
            e4,
            e5,
            e6,
            e7,
            e8,
            e9,
            e10,
            eJack,
            eQueen,
            eKing,
            eAce,
            eNumFaces
        };

        /* Default Card constructor */
        explicit Card(eSuits suit, eFaces face) : m_ccpsuit{suit}, m_ccpface{face} {}

        std::string toString() const;
        eFaces getFace() const { return m_ccpface; }
        eSuits getSuit() const { return m_ccpsuit; }

    private:
        eSuits m_ccpsuit; /* Card suit */
        eFaces m_ccpface; /* Car Face 1,2,3...J,K,Q,A */
};

bool compByFace(Card *, Card *);

/**
 * Player Hand class
 * 
 * Cards of a player's hand and determines the poker score of the hand.
 */
class PlayerHand {

    public:

        PlayerHand() {};
        ~PlayerHand();

        bool has_pair() const;
        bool has_two_pair() const;
        bool has_three_kind() const;
        bool has_four_kind() const;
        bool has_flush() const;
        bool has_straight() const;
        std::string toString() const;
        void acceptCard(Card *);

    private:

        size_t numCards{0}; /* Current number of cards in hand, maximum of CARDS_IN_HAND */
        std::array<Card*, CARDS_IN_HAND> m_pCards;
};

class DeckOfCards {

    public:

        /* Constructor/Destructor */
        DeckOfCards(bool deckShuffle=true);

        ~DeckOfCards();

        std::string printDeck(void) const;

        void shuffle(void);

        Card *dealCard(void);

        size_t numCards(void) const { return m_pCDeck.size(); }

        bool moreCards(void) const { return numCards() != 0; }

        Card * topCard(void) const {
            return moreCards() ? m_pCDeck.back() : (Card *) nullptr;
        }

    private:
        std::vector<Card *> m_pCDeck; /* Deck of cards */
};

#endif /* EX_9_24_H */