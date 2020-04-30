/**
 * @file tst_Ex_9_25.cpp
 *
 * @brief Tests the implementation of member functions for the Card, DeckOfCards, and PlayerHand classes
 *        including to determine which hand has the higher score.
 *
 * @author Matt Randazzo
 */

/* Includes */
#include <Ex_9_25.h>
#include <gtest/gtest.h>

/**
 * @file tst_Ex_9_24.cpp
 *
 * @brief Tests the implementation of member functions for the Card, DeckOfCards, and PlayerHand classes
 *        including to determine if the hand has a pair, two pairs, three of a kind, four of a kind,
 *        or a royal flush.
 *
 * @author Matt Randazzo
 */

/**
 * @brief Contains no valid score
 */
TEST(ContainsPair, noValidPair) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eAce));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e10));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e4));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e5));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e6));

    EXPECT_FALSE(samplePlayer.has_pair());
}

/**
 * @brief Verifies there is a pair present in the first two cards in the sample hand of cards.
 */
TEST(ContainsPair, singlePairBeginning) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e10));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e2));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e2));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eAce));

    EXPECT_TRUE(samplePlayer.has_pair());
    EXPECT_EQ(samplePlayer.getScore(), PlayerHand::PAIR);
    EXPECT_EQ(samplePlayer.getHighestCard(), Card::e2);
}

/**
 * @brief Verifies there is a pair present in the middle two cards in the sample hand of cards.
 */
TEST(ContainsPair, singlePairMiddle) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e10));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e2));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e10));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eAce));

    EXPECT_TRUE(samplePlayer.has_pair());
    EXPECT_EQ(samplePlayer.getScore(), PlayerHand::PAIR);
    EXPECT_EQ(samplePlayer.getHighestCard(), Card::e10);
}

/**
 * @brief Verifies there is a pair present in the last two cards in the sample hand of cards.
 */
TEST(ContainsPair, singlePairEnd) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eAce));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e2));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e10));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eAce));

    EXPECT_TRUE(samplePlayer.has_pair());
    EXPECT_EQ(samplePlayer.getScore(), PlayerHand::PAIR);
    EXPECT_EQ(samplePlayer.getHighestCard(), Card::eAce);
}

/**
 * @brief Verifies there are not two pairs present in the card hand with no pairs present.
 */
TEST(ContainsTwoPair, noPairs) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e2));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e3));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e10));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eJack));

    EXPECT_FALSE(samplePlayer.has_two_pair());
    EXPECT_EQ(samplePlayer.getScore(), PlayerHand::NONE);
    EXPECT_EQ(samplePlayer.getHighestCard(), Card::eQueen);
}

/**
 * @brief Verifies there are not two pairs present in the card hand with one pair present in the
 *        first two cards.
 */
TEST(ContainsTwoPair, singlePairBeginning) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e2));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e2));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e10));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eJack));

    EXPECT_FALSE(samplePlayer.has_two_pair());
    EXPECT_EQ(samplePlayer.getScore(), PlayerHand::PAIR);
    EXPECT_EQ(samplePlayer.getHighestCard(), Card::e2);
}

/**
 * @brief Verifies there are not two pairs present in the card hand with one pair present in the
 *        first three cards.
 */
TEST(ContainsTwoPair, singlePairSecond) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e3));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e2));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e3));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eJack));

    EXPECT_FALSE(samplePlayer.has_two_pair());
    EXPECT_EQ(samplePlayer.getScore(), PlayerHand::PAIR);
    EXPECT_EQ(samplePlayer.getHighestCard(), Card::e3);
}

/**
 * @brief Verifies there are not two pairs present in the card hand with one pair present in the
 *        first three cards.
 */
TEST(ContainsTwoPair, singlePairLast) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e4));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e2));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e4));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e3));

    EXPECT_FALSE(samplePlayer.has_two_pair());
    EXPECT_EQ(samplePlayer.getScore(), PlayerHand::PAIR);
    EXPECT_EQ(samplePlayer.getHighestCard(), Card::e4);
}

/**
 * @brief Verifies there are two pairs present in the card hand with one pair present in the
 *        first two cards.
 */
TEST(ContainsTwoPair, pairsBeginning) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e2));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e2));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e10));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e10));

    EXPECT_TRUE(samplePlayer.has_two_pair());
    EXPECT_EQ(samplePlayer.getScore(), PlayerHand::TWO_PAIR);
    EXPECT_EQ(samplePlayer.getHighestCard(), Card::e10);
}

/**
 * @brief Verifies there are two pairs present in the card hand with one pair present in the
 *        first three cards.
 */
TEST(ContainsTwoPair, pairsSecondCard) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e3));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e3));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e2));

    EXPECT_TRUE(samplePlayer.has_two_pair());
    EXPECT_EQ(samplePlayer.getScore(), PlayerHand::TWO_PAIR);
    EXPECT_EQ(samplePlayer.getHighestCard(), Card::eQueen);
}

