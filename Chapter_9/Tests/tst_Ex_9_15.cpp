#include <Ex_9_15.h>
#include <gtest/gtest.h>

/**
 * @brief Create TicTacToe game and start
 */
TEST(TwoPlayerGame, StartGame) {

    std::fstream playerMoves;
    const char *fileName = "inputFile.txt";

    playerMoves.open(fileName, std::ios::out);
    playerMoves << "2 1 2 3 4 6 5 7 8 9";
    playerMoves.close();

    TicTacToe ttt(fileName);
    std::remove(fileName);
}