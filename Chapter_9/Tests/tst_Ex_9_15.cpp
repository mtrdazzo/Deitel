#include <Ex_9_15.h>
#include <gtest/gtest.h>

/**
 * @brief Create TicTacToe game and start
 */
TEST(TwoPlayerSimulatedGame, TieGame) {

    std::fstream playerMoves;
    const char *fileName = "moves.txt";

    playerMoves.open(fileName, std::ios::out);
    playerMoves << "2 1 2 3 4 6 5 7 9 8";
    playerMoves.close();

    TicTacToe ttt(fileName);
    EXPECT_EQ(ttt.m_uiNumPlayers, 2);

    EXPECT_EQ(ttt.m_pBoard[0][0], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[0][1], TicTacToe::PLAYER_2);
    EXPECT_EQ(ttt.m_pBoard[0][2], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[1][0], TicTacToe::PLAYER_2);
    EXPECT_EQ(ttt.m_pBoard[1][1], TicTacToe::PLAYER_2);
    EXPECT_EQ(ttt.m_pBoard[1][2], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[2][0], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[2][1], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[2][2], TicTacToe::PLAYER_2);
    EXPECT_EQ(ttt._findWinner(), TicTacToe::TIE_GAME);
    
    std::remove(fileName);
}

/**
 * @brief Create TicTacToe game and start
 */
TEST(TwoPlayerSimulatedGame, Player1WinsThreeMoves) {

    std::fstream playerMoves;
    const char *fileName = "moves.txt";

    playerMoves.open(fileName, std::ios::out);
    playerMoves << "2 1 4 2 5 3";
    playerMoves.close();

    TicTacToe ttt(fileName);
    EXPECT_EQ(ttt.m_uiNumPlayers, 2);

    EXPECT_EQ(ttt.m_pBoard[0][0], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[0][1], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[0][2], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[1][0], TicTacToe::PLAYER_2);
    EXPECT_EQ(ttt.m_pBoard[1][1], TicTacToe::PLAYER_2);
    EXPECT_EQ(ttt.m_pBoard[1][2], TicTacToe::NO_PLAYER);
    EXPECT_EQ(ttt.m_pBoard[2][0], TicTacToe::NO_PLAYER);
    EXPECT_EQ(ttt.m_pBoard[2][1], TicTacToe::NO_PLAYER);
    EXPECT_EQ(ttt.m_pBoard[2][2], TicTacToe::NO_PLAYER);
    
    EXPECT_EQ(ttt._findWinner(), TicTacToe::PLAYER_1);
    
    std::remove(fileName);
}

/**
 * @brief Create TicTacToe game and start
 */
TEST(TwoPlayerSimulatedGame, Player2WinsThreeMoves) {

    std::fstream playerMoves;
    const char *fileName = "moves.txt";

    playerMoves.open(fileName, std::ios::out);
    playerMoves << "2 1 4 2 5 7 6";
    playerMoves.close();

    TicTacToe ttt(fileName);
    EXPECT_EQ(ttt.m_uiNumPlayers, 2);

    EXPECT_EQ(ttt.m_pBoard[0][0], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[0][1], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[0][2], TicTacToe::NO_PLAYER);
    EXPECT_EQ(ttt.m_pBoard[1][0], TicTacToe::PLAYER_2);
    EXPECT_EQ(ttt.m_pBoard[1][1], TicTacToe::PLAYER_2);
    EXPECT_EQ(ttt.m_pBoard[1][2], TicTacToe::PLAYER_2);
    EXPECT_EQ(ttt.m_pBoard[2][0], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[2][1], TicTacToe::NO_PLAYER);
    EXPECT_EQ(ttt.m_pBoard[2][2], TicTacToe::NO_PLAYER);

    EXPECT_EQ(ttt._findWinner(), TicTacToe::PLAYER_2);
    
    std::remove(fileName);
}