/**
 * @brief Verifies there are two pairs present in the card hand with both pairs present in the
 *        first four cards.
 */
TEST(ContainsTwoPair, pairsMiddle) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e2));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e2));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e10));

    EXPECT_TRUE(samplePlayer.has_two_pair());
    EXPECT_EQ(samplePlayer.getScore(), PlayerHand::TWO_PAIR);
    EXPECT_EQ(samplePlayer.getHighestCard(), Card::eQueen);
}

/**
 * @brief Verifies there are two pairs present in the card hand with both pairs present in the
 *        last four cards.
 */
TEST(ContainsTwoPair, pairsEnd) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e2));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e10));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e10));

    EXPECT_TRUE(samplePlayer.has_two_pair());
    EXPECT_EQ(samplePlayer.getScore(), PlayerHand::TWO_PAIR);
    EXPECT_EQ(samplePlayer.getHighestCard(), Card::eQueen);
}

/**
 * @brief Verifies there are two pairs present in the card hand with three of a kind in the
 *        first three cards.
 */
TEST(ContainsTwoPair, threeBeginning) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eHEARTS, Card::e2));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e10));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e2));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e2));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e9));

    EXPECT_TRUE(samplePlayer.has_three_kind());
    EXPECT_EQ(samplePlayer.getScore(), PlayerHand::THREE_OF_A_KIND);
    EXPECT_EQ(samplePlayer.getHighestCard(), Card::e2);
}

/**
 * @brief Verifies there are two pairs present in the card hand with three of a kind in the
 *        middle three cards.
 */
TEST(ContainsTwoPair, threeMiddle) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eHEARTS, Card::e6));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e10));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e6));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e6));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e4));

    EXPECT_TRUE(samplePlayer.has_three_kind());
    EXPECT_EQ(samplePlayer.getScore(), PlayerHand::THREE_OF_A_KIND);
    EXPECT_EQ(samplePlayer.getHighestCard(), Card::e6);
}

/**
 * @brief Verifies there are two pairs present in the card hand with three of a kind in the
 *        last three cards.
 */
TEST(ContainsTwoPair, threeEnd) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eHEARTS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e10));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e10));

    EXPECT_TRUE(samplePlayer.has_three_kind());
    EXPECT_EQ(samplePlayer.getScore(), PlayerHand::FULL_HOUSE);
    EXPECT_EQ(samplePlayer.getHighestCard(), Card::eQueen);
}

/**
 * @brief Verifies there are no three of a kind in the hand.
 */
TEST(ContainsThreeOfKind, noThreeKind) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e2));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e10));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e10));

    EXPECT_FALSE(samplePlayer.has_three_kind());
    EXPECT_EQ(samplePlayer.getScore(), PlayerHand::TWO_PAIR);
    EXPECT_EQ(samplePlayer.getHighestCard(), Card::eQueen);
}

/**
 * @brief Verifies there are three of a kind in the first three cards in the hand.
 */
TEST(ContainsThreeOfKind, threeBeginning) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eHEARTS, Card::e2));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e10));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e2));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e2));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e9));

    EXPECT_TRUE(samplePlayer.has_three_kind());
    EXPECT_EQ(samplePlayer.getScore(), PlayerHand::THREE_OF_A_KIND);
    EXPECT_EQ(samplePlayer.getHighestCard(), Card::e2);
}

/**
 * @brief Verifies there are three of a kind in the middle three cards in the hand.
 */
TEST(ContainsThreeOfKind, threeMiddle) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eHEARTS, Card::e6));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e10));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e6));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e6));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e4));

    EXPECT_TRUE(samplePlayer.has_three_kind());
    EXPECT_EQ(samplePlayer.getScore(), PlayerHand::THREE_OF_A_KIND);
    EXPECT_EQ(samplePlayer.getHighestCard(), Card::e6);
}

/**
 * @brief Verifies there are three of a kind in the last three cards in the hand.
 */
TEST(ContainsThreeOfKind, threeEnd) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eHEARTS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e10));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e10));

    EXPECT_TRUE(samplePlayer.has_three_kind());
    EXPECT_EQ(samplePlayer.getScore(), PlayerHand::FULL_HOUSE);
    EXPECT_EQ(samplePlayer.getHighestCard(), Card::eQueen);
}

/**
 * @brief Verifies there is not a four of a kind in the hand.
 */
TEST(ContainsFourOfAKind, noFourKind) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eHEARTS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eJack));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eKing));

    EXPECT_FALSE(samplePlayer.has_four_kind());
    EXPECT_EQ(samplePlayer.getScore(), PlayerHand::THREE_OF_A_KIND);
    EXPECT_EQ(samplePlayer.getHighestCard(), Card::eQueen);
}

