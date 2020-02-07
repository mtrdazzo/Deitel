/**
 * @file Ex_9_25.h
 *
 * @brief
 *
 * @mainpage Exercise 9-25 Project: Card Shuffling and Dealing
 *
 * Use the functions from Exercise 9.24 to write a program that deals two five-card poker hands,
 * evauluates each hand and determines which is the better hand.
 *
 * @author Matt Randazzo
 */

#ifndef EX_9_25_H
#define EX_9_25_H

/* Includes */
#include <cstdint>
#include <cstddef>
#include <vector>    /* deck of cards */
#include <array>
#include <algorithm> /* for sort function */
#include <sstream>
#include <iostream>

#define WHAT
#define CARDS_IN_DECK 52
#define MAX_CARDS_HAND 5
#define MAX_PLAYERS 2 /* requirements for only two hands */

#define LOG(x) std::cout << x << std::endl; 

/**
 * Card Class
 *
 * @brief Contains a face and suit to represent a card in a deck.
 */
class Card {

    public:

        /* declarations for suits and faces strings */
        static const char *g_suits[];
        static const char *g_faces[];

        /**
         * All suits in the deck of cards
         */
        enum eSuits {
            eHEARTS = 0,
            eDIAMONDS,
            eSPADES,
            eCLUBS,
            eNumSuits
        };

        /**
         * All Card Faces for each suit
         */
        enum eFaces {
            eNone = 0,
            e2,
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

/* Comparator function for comparing card faces */
bool compByFace(Card *, Card *);

/**
 * PlayerHand
 * 
 * @brief A combination of five cards to represent a player's poker hand.
 *        The highest score is automatically calculated for the combination
 *        of cards (i.e., straight, flush, two-pair, etc.).
 */
class PlayerHand {

    public:

        PlayerHand() {};
        ~PlayerHand();

        /**
         * Score for the combinations of cards
         * 
         */
        enum eScore {
            NONE,
            PAIR,
            TWO_PAIR,
            THREE_OF_A_KIND,
            STRAIGHT,
            FLUSH,
            FULL_HOUSE,
            FOUR_OF_A_KIND,
            STRAIGHT_FLUSH,
            ROYAL_FLUSH
        };

        bool has_pair();
        bool has_two_pair();
        bool has_three_kind();
        bool has_four_kind();
        bool has_flush() const;
        bool has_royal_flush() const;
        bool has_straight() const;
        bool has_full_house() const;
        bool has_straight_flush() const;
        std::string toString() const;
        void acceptCard(Card *);

        eScore getScore() const { return m_eScore; }

        /* Return highest related in card combination i.e., pair, straight, etc. */
        Card::eFaces getHighestCard() const { return m_uiHighestCard; }

        /* Return highest face card in hand in case of tie */
        Card::eFaces getTieBreaker() const { return m_uiTieBreaker; }

    private:

        void calculateScore(); /* Calculate score */

        size_t m_uiNumCards{0}; /* Current number of cards in hand, maximum of MAX_CARDS_HAND */
        Card::eFaces m_uiHighestCard{Card::eNone}; /* Hightest card related to card combination */
        Card::eFaces m_uiTieBreaker{Card::eNone}; /* Tie breaker in case of tie of highest card */
        std::array<Card*, MAX_CARDS_HAND> m_pCards;
        eScore m_eScore{NONE}; /* Highest score in hand */
};

/**
 * DeckOfCards
 * 
 * @brief A deck of cards which can deal cards to players.
 */
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

/**
 * @brief Main driver of the Poker program. This class holds two player hands
 *        and compares the two scores.
 */
class PokerGame {

    public:

        /**
         * Players in Game
         */
        enum e_Player {
            NO_PLAYER,
            PLAYER_1,
            PLAYER_2
        };

        PokerGame() {};

        std::string toString() const;
        e_Player determineWinner() const;
        void addPlayer(PlayerHand *);
        void dealCards();

    private:

        DeckOfCards m_cDeck;
        uint8_t m_uiNumPlayers{0};
        std::array<PlayerHand *, MAX_PLAYERS> m_aPlayers;
};

#endif /* EX_9_25_H */