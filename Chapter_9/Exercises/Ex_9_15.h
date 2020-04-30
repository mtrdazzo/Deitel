/**
 * Exercise 9-15 TicTacToe Class
 * 
 * Create a class TicTacToe that will enable you to write a complete program to play
 * the game of tic-tac-toe. The class contains as private data a 3-by-3 two-dimensional
 * array of integers. The constructor should initialize the empty board to all zeroes.
 * Allow two human players. Wherever the first player moves, place a 1 in the specified
 * square. Place a 2 wherever the second player moves. Each move must be to any empty
 * square. After each move, determine whether the game has been won or is a draw. If you
 * feel ambitious, modify your program so that the computer makes the moves for one of
 * the players. Also, allow the player to specify whether he or she wants to go first or
 * second. If you feel exceptionally ambitious, develop a program that will play three-
 * dimensional tic-tac-toe on a 4-by-4-by-4 board.
 * 
 */

#ifndef EX_9_15_H
#define EX_9_15_H

#include <iostream>
#include <fstream>
#include <gtest/gtest_prod.h>

#define BOARD_SIZE 3 /* Size of each dimension of the board */

/**
 * @brief Interface for the TicTacToe class.
 * 
 */
class TicTacToe {

    FRIEND_TEST(TwoPlayerSimulatedGame, TieGame);
    FRIEND_TEST(TwoPlayerSimulatedGame, TieGameAlmostDiagonal);
    FRIEND_TEST(TwoPlayerSimulatedGame, Player1ColumnWinner);
    FRIEND_TEST(TwoPlayerSimulatedGame, Player2ColumnWinner);
    FRIEND_TEST(TwoPlayerSimulatedGame, Player1RowWinner);
    FRIEND_TEST(TwoPlayerSimulatedGame, Player2RowWinner);
    FRIEND_TEST(TwoPlayerSimulatedGame, Player1PositiveDiagonalWinner);
    FRIEND_TEST(TwoPlayerSimulatedGame, Player2PositiveDiagonalWinner);
    FRIEND_TEST(TwoPlayerSimulatedGame, Player1NegativeDiagonalWinner);
    FRIEND_TEST(TwoPlayerSimulatedGame, Player2NegativeDiagonalWinner);

    public:

        TicTacToe();
        ~TicTacToe();
        void start(void);

    private:

        TicTacToe(const char *);

        enum m_ePlayer : uint8_t {
            NO_PLAYER,  
            PLAYER_1,
            PLAYER_2,
            TIE_GAME
        };

        void _getNumberOfPlayers(void);
        void _printGreeting(void) const;
        void _getPlayerOrder(void);
        int _findWinner(void) const;
        bool _movesLeft(void) const;
        void _printBoard(void) const;
        void _printGameStatus(void) const;
        bool _isValidSelection(uint8_t) const;
        void _makeSelection(uint8_t);
        int _makeSelectionComputer();
        int minimax(int, bool);
       
        uint8_t m_pBoard[BOARD_SIZE][BOARD_SIZE] = {m_ePlayer::NO_PLAYER};
        uint8_t m_uiTurnNum{0};
        uint8_t m_uiNumPlayers{m_ePlayer::NO_PLAYER};
        uint8_t m_uiCurrentPlayer{m_ePlayer::PLAYER_1};
        uint8_t m_uiGameStatus{m_ePlayer::NO_PLAYER};
        bool m_bIsComputerTurn{false};
        const char *m_pStrFileName{nullptr};
        std::fstream m_fileStream;
};

#endif