/**
 * @brief Verifies there are four of a kind in the first four cards in the hand.
 */
TEST(ContainsFourOfAKind, fourBeginning) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eHEARTS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eKing));

    EXPECT_TRUE(samplePlayer.has_four_kind());
    EXPECT_EQ(samplePlayer.getScore(), PlayerHand::FOUR_OF_A_KIND);
    EXPECT_EQ(samplePlayer.getHighestCard(), Card::eQueen);
}

/**
 * @brief Verifies there are four of a kind in the last four cards in the hand.
 */
TEST(ContainsFourOfAKind, fourEnd) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eHEARTS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eJack));

    EXPECT_TRUE(samplePlayer.has_four_kind());
    EXPECT_EQ(samplePlayer.getScore(), PlayerHand::FOUR_OF_A_KIND);
    EXPECT_EQ(samplePlayer.getHighestCard(), Card::eQueen);
}

/**
 * @brief Verifies there is a flush with all suits.
 */
TEST(Flush, flushDiamonds) {

     for (int suitInt{Card::eSuits(0)}; suitInt < Card::eNumSuits; suitInt++) {
        PlayerHand samplePlayer;

        samplePlayer.acceptCard(new Card(Card::eSuits(suitInt), Card::e10));
        samplePlayer.acceptCard(new Card(Card::eSuits(suitInt), Card::e2));
        samplePlayer.acceptCard(new Card(Card::eSuits(suitInt), Card::eKing));
        samplePlayer.acceptCard(new Card(Card::eSuits(suitInt), Card::e6));
        samplePlayer.acceptCard(new Card(Card::eSuits(suitInt), Card::eJack));

        EXPECT_TRUE(samplePlayer.has_flush());
        EXPECT_EQ(samplePlayer.getScore(), PlayerHand::FLUSH);
        EXPECT_EQ(samplePlayer.getHighestCard(), Card::eKing);
    }
}

/**
 * @brief Verifies there is not a flush of spades in the hand with a card with a
 *        different suit.
 */
TEST(Flush, differentSuitFlush) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eHEARTS, Card::e10));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eAce));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eKing));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eJack));

    EXPECT_FALSE(samplePlayer.has_flush());
    EXPECT_EQ(samplePlayer.getScore(), PlayerHand::STRAIGHT);
    EXPECT_EQ(samplePlayer.getHighestCard(), Card::eAce);
}

/**
 * @brief Verifies there is not a flush with a card with a card with a different suit.
 */
TEST(Flush, invalidFlush) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e10));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eAce));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eKing));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eJack));

    EXPECT_FALSE(samplePlayer.has_flush());
    EXPECT_EQ(samplePlayer.getScore(), PlayerHand::STRAIGHT);
    EXPECT_EQ(samplePlayer.getHighestCard(), Card::eAce);
}

/**
 * @brief Verifies there is not a straight beginning with the first card.
 */
TEST(ContainsStraight, invalidStraightBeginning) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eHEARTS, Card::e3));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e3));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e4));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e5));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e6));

    EXPECT_FALSE(samplePlayer.has_straight());
    EXPECT_EQ(samplePlayer.getScore(), PlayerHand::PAIR);
    EXPECT_EQ(samplePlayer.getHighestCard(), Card::e3);
}

/**
 * @brief Verifies there is not a straight beginning with a middle card.
 */
TEST(ContainsStraight, invalidStraightMiddle) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eHEARTS, Card::e2));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e3));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e7));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e5));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e6));

    EXPECT_FALSE(samplePlayer.has_straight());
    EXPECT_EQ(samplePlayer.getScore(), PlayerHand::NONE);
    EXPECT_EQ(samplePlayer.getHighestCard(), Card::e7);
}

/**
 * @brief Verifies there is not a straight with the last card.
 */
TEST(ContainsStraight, invalidStraightEnd) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eHEARTS, Card::e4));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e3));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e8));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e5));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e6));

    EXPECT_FALSE(samplePlayer.has_straight());
    EXPECT_EQ(samplePlayer.getScore(), PlayerHand::NONE);
    EXPECT_EQ(samplePlayer.getHighestCard(), Card::e8);
}

/**
 * @brief Verifies there is a valid straight with each combination of faces.
 */
TEST(ContainsStraight, validStraights) {

    for (int faceInt{Card::eFaces(0)}; faceInt < Card::eNumFaces-4; faceInt++) {

        PlayerHand samplePlayer;

        samplePlayer.acceptCard(new Card(Card::eHEARTS, Card::eFaces(faceInt)));
        samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eFaces(faceInt+1)));
        samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eFaces(faceInt+2)));
        samplePlayer.acceptCard(new Card(Card::eSPADES, Card::eFaces(faceInt+3)));
        samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eFaces(faceInt+4)));

        EXPECT_TRUE(samplePlayer.has_straight());
        EXPECT_EQ(samplePlayer.getScore(), PlayerHand::STRAIGHT);
        EXPECT_EQ(samplePlayer.getHighestCard(), Card::eFaces(faceInt+4));
    }
}

