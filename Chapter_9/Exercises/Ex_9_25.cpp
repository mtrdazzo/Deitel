/**
 * @file Ex_9_25.cpp
 *
 * @brief Improvement fo Implementation of member functions for the Card, DeckOfCards, PlayerHand,
 *        and PokerGame classes. These class implementations have the ability to deal two hands of
 *        cards and determine if the hand has a pair, two pairs, three of a kind, four of a kind,
 *        a straight flush, or a royal flush. The PokerGame class can also determine the winner
 *        between the two hands.
 *
 * @author Matt Randazzo
 */

/* Includes */
#include <Ex_9_25.h>
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
    if (m_uiNumCards)
        for (size_t index{0}; index < m_uiNumCards; ++index)        
            delete m_pCards[index];
}

/**
 * @brief Returns the string representation of the player's hand.
 *
 * @return set of Card strings in the player's hand.
 */
std::string PlayerHand::toString() const {
    std::ostringstream output;
    for (size_t num{0}; num < m_uiNumCards; ++num)
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
    if (m_uiNumCards < MAX_CARDS_HAND)
        m_pCards[m_uiNumCards++] = newCard;
    else
        throw std::invalid_argument("Cannot accept more than 5 cards");

    if (m_uiNumCards == MAX_CARDS_HAND) {
        std::sort(m_pCards.begin(), m_pCards.end(), compByFace);
        calculateScore();
    }
}

/**
 * @brief Determines if the player's hand contains all five cards with the same suit (flush).
 *
 * @return true if the hand contains a flush, otherwise false.
 */
bool PlayerHand::has_flush() const {

    return (m_pCards[0]->getSuit() == m_pCards[1]->getSuit()) &&
           (m_pCards[1]->getSuit() == m_pCards[2]->getSuit()) &&
           (m_pCards[2]->getSuit() == m_pCards[3]->getSuit()) &&
           (m_pCards[3]->getSuit() == m_pCards[4]->getSuit());
}

/**
 * @brief Determines if the player's hand contains a full house (one pair, one three of a kind)
 *
 * @return true if the hand contains a full house, otherwise false.
 */
bool PlayerHand::has_full_house() const {

    return ((m_pCards[0]->getFace() == m_pCards[1]->getFace()) &&
           (m_pCards[1]->getFace() == m_pCards[2]->getFace()) &&
           (m_pCards[3]->getFace() == m_pCards[4]->getFace())) ||
           ((m_pCards[0]->getFace() == m_pCards[1]->getFace()) &&
           (m_pCards[2]->getFace() == m_pCards[3]->getFace()) &&
           (m_pCards[3]->getFace() == m_pCards[4]->getFace()));
}

/**
 * @brief Determines if the player's hand contains a 10, J, Q, K, and Ace of the same suit, aka a Royal Flush.
 *
 * @return true if the hand contains a royal flush, otherwise false.
 */
bool PlayerHand::has_royal_flush() const {

    return (m_pCards[0]->getSuit() == m_pCards[1]->getSuit()) &&
           (m_pCards[2]->getSuit() == m_pCards[3]->getSuit()) &&
           (m_pCards[3]->getSuit() == m_pCards[4]->getSuit()) &&
           (m_pCards[0]->getFace() == Card::e10) &&
           (m_pCards[1]->getFace() == Card::eJack) &&
           (m_pCards[2]->getFace() == Card::eQueen) &&
           (m_pCards[3]->getFace() == Card::eKing) &&
           (m_pCards[4]->getFace() == Card::eAce);
}

/**
 * @brief Determines if the player's hand contains at least one set of two cards with the
 *        same face of different suits (a pair).
 *
 * @return true if the hand contains a pair, otherwise false.
 */
bool PlayerHand::has_pair() {

    for (auto it = m_pCards.begin(); it != m_pCards.end() - 1; ++it)
        if ((*it)->getFace() == (*(it + 1))->getFace()) {
            m_uiHighestCard = (*it)->getFace();

            if (it + 1 == m_pCards.end() - 1) {
                m_uiTieBreaker = (*(it - 1))->getFace();
            }
            else {
                m_uiTieBreaker = m_pCards[m_uiNumCards-1]->getFace();
            }
            return true;
        }

    m_uiTieBreaker = m_pCards[m_uiNumCards-1]->getFace();

    return false;
}

/**
 * @brief Determines if the player's hand contains two sets of two cards with the same face
 *        of different suits (two pairs).
 *
 * @return true if the hand contains two pairs, otherwise false.
 */
