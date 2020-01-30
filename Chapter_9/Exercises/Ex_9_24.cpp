/**
 * @file Ex_9_24.cpp
 *
 * @brief Implementation of member functions for the Card, DeckOfCards, and PlayerHand classes.
 *        These class implementations have the ability to deal a hand of cards and determine
 *        if the hand has a pair, two pairs, three of a kind, four of a kind, or a royal flush.
 *
 * @author Matt Randazzo
 */

/* Includes */
#include <Ex_9_24.h>
#include <sstream> /* for ostringstream */
#include <cstdlib> /* for rand() and srand() functions */
#include <ctime>   /* for time() function */

/* Strings for suits and faces */
const char *Card::g_faces[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
const char *Card::g_suits[] = {"Hearts", "Diamonds", "Spades", "Clubs"};

/**
 * @brief Comparator function to be used with the sort function compare the enumerated face value
 *        of two Cards objects.
 *
 * @param card1 Card which is to be compared.
 * @param card2 Card which is to be compared to card 1.
 * @return true if the face of card 1 is less than the face of card 2, otherwise false.
 */
bool compByFace(Card *card1, Card *card2) {
    return card1->getFace() < card2->getFace();
}

/**
 * @brief Returns the string representation of the Card.
 *
 * @return string representation of the card's face and value.
 */
std::string Card::toString() const {
    std::ostringstream output;
    output << g_faces[m_ccpface] << " of " << g_suits[m_ccpsuit];

    return output.str();
}

/**
 * @brief PlayerHand destructor, free all cards in the player's hand.
 */
PlayerHand::~PlayerHand() {
    for (auto card : m_pCards)
        delete card;
}

/**
 * @brief Returns the string representation of the player's hand.
 *
 * @return set of Card strings in the player's hand.
 */
std::string PlayerHand::toString() const {
    std::ostringstream output;
    for (size_t num{0}; num < numCards; ++num)
         output << m_pCards[num]->toString() << std::endl;
    return output.str();
}

/**
 * @brief Adds a card to the player's hand. A player can have a maximum of 5 cards
 *        in their hand at one time. Once the fifth card has been accepted, the
 *        cards are shuffled.
 *
 * @param newCard Card to be inserted into the player's hand.
 */
void PlayerHand::acceptCard(Card *newCard) {
    if (numCards < CARDS_IN_HAND)
        m_pCards[numCards++] = newCard;
    else
        throw std::invalid_argument("Cannot accept more than 5 cards");

    if (numCards == CARDS_IN_HAND)
        std::sort(m_pCards.begin(), m_pCards.end(), compByFace);
}

/**
 * @brief Determines if the player's hand contains five cards of the same suit, aka a Flush.
 *
 * @return true if the hand contains a flush, otherwise false.
 */
bool PlayerHand::has_flush() const {

    return (m_pCards[0]->getSuit() == m_pCards[1]->getSuit()) &&
           (m_pCards[2]->getSuit() == m_pCards[3]->getSuit()) &&
           (m_pCards[3]->getSuit() == m_pCards[4]->getSuit());
}

/**
 * @brief Determines if the player's hand contains at least one set of two cards with the
 *        same face of different suits (a pair).
 *
 * @return true if the hand contains a pair, otherwise false.
 */
bool PlayerHand::has_pair() const {

    for (auto it = m_pCards.begin(); it != m_pCards.end() - 1; ++it)
        if ((*it)->getFace() == (*(it + 1))->getFace())
            return true;
    return false;
}

/**
 * @brief Determines if the player's hand contains two sets of two cards with the same face
 *        of different suits (two pairs).
 *
 * @return true if the hand contains two pairs, otherwise false.
 */
bool PlayerHand::has_two_pair() const {

    for (auto it = m_pCards.begin(); it != m_pCards.end() - 3; ++it)
        if ((*it)->getFace() == (*(it + 1))->getFace()) {
            switch (m_pCards.end() - it) { /* can only occur if pair found in first three cards */
                case 4:
                    return (*(it + 2))->getFace() == (*(it + 3))->getFace() &&
                           (*(it + 2))->getFace() != (*it)->getFace();
                case 5:
                    return ((*(it + 2))->getFace() == (*(it + 3))->getFace() ||
                           (*(it + 3))->getFace() == (*(it + 4))->getFace()) &&
                           (*(it + 3))->getFace() != (*it)->getFace();
                default:
                    exit(1); /* something went wrong here */
            }
        }
    return false;
}

/**
 * @brief Determines if the player's hand contains at least three cards with the same face
 *        of different suits (three of a kind).
 *
 * @return true if the hand contains three of a kind, otherwise false.
 */
bool PlayerHand::has_three_kind() const {

    for (auto it = m_pCards.begin(); it != m_pCards.end() - 2; ++it)
        if ((*it)->getFace() == (*(it + 1))->getFace() &&
           (*(it + 1))->getFace() == (*(it + 2))->getFace())
            return true;
    return false;
}

/**
 * @brief Determines if the player's hand contains four cards with the same face (four of a kind).
 *
 * @return true if the hand contains four of a kind, otherwise false.
 */
bool PlayerHand::has_four_kind() const {

    for (auto it = m_pCards.begin(); it != m_pCards.end() - 3; ++it)
        if ((*it)->getFace() == (*(it + 1))->getFace() &&
           (*(it + 1))->getFace() == (*(it + 2))->getFace() &&
           (*(it + 2))->getFace() == (*(it + 3))->getFace())
            return true;
    return false;
}

/**
 * @brief Determines if the player's hand contains five cards in sequential numerical order (a straight).
 *
 * @return true if the hand contains a straight, otherwise false.
 */
bool PlayerHand::has_straight() const {

    for (auto it_beg = m_pCards.begin(), it_end = m_pCards.end()-1; it_beg != it_end; ++it_beg, --it_end)
        if (((*it_end)->getFace() != (*(it_end-1))->getFace() + 1) ||
            ((*it_beg)->getFace() != (*(it_beg+1))->getFace() - 1))
            return false;
    return true;
}

/**
 * @brief DeckOfCards default constructor.
 *
 * @param deckShuffle Set to set shuffle deck on instantiatio (true by default).
 */
DeckOfCards::DeckOfCards(bool deckShuffle) {

    for (int suitInt{Card::eSuits(0)}; suitInt < Card::eNumSuits; suitInt++) {
        Card::eSuits suit = static_cast<Card::eSuits>(suitInt);
        for (int faceInt{Card::eFaces(0)}; faceInt < Card::eFaces::eNumFaces; faceInt++) {
            Card::eFaces face = static_cast<Card::eFaces>(faceInt);
            m_pCDeck.push_back(new Card(suit, face));
        }
    }

    /* set random seed based on current time */
    srand(static_cast<unsigned int>(time(0)));

    if (deckShuffle)
        shuffle();
}

/**
 * @brief DeckOfCards deconstructor.
 *
 * @param deckShuffle Set to set shuffle deck on instantiatio (true by default).
 */
DeckOfCards::~DeckOfCards() {
    for (auto card : m_pCDeck)
        delete card;
}

/**
 * @brief A card is removed from the top of the card deck.
 *
 * @return Pointer to a card object if cards remain in deck, otherwise a pointer to NULL.
 */
Card *DeckOfCards::dealCard(void) {

    if (moreCards()) {
        Card * top_card = m_pCDeck.back();
        m_pCDeck.pop_back();
        return top_card;
    }
        return (Card *) nullptr;
}

/**
 * @brief Randomly shuffle the deck of cards.
 */
void DeckOfCards::shuffle(void) {

    size_t index2;
    Card *tmp;

    if (!numCards())
        return;

    for (size_t index1{0}; index1 < numCards(); index1++) {

        index2 = rand() % numCards();

        tmp = m_pCDeck[index1];
        m_pCDeck[index1] = m_pCDeck[index2];
        m_pCDeck[index2] = tmp;
    }
}

/**
 * @brief Print the entire deck of cards.
 */
std::string DeckOfCards::printDeck(void) const {
    std::ostringstream output;
    for (size_t index{0}; index < numCards(); index++)
        output << m_pCDeck[index]->toString() << std::endl;
    return output.str();
}