/**
 * @brief Verifies there is a royal flush of each suit.
 */
TEST(RoyalFlush, royalFlushEachSuit) {

    for (int suitInt{Card::eSuits(0)}; suitInt < Card::eNumSuits; suitInt++) {
        PlayerHand samplePlayer;

        samplePlayer.acceptCard(new Card(Card::eSuits(suitInt), Card::e10));
        samplePlayer.acceptCard(new Card(Card::eSuits(suitInt), Card::eAce));
        samplePlayer.acceptCard(new Card(Card::eSuits(suitInt), Card::eKing));
        samplePlayer.acceptCard(new Card(Card::eSuits(suitInt), Card::eQueen));
        samplePlayer.acceptCard(new Card(Card::eSuits(suitInt), Card::eJack));

        EXPECT_TRUE(samplePlayer.has_royal_flush());
        EXPECT_EQ(samplePlayer.getScore(), PlayerHand::ROYAL_FLUSH);
        EXPECT_EQ(samplePlayer.getHighestCard(), Card::eAce);
    }
}

/**
 * @brief Verifies there is a straight flush over a flush for each suit and straight combination.
 */
TEST(RoyalFlush, straightFlushOverFlush) {

    for (int suitInt{Card::eSuits(0)}; suitInt < Card::eNumSuits; suitInt++) {

        for (int faceInt{Card::eFaces(0)}; faceInt < Card::eNumFaces - 5; faceInt++) {
            PlayerHand samplePlayer;

            samplePlayer.acceptCard(new Card(Card::eSuits(suitInt), Card::eFaces(faceInt)));
            samplePlayer.acceptCard(new Card(Card::eSuits(suitInt), Card::eFaces(faceInt+1)));
            samplePlayer.acceptCard(new Card(Card::eSuits(suitInt), Card::eFaces(faceInt+2)));
            samplePlayer.acceptCard(new Card(Card::eSuits(suitInt), Card::eFaces(faceInt+3)));
            samplePlayer.acceptCard(new Card(Card::eSuits(suitInt), Card::eFaces(faceInt+4)));

            EXPECT_FALSE(samplePlayer.has_royal_flush());
            EXPECT_TRUE(samplePlayer.has_flush());
            EXPECT_TRUE(samplePlayer.has_straight());
            EXPECT_EQ(samplePlayer.getScore(), PlayerHand::STRAIGHT_FLUSH);
            EXPECT_EQ(samplePlayer.getHighestCard(), Card::eFaces(faceInt+4));
        }
    }
}

/**
 * @brief Verifies a higher score beats a lower score (flush beats straight)
 */
TEST(verifyWinner, higherScoreWins) {

    PlayerHand player1;
    PlayerHand player2;

    player1.acceptCard(new Card(Card::eDIAMONDS, Card::e10));
    player1.acceptCard(new Card(Card::eHEARTS, Card::e9));
    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eKing));
    player1.acceptCard(new Card(Card::eSPADES, Card::eQueen));
    player1.acceptCard(new Card(Card::eCLUBS, Card::eJack));

    player2.acceptCard(new Card(Card::eHEARTS, Card::e2));
    player2.acceptCard(new Card(Card::eHEARTS, Card::e5));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eKing));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eQueen));
    player2.acceptCard(new Card(Card::eHEARTS, Card::e9));

    PokerGame game;
    game.addPlayer(&player1);
    game.addPlayer(&player2);

    EXPECT_EQ(player1.getScore(), PlayerHand::STRAIGHT);
    EXPECT_EQ(player2.getScore(), PlayerHand::FLUSH);
    EXPECT_EQ(game.determineWinner(), PokerGame::PLAYER_2);
}

/**
 * @brief Verifies a higher highest beats a lower highest card.
 */