bool PlayerHand::has_two_pair() {

    for (auto it = m_pCards.begin(); it != m_pCards.end() - 3; ++it)
        if ((*it)->getFace() == (*(it + 1))->getFace()) {
            switch (m_pCards.end() - it) { /* can only occur if pair found in first three cards */
                case 4:
                    if ((*(it + 2))->getFace() == (*(it + 3))->getFace() &&
                       (*(it + 2))->getFace() != (*it)->getFace()) {
                        m_uiHighestCard = (*(it + 3))->getFace();
                        m_uiTieBreaker = m_pCards[0]->getFace();
                        return true;
                    }
                    else
                        return false;
                case 5:
                    if ((*(it + 2))->getFace() == (*(it + 3))->getFace() &&
                       (*(it + 3))->getFace() != (*it)->getFace()) {
                        m_uiTieBreaker = (*(it + 4))->getFace();
                        m_uiHighestCard = (*(it + 3))->getFace();
                        return true;
                    }
                    else if ((*(it + 3))->getFace() == (*(it + 4))->getFace() &&
                           (*(it + 3))->getFace() != (*it)->getFace()) {
                        m_uiHighestCard = (*(it + 4))->getFace();
                        m_uiTieBreaker = (*(it + 2))->getFace();
                        return true;
                    }
                    else
                        return false;
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
bool PlayerHand::has_three_kind() {

    for (auto it = m_pCards.begin(); it != m_pCards.end() - 2; ++it)
        if ((*it)->getFace() == (*(it + 1))->getFace() &&
           (*(it + 1))->getFace() == (*(it + 2))->getFace()) {
            m_uiHighestCard = (*it)->getFace();
            return true;
        }
    return false;
}

/**
 * @brief Determines if the player's hand contains four cards with the same face (four of a kind).
 *
 * @return true if the hand contains four of a kind, otherwise false.
 */
bool PlayerHand::has_four_kind() {

    for (auto it = m_pCards.begin(); it != m_pCards.end() - 3; ++it)
        if ((*it)->getFace() == (*(it + 1))->getFace() &&
           (*(it + 1))->getFace() == (*(it + 2))->getFace() &&
           (*(it + 2))->getFace() == (*(it + 3))->getFace()) {
            m_uiHighestCard = (*it)->getFace();
            return true;
        }
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

void PlayerHand::calculateScore() {
    uint8_t pairScore{NONE};
    uint8_t flushScore{NONE};
    uint8_t straightScore{NONE};

    /* Has pair, three of a kind, two pair, or four pair */
    pairScore = has_pair() ? has_three_kind() ? has_four_kind() ? \
                FOUR_OF_A_KIND : has_full_house() ? FULL_HOUSE : THREE_OF_A_KIND : has_two_pair() ? TWO_PAIR : PAIR : NONE;

    /* Has straight */
    straightScore = has_straight() ? STRAIGHT : NONE;

    /* Has flush */
    flushScore = has_flush() ? FLUSH : NONE;

    /* Has royal flush or straight flush */
    if (straightScore && flushScore)
        flushScore = has_royal_flush() ? ROYAL_FLUSH : STRAIGHT_FLUSH;

    if (straightScore || flushScore || pairScore == FULL_HOUSE) {
        m_uiHighestCard = m_pCards[m_uiNumCards-1]->getFace();
        m_uiTieBreaker = Card::eNone;
    }

    m_eScore = static_cast<eScore>(std::max(std::max(flushScore, straightScore), pairScore));

    if (m_eScore == NONE)
        m_uiHighestCard = m_uiTieBreaker = m_pCards[m_uiNumCards-1]->getFace();
}

/**
 * @brief DeckOfCards default constructor.
 *
 * @param deckShuffle Set to set shuffle deck on instantiation (true by default).
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

/**
 * @brief Print both hands of the two players.
 */
std::string PokerGame::toString() const {

    std::ostringstream output;
    for (size_t playerNum{0}; playerNum < m_uiNumPlayers; ++playerNum) {
        output << "Player: " << playerNum + 1 << std::endl;
        output << m_aPlayers[playerNum]->toString() << std::endl;
    }

    return output.str();
}

/**
 * @brief Deals 5 Cards to each player one by one.
 */
void PokerGame::dealCards() {

    for (size_t cardNum{0}; cardNum < MAX_CARDS_HAND; ++cardNum)
        for (size_t playerNum{0}; playerNum < m_uiNumPlayers; ++playerNum)
            m_aPlayers[playerNum]->acceptCard(m_cDeck.dealCard());
    /* no more players can be added */
    m_uiNumPlayers = MAX_PLAYERS;
}

/**
 * @brief Determine the winner of the game. If the two players have the same score the highest card wins.
 *        If the two players have the same highest card, the game is a draw.
 *
 * @return Player enum of winning player, if there is a tie to player wins.
 */
PokerGame::e_Player PokerGame::determineWinner() const {

    if (m_aPlayers[0]->getScore() != m_aPlayers[1]->getScore())
        return m_aPlayers[0]->getScore() > m_aPlayers[1]->getScore() ? PLAYER_1 : PLAYER_2;

    if (m_aPlayers[0]->getHighestCard() != m_aPlayers[1]->getHighestCard())
        return m_aPlayers[0]->getHighestCard() > m_aPlayers[1]->getHighestCard() ? PLAYER_1 : PLAYER_2;

    if (m_aPlayers[0]->getTieBreaker() != m_aPlayers[1]->getTieBreaker())
        return m_aPlayers[0]->getTieBreaker() > m_aPlayers[1]->getTieBreaker() ? PLAYER_1 : PLAYER_2;

    return NO_PLAYER;
}

/**
 * @brief Adds a new player to the poker game. This is mainly added to control which cards are
 *        distributed to each player for testing the determineWinner method.
 *
 * @param newPlayer new player with a full hand of five cards
 */
void PokerGame::addPlayer(PlayerHand *newPlayer) {

    if (m_uiNumPlayers < MAX_PLAYERS)
        m_aPlayers[m_uiNumPlayers++] = newPlayer;
    else
    {
        throw std::invalid_argument("too many players, maximum of 2");
    }
    
}