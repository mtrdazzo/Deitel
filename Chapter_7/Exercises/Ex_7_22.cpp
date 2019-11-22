/*
 * Exercise 7-22 Knight's Tour
 *
 * Write a program to move the knight around an empty chessboard and touch each of
 * the 64 squares once and only once.
 *
 */

#include <iostream>
#include <array>
#include <iomanip>
#include "Ex_7_22.h"

/* arrays of possible move combinations by a knight */
t_move vertical{2,1,-1,-2,-2,-1,1,2};
t_move horizontal{-1,-2,-2,-1,1,2,2,1};

/**
 * Move the knight around the chess board.
 *
 * Moves a knight starting at currentRow and currentColumn around the chess board
 * touching each of the 64 squares once and only once.
 *
 * @param currentRow    Starting row on chess board [1,8]
 * @param currentColumn Starting column on chess board [1,8]
 * @return 8 x 8 array of knight's moves from 1 to 64 at each position on the chess boards
 */
t_board knightsTour(uint8_t currentRow, uint8_t currentColumn) {

    uint8_t moveNumber{1};
    uint8_t newRow;
    uint8_t newColumn;
    int8_t lowestAvailability;
    int8_t lowestIndex;
    t_board chess_board{0};
    t_board availability{0};

    /* starting row or column out of bounds */
    if (currentRow < 1 || currentRow > NUM_ROWS || currentColumn < 1 || currentColumn > NUM_COLUMNS)
        return chess_board;

    initAvailability(availability);
    /* convert row and column to index values */
    chess_board[--currentRow][--currentColumn] = moveNumber;
    updateAvailability(currentRow, currentColumn, availability);

    while (moveNumber < BOARD_SPACES) {

        lowestAvailability = MAX_AVAILABILITY + 1;
        lowestIndex = -1;

        /* find valid move to space with lowest availability */
        for (size_t move{0}; move < NUM_MOVES; ++move) {
            newRow = currentRow + vertical[move];
            newColumn = currentColumn + horizontal[move];
            if (checkSpace(newRow, newColumn, chess_board) && (availability[newRow][newColumn] < lowestAvailability)) {
                lowestAvailability = availability[newRow][newColumn];
                lowestIndex = move;
            }
        }

        /* move knight to new position, update availability */
        currentRow += vertical[lowestIndex];
        currentColumn += horizontal[lowestIndex];
        chess_board[currentRow][currentColumn] = ++moveNumber;
        updateAvailability(currentRow, currentColumn, availability);
    }
    return chess_board;
}

/**
 * Update the availability of the chess board.
 *
 * After a knight moves to space (row, column) the spcaes which could previously access
 * this spaces must be updated.
 *
 * @param row    Row of knight chess board
 * @param column Column of knight chess board
 * @param avail  2D (8 x 8) array representing the availability of each square on the chess board
 * @return void
 */
void updateAvailability(uint8_t row, uint8_t column, t_board& avail) {

    avail[row][column] = 0;
    uint8_t newRow;
    uint8_t newColumn;
    for(uint8_t index{0}; index < NUM_MOVES; index++) {
        newRow = row + vertical[index];
        newColumn = column + horizontal[index];

        if (onBoard(newRow, newColumn) && avail[newRow][newColumn])
            --avail[newRow][newColumn];
    }
}

/**
 * Initialize the availability of the chess board.
 *
 * Initialize the avialability array of a blank chess board.
 *
 * @param avail  2D (8 x 8) array representing the availability of each square on the chess board
 * @return void
 */
void initAvailability(t_board &avail) {

    for(size_t row{0}; row < NUM_ROWS; row++)
        for(size_t col{0}; col < NUM_COLUMNS; col++)
            for (size_t move{0}; move < NUM_MOVES; move++)
                if (onBoard(row + horizontal[move], col + vertical[move]))
                    ++avail[row + horizontal[move]][col + vertical[move]];
}

/**
 * Print the values of the chess board.
 *
 * Print the values of array of a chess board (availability of knight locations).
 *
 * @param board  2D (8 x 8) array representing a chess board
 * @return void
 */
void printBoard(t_board& board) {
    std::cout << "  ";
    for (int column{0}; column < NUM_COLUMNS; column++)
        std::cout << std::setw(2) << column + 1 << " ";
    std::cout << std::endl;

    for(uint8_t row{0}; row < board.size(); row++) {
        std::cout << static_cast<int>(row+1) << " ";
        for (uint8_t column{0}; column < NUM_ROWS; column++)
            std::cout << std::setw(2) << static_cast<int>(board[row][column]) << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/**
 * Check if (row, column) is a space on the board.
 *
 * @param row    Row array index of the chess board
 * @param column Column array index of the chess board
 * @return true if (row, column) is a valid space on the chess board, otherwise false
 */
bool onBoard(uint8_t row, uint8_t column) {

    return ( row >= 0 && row < NUM_COLUMNS &&
             column >= 0 && column < NUM_ROWS );
}

/**
 * Check if a Knight can be placed at (row, column) on the chess board.
 *
 * @param row    Row array index of the chess board
 * @param column Column array index of the chess board
 * @return true if a knight can be placed at (row, column) on the chess board, otherwise false
 */
bool checkSpace(uint8_t row, uint8_t column, t_board &board) {

    return onBoard(row, column) && !board[row][column];
}