TEST(verifyWinner, higherHighestCardNoScoreWins) {
    
    PlayerHand player1;
    PlayerHand player2;

    player1.acceptCard(new Card(Card::eDIAMONDS, Card::e10));
    player1.acceptCard(new Card(Card::eHEARTS, Card::e8));
    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eAce));
    player1.acceptCard(new Card(Card::eSPADES, Card::eQueen));
    player1.acceptCard(new Card(Card::eCLUBS, Card::eJack));

    player2.acceptCard(new Card(Card::eHEARTS, Card::e2));
    player2.acceptCard(new Card(Card::eHEARTS, Card::e5));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eKing));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eQueen));
    player2.acceptCard(new Card(Card::eDIAMONDS, Card::e9));

    PokerGame game;
    game.addPlayer(&player1);
    game.addPlayer(&player2);

    EXPECT_EQ(player1.getScore(), PlayerHand::NONE);
    EXPECT_EQ(player2.getScore(), PlayerHand::NONE);
    EXPECT_EQ(game.determineWinner(), PokerGame::PLAYER_1);

    PokerGame game2;
    game2.addPlayer(&player2);
    game2.addPlayer(&player1);
    EXPECT_EQ(player1.getScore(), PlayerHand::NONE);
    EXPECT_EQ(player2.getScore(), PlayerHand::NONE);
    EXPECT_EQ(game2.determineWinner(), PokerGame::PLAYER_2);
}

/**
 * @brief Verifies a higher highest beats a lower highest card.
 */
TEST(verifyWinner, higherStraight) {

    PlayerHand player1;
    PlayerHand player2;

    player1.acceptCard(new Card(Card::eDIAMONDS, Card::e8));
    player1.acceptCard(new Card(Card::eHEARTS, Card::e9));
    player1.acceptCard(new Card(Card::eDIAMONDS, Card::e10));
    player1.acceptCard(new Card(Card::eSPADES, Card::e7));
    player1.acceptCard(new Card(Card::eCLUBS, Card::eJack));

    player2.acceptCard(new Card(Card::eHEARTS, Card::e2));
    player2.acceptCard(new Card(Card::eHEARTS, Card::e3));
    player2.acceptCard(new Card(Card::eHEARTS, Card::e4));
    player2.acceptCard(new Card(Card::eHEARTS, Card::e6));
    player2.acceptCard(new Card(Card::eDIAMONDS, Card::e5));

    PokerGame game;
    game.addPlayer(&player1);
    game.addPlayer(&player2);

    EXPECT_EQ(player1.getScore(), PlayerHand::STRAIGHT);
    EXPECT_EQ(player2.getScore(), PlayerHand::STRAIGHT);
    EXPECT_EQ(game.determineWinner(), PokerGame::PLAYER_1);
}

/**
 * @brief Verifies there can be a tie with equal scores and equal high cards.
 */
TEST(verifyWinner, equalScoresEqualHighestCardStraight) {

    PlayerHand player1;
    PlayerHand player2;

    player1.acceptCard(new Card(Card::eDIAMONDS, Card::e10));
    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eAce));
    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eKing));
    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eJack));

    player2.acceptCard(new Card(Card::eHEARTS, Card::e10));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eAce));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eKing));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eQueen));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eJack));

    PokerGame game;
    game.addPlayer(&player1);
    game.addPlayer(&player2);

    EXPECT_EQ(player1.getScore(), PlayerHand::ROYAL_FLUSH);
    EXPECT_EQ(player2.getScore(), PlayerHand::ROYAL_FLUSH);
    EXPECT_EQ(game.determineWinner(), PokerGame::NO_PLAYER);
}

/**
 * @brief Verifies a higher pair wins.
 */
TEST(verifyWinner, higherPair) {

    PlayerHand player1;
    PlayerHand player2;

    player1.acceptCard(new Card(Card::eDIAMONDS, Card::e10));
    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eAce));
    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eJack));
    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    player1.acceptCard(new Card(Card::eCLUBS, Card::eJack));

    player2.acceptCard(new Card(Card::eHEARTS, Card::e10));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eAce));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eKing));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eQueen));
    player2.acceptCard(new Card(Card::eSPADES, Card::e10));

    PokerGame game;
    game.addPlayer(&player1);
    game.addPlayer(&player2);

    EXPECT_EQ(player1.getScore(), PlayerHand::PAIR);
    EXPECT_EQ(player2.getScore(), PlayerHand::PAIR);
    EXPECT_EQ(game.determineWinner(), PokerGame::PLAYER_1);
}

/**
 * @brief Verifies a higher three of a kind wins.
 */
TEST(verifyWinner, higherThreeKind) {

    PlayerHand player1;
    PlayerHand player2;

    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eJack));
    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eAce));
    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eJack));
    player1.acceptCard(new Card(Card::eHEARTS, Card::eQueen));
    player1.acceptCard(new Card(Card::eCLUBS, Card::eJack));

    player2.acceptCard(new Card(Card::eHEARTS, Card::e10));
    player2.acceptCard(new Card(Card::eCLUBS, Card::e10));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eKing));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eQueen));
    player2.acceptCard(new Card(Card::eSPADES, Card::e10));

    PokerGame game;
    game.addPlayer(&player1);
    game.addPlayer(&player2);

    EXPECT_EQ(player1.getScore(), PlayerHand::THREE_OF_A_KIND);
    EXPECT_EQ(player1.getHighestCard(), Card::eJack);
    EXPECT_EQ(player2.getScore(), PlayerHand::THREE_OF_A_KIND);
    EXPECT_EQ(player2.getHighestCard(), Card::e10);
    EXPECT_EQ(game.determineWinner(), PokerGame::PLAYER_1);
}

