#include <Ex_9_15.h>
#include <gtest/gtest.h>

const char *fileName = "moves.txt";

/**
 * @brief Create TicTacToe game and start
 */
TEST(TwoPlayerSimulatedGame, TieGame) {

    std::fstream playerMoves;

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
 * @brief Create Tie TicTacToe with almost negative diagonal.
 */
TEST(TwoPlayerSimulatedGame, TieGameAlmostDiagonal) {

    std::fstream playerMoves;

    playerMoves.open(fileName, std::ios::out);
    playerMoves << "2 3 2 5 7 9 1 4 6 8";
    playerMoves.close();

    TicTacToe ttt(fileName);
    EXPECT_EQ(ttt.m_uiNumPlayers, 2);

    EXPECT_EQ(ttt.m_pBoard[0][0], TicTacToe::PLAYER_2);
    EXPECT_EQ(ttt.m_pBoard[0][1], TicTacToe::PLAYER_2);
    EXPECT_EQ(ttt.m_pBoard[0][2], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[1][0], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[1][1], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[1][2], TicTacToe::PLAYER_2);
    EXPECT_EQ(ttt.m_pBoard[2][0], TicTacToe::PLAYER_2);
    EXPECT_EQ(ttt.m_pBoard[2][1], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[2][2], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt._findWinner(), TicTacToe::TIE_GAME);
    
    std::remove(fileName);
}

/**
 * @brief Player 1 wins in row.
 */
TEST(TwoPlayerSimulatedGame, Player1RowWinner) {

    std::fstream playerMoves;

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
 * @brief Player 2 wins in row.
 */
TEST(TwoPlayerSimulatedGame, Player2RowWinner) {

    std::fstream playerMoves;

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

/**
 * @brief Player 1 wins in column.
 */
TEST(TwoPlayerSimulatedGame, Player1ColumnWinner) {

    std::fstream playerMoves;

    playerMoves.open(fileName, std::ios::out);
    playerMoves << "2 1 2 4 5 7";
    playerMoves.close();

    TicTacToe ttt(fileName);
    EXPECT_EQ(ttt.m_uiNumPlayers, 2);

    EXPECT_EQ(ttt.m_pBoard[0][0], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[0][1], TicTacToe::PLAYER_2);
    EXPECT_EQ(ttt.m_pBoard[0][2], TicTacToe::NO_PLAYER);
    EXPECT_EQ(ttt.m_pBoard[1][0], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[1][1], TicTacToe::PLAYER_2);
    EXPECT_EQ(ttt.m_pBoard[1][2], TicTacToe::NO_PLAYER);
    EXPECT_EQ(ttt.m_pBoard[2][0], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[2][1], TicTacToe::NO_PLAYER);
    EXPECT_EQ(ttt.m_pBoard[2][2], TicTacToe::NO_PLAYER);
    
    EXPECT_EQ(ttt._findWinner(), TicTacToe::PLAYER_1);
    
    std::remove(fileName);
}

/**
 * @brief Player 2 wins in column.
 */
TEST(TwoPlayerSimulatedGame, Player2ColumnWinner) {

    std::fstream playerMoves;

    playerMoves.open(fileName, std::ios::out);
    playerMoves << "2 1 2 4 5 6 8";
    playerMoves.close();

    TicTacToe ttt(fileName);
    EXPECT_EQ(ttt.m_uiNumPlayers, 2);

    EXPECT_EQ(ttt.m_pBoard[0][0], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[0][1], TicTacToe::PLAYER_2);
    EXPECT_EQ(ttt.m_pBoard[0][2], TicTacToe::NO_PLAYER);
    EXPECT_EQ(ttt.m_pBoard[1][0], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[1][1], TicTacToe::PLAYER_2);
    EXPECT_EQ(ttt.m_pBoard[1][2], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[2][0], TicTacToe::NO_PLAYER);
    EXPECT_EQ(ttt.m_pBoard[2][1], TicTacToe::PLAYER_2);
    EXPECT_EQ(ttt.m_pBoard[2][2], TicTacToe::NO_PLAYER);

    EXPECT_EQ(ttt._findWinner(), TicTacToe::PLAYER_2);
    
    std::remove(fileName);
}

/**
 * @brief Player 1 wins in positive diagonal.
 */
TEST(TwoPlayerSimulatedGame, Player1PositiveDiagonalWinner) {

    std::fstream playerMoves;

    playerMoves.open(fileName, std::ios::out);
    playerMoves << "2 1 2 5 4 9";
    playerMoves.close();

    TicTacToe ttt(fileName);
    EXPECT_EQ(ttt.m_uiNumPlayers, 2);

    EXPECT_EQ(ttt.m_pBoard[0][0], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[0][1], TicTacToe::PLAYER_2);
    EXPECT_EQ(ttt.m_pBoard[0][2], TicTacToe::NO_PLAYER);
    EXPECT_EQ(ttt.m_pBoard[1][0], TicTacToe::PLAYER_2);
    EXPECT_EQ(ttt.m_pBoard[1][1], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[1][2], TicTacToe::NO_PLAYER);
    EXPECT_EQ(ttt.m_pBoard[2][0], TicTacToe::NO_PLAYER);
    EXPECT_EQ(ttt.m_pBoard[2][1], TicTacToe::NO_PLAYER);
    EXPECT_EQ(ttt.m_pBoard[2][2], TicTacToe::PLAYER_1);
    
    EXPECT_EQ(ttt._findWinner(), TicTacToe::PLAYER_1);
    
    std::remove(fileName);
}

/**
 * @brief Player 2 wins in positive diagonal.
 */
TEST(TwoPlayerSimulatedGame, Player2PositiveDiagonalWinner) {

    std::fstream playerMoves;

    playerMoves.open(fileName, std::ios::out);
    playerMoves << "2 2 1 4 5 6 9";
    playerMoves.close();

    TicTacToe ttt(fileName);
    EXPECT_EQ(ttt.m_uiNumPlayers, 2);

    EXPECT_EQ(ttt.m_pBoard[0][0], TicTacToe::PLAYER_2);
    EXPECT_EQ(ttt.m_pBoard[0][1], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[0][2], TicTacToe::NO_PLAYER);
    EXPECT_EQ(ttt.m_pBoard[1][0], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[1][1], TicTacToe::PLAYER_2);
    EXPECT_EQ(ttt.m_pBoard[1][2], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[2][0], TicTacToe::NO_PLAYER);
    EXPECT_EQ(ttt.m_pBoard[2][1], TicTacToe::NO_PLAYER);
    EXPECT_EQ(ttt.m_pBoard[2][2], TicTacToe::PLAYER_2);

    EXPECT_EQ(ttt._findWinner(), TicTacToe::PLAYER_2);
    
    std::remove(fileName);
}

/**
 * @brief Player 1 wins in negative diagonal.
 */
TEST(TwoPlayerSimulatedGame, Player1NegativeDiagonalWinner) {

    std::fstream playerMoves;

    playerMoves.open(fileName, std::ios::out);
    playerMoves << "2 3 2 5 4 7";
    playerMoves.close();

    TicTacToe ttt(fileName);
    EXPECT_EQ(ttt.m_uiNumPlayers, 2);

    EXPECT_EQ(ttt.m_pBoard[0][0], TicTacToe::NO_PLAYER);
    EXPECT_EQ(ttt.m_pBoard[0][1], TicTacToe::PLAYER_2);
    EXPECT_EQ(ttt.m_pBoard[0][2], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[1][0], TicTacToe::PLAYER_2);
    EXPECT_EQ(ttt.m_pBoard[1][1], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[1][2], TicTacToe::NO_PLAYER);
    EXPECT_EQ(ttt.m_pBoard[2][0], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[2][1], TicTacToe::NO_PLAYER);
    EXPECT_EQ(ttt.m_pBoard[2][2], TicTacToe::NO_PLAYER);
    
    EXPECT_EQ(ttt._findWinner(), TicTacToe::PLAYER_1);
    
    std::remove(fileName);
}

/**
 * @brief Player 2 wins in negative diagonal.
 */
TEST(TwoPlayerSimulatedGame, Player2NegativeDiagonalWinner) {

    std::fstream playerMoves;

    playerMoves.open(fileName, std::ios::out);
    playerMoves << "2 2 3 4 5 6 7";
    playerMoves.close();

    TicTacToe ttt(fileName);
    EXPECT_EQ(ttt.m_uiNumPlayers, 2);

    EXPECT_EQ(ttt.m_pBoard[0][0], TicTacToe::NO_PLAYER);
    EXPECT_EQ(ttt.m_pBoard[0][1], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[0][2], TicTacToe::PLAYER_2);
    EXPECT_EQ(ttt.m_pBoard[1][0], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[1][1], TicTacToe::PLAYER_2);
    EXPECT_EQ(ttt.m_pBoard[1][2], TicTacToe::PLAYER_1);
    EXPECT_EQ(ttt.m_pBoard[2][0], TicTacToe::PLAYER_2);
    EXPECT_EQ(ttt.m_pBoard[2][1], TicTacToe::NO_PLAYER);
    EXPECT_EQ(ttt.m_pBoard[2][2], TicTacToe::NO_PLAYER);

    EXPECT_EQ(ttt._findWinner(), TicTacToe::PLAYER_2);
    
    std::remove(fileName);
}