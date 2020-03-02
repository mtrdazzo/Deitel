#include <Ex_9_15.h>
#include <gtest/gtest.h>

/**
 * @brief Create TicTacToe game and start
 */
TEST(Constructor, StartGame) {

    TicTacToe ttt;
    ttt.start();
}