/**
 * @brief Verifies a higher full house wins.
 */
TEST(verifyWinner, higherFullHouse) {

    PlayerHand player1;
    PlayerHand player2;

    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eJack));
    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eJack));
    player1.acceptCard(new Card(Card::eHEARTS, Card::eQueen));
    player1.acceptCard(new Card(Card::eCLUBS, Card::eJack));

    player2.acceptCard(new Card(Card::eHEARTS, Card::e10));
    player2.acceptCard(new Card(Card::eCLUBS, Card::e10));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eJack));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eJack));
    player2.acceptCard(new Card(Card::eSPADES, Card::e10));

    PokerGame game;
    game.addPlayer(&player1);
    game.addPlayer(&player2);

    EXPECT_EQ(player1.getScore(), PlayerHand::FULL_HOUSE);
    EXPECT_EQ(player1.getHighestCard(), Card::eQueen);

    EXPECT_EQ(player2.getScore(), PlayerHand::FULL_HOUSE);
    EXPECT_EQ(player2.getHighestCard(), Card::eJack);

    EXPECT_EQ(game.determineWinner(), PokerGame::PLAYER_1);
}

/**
 * @brief Verifies a higher four of a kind wins.
 */
TEST(verifyWinner, higherFourOfAKind) {

    PlayerHand player1;
    PlayerHand player2;

    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eJack));
    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    player1.acceptCard(new Card(Card::eSPADES, Card::eQueen));
    player1.acceptCard(new Card(Card::eHEARTS, Card::eQueen));
    player1.acceptCard(new Card(Card::eCLUBS, Card::eQueen));

    player2.acceptCard(new Card(Card::eSPADES, Card::eJack));
    player2.acceptCard(new Card(Card::eCLUBS, Card::eJack));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eJack));
    player2.acceptCard(new Card(Card::eDIAMONDS, Card::eJack));
    player2.acceptCard(new Card(Card::eSPADES, Card::e10));

    PokerGame game;
    game.addPlayer(&player1);
    game.addPlayer(&player2);

    EXPECT_EQ(player1.getScore(), PlayerHand::FOUR_OF_A_KIND);
    EXPECT_EQ(player1.getHighestCard(), Card::eQueen);

    EXPECT_EQ(player2.getScore(), PlayerHand::FOUR_OF_A_KIND);
    EXPECT_EQ(player2.getHighestCard(), Card::eJack);

    EXPECT_EQ(game.determineWinner(), PokerGame::PLAYER_1);
}

/**
 * @brief Verifies a higher straight flush wins.
 */
TEST(verifyWinner, higherStraightFlush) {

    PlayerHand player1;
    PlayerHand player2;

    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eJack));
    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    player1.acceptCard(new Card(Card::eDIAMONDS, Card::e10));
    player1.acceptCard(new Card(Card::eDIAMONDS, Card::e9));
    player1.acceptCard(new Card(Card::eDIAMONDS, Card::e8));

    player2.acceptCard(new Card(Card::eSPADES, Card::eJack));
    player2.acceptCard(new Card(Card::eSPADES, Card::e10));
    player2.acceptCard(new Card(Card::eSPADES, Card::e9));
    player2.acceptCard(new Card(Card::eSPADES, Card::e7));
    player2.acceptCard(new Card(Card::eSPADES, Card::e8));

    PokerGame game;
    game.addPlayer(&player1);
    game.addPlayer(&player2);

    EXPECT_EQ(player1.getScore(), PlayerHand::STRAIGHT_FLUSH);
    EXPECT_EQ(player1.getHighestCard(), Card::eQueen);

    EXPECT_EQ(player2.getScore(), PlayerHand::STRAIGHT_FLUSH);
    EXPECT_EQ(player2.getHighestCard(), Card::eJack);

    EXPECT_EQ(game.determineWinner(), PokerGame::PLAYER_1);
}

/**
 * @brief Verifies hand with greater tiebreaker of same two pair hands.
 */
