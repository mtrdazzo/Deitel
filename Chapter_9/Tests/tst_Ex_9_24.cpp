/**
 * @file tst_Ex_9_24.cpp
 *
 * @brief Tests the implementation of member functions for the Card, DeckOfCards, and PlayerHand classes
 *        including to determine if the hand has a pair, two pairs, three of a kind, four of a kind,
 *        or a royal flush.
 *
 * @author Matt Randazzo
 */

/* Includes */
#include <Ex_9_24.h>
#include <gtest/gtest.h>
#include <iostream>

/**
 * @brief Verifies there is no pair present in the sample hand of cards.
 */
TEST(ContainsPair, noPair) {

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
}

/**
 * @brief Verifies there are three of a kind in the first four cards in the hand.
 */
TEST(ContainsFourOfAKind, fourBeginning) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eHEARTS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eKing));

    EXPECT_TRUE(samplePlayer.has_four_kind());
}

/**
 * @brief Verifies there are three of a kind in the last four cards in the hand.
 */
TEST(ContainsFourOfAKind, fourEnd) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eHEARTS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eJack));

    EXPECT_TRUE(samplePlayer.has_four_kind());
}

/**
 * @brief Verifies there is a royal flush of diamonds in the hand.
 */
TEST(RoyalFlush, royalFlushDiamonds) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e10));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eAce));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eKing));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eJack));

    EXPECT_TRUE(samplePlayer.has_flush());
}

/**
 * @brief Verifies there is a flush of hearts in the hand.
 */
TEST(RoyalFlush, royalFlushHearts) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eHEARTS, Card::e10));
    samplePlayer.acceptCard(new Card(Card::eHEARTS, Card::e2));
    samplePlayer.acceptCard(new Card(Card::eHEARTS, Card::eKing));
    samplePlayer.acceptCard(new Card(Card::eHEARTS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eHEARTS, Card::eJack));

    EXPECT_TRUE(samplePlayer.has_flush());
}

/**
 * @brief Verifies there is a flush of clubs in the hand.
 */
TEST(RoyalFlush, royalFlushClubs) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e10));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eAce));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eKing));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e5));
    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::eJack));

    EXPECT_TRUE(samplePlayer.has_flush());
}

/**
 * @brief Verifies there is a royal flush of spades in the hand.
 */
TEST(RoyalFlush, royalFlushSpades) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eSPADES, Card::e10));
    samplePlayer.acceptCard(new Card(Card::eSPADES, Card::eAce));
    samplePlayer.acceptCard(new Card(Card::eSPADES, Card::eKing));
    samplePlayer.acceptCard(new Card(Card::eSPADES, Card::e4));
    samplePlayer.acceptCard(new Card(Card::eSPADES, Card::eJack));

    EXPECT_TRUE(samplePlayer.has_flush());
}

/**
 * @brief Verifies there is not a flush of spades in the hand with a card with a
 *        different suit.
 */
TEST(RoyalFlush, differentSuitFlush) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eHEARTS, Card::e10));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eAce));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eKing));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eJack));

    EXPECT_FALSE(samplePlayer.has_flush());
}

/**
 * @brief Verifies there is not a flush of spades in the hand with a card with a
 *        missing.
 */
TEST(RoyalFlush, invalidFlush) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eCLUBS, Card::e10));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eAce));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eKing));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eJack));

    EXPECT_FALSE(samplePlayer.has_flush());
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
}

/**
 * @brief Verifies there is a valid straight with the lowest cards.
 */
TEST(ContainsStraight, validStraightLow) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eHEARTS, Card::e4));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e3));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e2));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e5));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::e6));

    EXPECT_TRUE(samplePlayer.has_straight());
}

/**
 * @brief Verifies there is a valid straight with the highest cards.
 */
TEST(ContainsStraight, validStraightHigh) {

    PlayerHand samplePlayer;

    samplePlayer.acceptCard(new Card(Card::eHEARTS, Card::e10));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eQueen));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eAce));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eKing));
    samplePlayer.acceptCard(new Card(Card::eDIAMONDS, Card::eJack));

    EXPECT_TRUE(samplePlayer.has_straight());
}