TEST(verifyWinner, sameTwoPairTieBreakerBeginning) {

    PlayerHand player1;
    PlayerHand player2;

    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eJack));
    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    player1.acceptCard(new Card(Card::eHEARTS, Card::eKing));
    player1.acceptCard(new Card(Card::eCLUBS, Card::eJack));
    player1.acceptCard(new Card(Card::eCLUBS, Card::eQueen));

    player2.acceptCard(new Card(Card::eSPADES, Card::eQueen));
    player2.acceptCard(new Card(Card::eSPADES, Card::eJack));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eQueen));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eJack));
    player2.acceptCard(new Card(Card::eDIAMONDS, Card::eAce));

    PokerGame game;
    game.addPlayer(&player1);
    game.addPlayer(&player2);

    EXPECT_EQ(player1.getScore(), PlayerHand::TWO_PAIR);
    EXPECT_EQ(player1.getHighestCard(), Card::eQueen);
    EXPECT_EQ(player1.getTieBreaker(), Card::eKing);

    EXPECT_EQ(player2.getScore(), PlayerHand::TWO_PAIR);
    EXPECT_EQ(player2.getHighestCard(), Card::eQueen);
    EXPECT_EQ(player2.getTieBreaker(), Card::eAce);

    EXPECT_EQ(game.determineWinner(), PokerGame::PLAYER_2);
}

/**
 * @brief Verifies hand with greater tiebreaker of same two pair hands.
 */
TEST(verifyWinner, sameTwoPairTieBreakerMiddle) {

    PlayerHand player1;
    PlayerHand player2;

    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eJack));
    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eKing));
    player1.acceptCard(new Card(Card::eHEARTS, Card::eQueen));
    player1.acceptCard(new Card(Card::eCLUBS, Card::eJack));
    player1.acceptCard(new Card(Card::eCLUBS, Card::eKing));

    player2.acceptCard(new Card(Card::eSPADES, Card::eKing));
    player2.acceptCard(new Card(Card::eSPADES, Card::eJack));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eKing));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eJack));
    player2.acceptCard(new Card(Card::eDIAMONDS, Card::eAce));

    PokerGame game;
    game.addPlayer(&player1);
    game.addPlayer(&player2);

    EXPECT_EQ(player1.getScore(), PlayerHand::TWO_PAIR);
    EXPECT_EQ(player1.getHighestCard(), Card::eKing);
    EXPECT_EQ(player1.getTieBreaker(), Card::eQueen);

    EXPECT_EQ(player2.getScore(), PlayerHand::TWO_PAIR);
    EXPECT_EQ(player2.getHighestCard(), Card::eKing);
    EXPECT_EQ(player2.getTieBreaker(), Card::eAce);

    EXPECT_EQ(game.determineWinner(), PokerGame::PLAYER_2);
}

/**
 * @brief Verifies hand with greater tiebreaker of same two pair hands.
 */
TEST(verifyWinner, sameTwoPairTieBreakerEnd) {

    PlayerHand player1;
    PlayerHand player2;

    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eJack));
    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    player1.acceptCard(new Card(Card::eHEARTS, Card::e2));
    player1.acceptCard(new Card(Card::eCLUBS, Card::eJack));
    player1.acceptCard(new Card(Card::eCLUBS, Card::eQueen));

    player2.acceptCard(new Card(Card::eSPADES, Card::eQueen));
    player2.acceptCard(new Card(Card::eSPADES, Card::eJack));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eQueen));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eJack));
    player2.acceptCard(new Card(Card::eDIAMONDS, Card::e8));

    PokerGame game;
    game.addPlayer(&player1);
    game.addPlayer(&player2);

    EXPECT_EQ(player1.getScore(), PlayerHand::TWO_PAIR);
    EXPECT_EQ(player1.getHighestCard(), Card::eQueen);
    EXPECT_EQ(player1.getTieBreaker(), Card::e2);

    EXPECT_EQ(player2.getScore(), PlayerHand::TWO_PAIR);
    EXPECT_EQ(player2.getHighestCard(), Card::eQueen);
    EXPECT_EQ(player2.getTieBreaker(), Card::e8);

    EXPECT_EQ(game.determineWinner(), PokerGame::PLAYER_2);
}

/**
 * @brief Verifies hand with greater tiebreaker of same pair.
 */
TEST(verifyWinner, samePairMaxCards) {

    PlayerHand player1;
    PlayerHand player2;

    player1.acceptCard(new Card(Card::eDIAMONDS, Card::e7));
    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    player1.acceptCard(new Card(Card::eHEARTS, Card::e2));
    player1.acceptCard(new Card(Card::eCLUBS, Card::e10));
    player1.acceptCard(new Card(Card::eCLUBS, Card::eQueen));

    player2.acceptCard(new Card(Card::eSPADES, Card::eQueen));
    player2.acceptCard(new Card(Card::eSPADES, Card::e10));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eQueen));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eJack));
    player2.acceptCard(new Card(Card::eDIAMONDS, Card::e8));

    PokerGame game;
    game.addPlayer(&player1);
    game.addPlayer(&player2);

    EXPECT_EQ(player1.getScore(), PlayerHand::PAIR);
    EXPECT_EQ(player1.getHighestCard(), Card::eQueen);
    EXPECT_EQ(player1.getTieBreaker(), Card::e10);

    EXPECT_EQ(player2.getScore(), PlayerHand::PAIR);
    EXPECT_EQ(player2.getHighestCard(), Card::eQueen);
    EXPECT_EQ(player2.getTieBreaker(), Card::eJack);

    EXPECT_EQ(game.determineWinner(), PokerGame::PLAYER_2);
}

/**
 * @brief Verifies hand with greater tiebreaker of same pair.
 */
TEST(verifyWinner, samePairNotMaxCards) {

    PlayerHand player1;
    PlayerHand player2;

    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eJack));
    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    player1.acceptCard(new Card(Card::eHEARTS, Card::e2));
    player1.acceptCard(new Card(Card::eCLUBS, Card::eKing));
    player1.acceptCard(new Card(Card::eCLUBS, Card::eQueen));

    player2.acceptCard(new Card(Card::eSPADES, Card::eQueen));
    player2.acceptCard(new Card(Card::eSPADES, Card::e10));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eQueen));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eAce));
    player2.acceptCard(new Card(Card::eDIAMONDS, Card::e8));

    PokerGame game;
    game.addPlayer(&player1);
    game.addPlayer(&player2);

    EXPECT_EQ(player1.getScore(), PlayerHand::PAIR);
    EXPECT_EQ(player1.getHighestCard(), Card::eQueen);
    EXPECT_EQ(player1.getTieBreaker(), Card::eKing);

    EXPECT_EQ(player2.getScore(), PlayerHand::PAIR);
    EXPECT_EQ(player2.getHighestCard(), Card::eQueen);
    EXPECT_EQ(player2.getTieBreaker(), Card::eAce);

    EXPECT_EQ(game.determineWinner(), PokerGame::PLAYER_2);
}

/**
 * @brief Verifies hand with greater tiebreaker of same pair same tiebreaker.
 */
TEST(verifyWinner, samePairSameTiebreakerMax) {

    PlayerHand player1;
    PlayerHand player2;

    player1.acceptCard(new Card(Card::eDIAMONDS, Card::e8));
    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    player1.acceptCard(new Card(Card::eHEARTS, Card::e2));
    player1.acceptCard(new Card(Card::eCLUBS, Card::eJack));
    player1.acceptCard(new Card(Card::eCLUBS, Card::eQueen));

    player2.acceptCard(new Card(Card::eSPADES, Card::eQueen));
    player2.acceptCard(new Card(Card::eSPADES, Card::e10));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eQueen));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eJack));
    player2.acceptCard(new Card(Card::eDIAMONDS, Card::e8));

    PokerGame game;
    game.addPlayer(&player1);
    game.addPlayer(&player2);

    EXPECT_EQ(player1.getScore(), PlayerHand::PAIR);
    EXPECT_EQ(player1.getHighestCard(), Card::eQueen);
    EXPECT_EQ(player1.getTieBreaker(), Card::eJack);

    EXPECT_EQ(player2.getScore(), PlayerHand::PAIR);
    EXPECT_EQ(player2.getHighestCard(), Card::eQueen);
    EXPECT_EQ(player2.getTieBreaker(), Card::eJack);

    EXPECT_EQ(game.determineWinner(), PokerGame::NO_PLAYER);
}

/**
 * @brief Verifies hand with greater tiebreaker of same pair same tiebreaker.
 */
TEST(verifyWinner, samePairSameTiebreakerNotMax) {

    PlayerHand player1;
    PlayerHand player2;

    player1.acceptCard(new Card(Card::eDIAMONDS, Card::e8));
    player1.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    player1.acceptCard(new Card(Card::eHEARTS, Card::e2));
    player1.acceptCard(new Card(Card::eCLUBS, Card::eKing));
    player1.acceptCard(new Card(Card::eCLUBS, Card::eQueen));

    player2.acceptCard(new Card(Card::eSPADES, Card::eQueen));
    player2.acceptCard(new Card(Card::eSPADES, Card::e10));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eQueen));
    player2.acceptCard(new Card(Card::eHEARTS, Card::eKing));
    player2.acceptCard(new Card(Card::eDIAMONDS, Card::e8));

    PokerGame game;
    game.addPlayer(&player1);
    game.addPlayer(&player2);

    EXPECT_EQ(player1.getScore(), PlayerHand::PAIR);
    EXPECT_EQ(player1.getHighestCard(), Card::eQueen);
    EXPECT_EQ(player1.getTieBreaker(), Card::eKing);

    EXPECT_EQ(player2.getScore(), PlayerHand::PAIR);
    EXPECT_EQ(player2.getHighestCard(), Card::eQueen);
    EXPECT_EQ(player2.getTieBreaker(), Card::eKing);

    EXPECT_EQ(game.determineWinner(), PokerGame::NO_PLAYER);
}
