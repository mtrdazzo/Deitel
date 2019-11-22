/*
 * Exercise 7-22 Knight's Tour
 *
 * Write a program to move the knight around the chessboard. Run the program.
 *
 */

#include <iostream>
#include <array>
#include <iomanip>
#include "Ex_7_22.h"

const std::array<int8_t, NUM_MOVES> vertical{2,1,-1,-2,-2,-1,1,2};
const std::array<int8_t, NUM_MOVES> horizontal{-1,-2,-2,-1,1,2,2,1};

/* knightsTour: Run the knight around the chessboard starting at (currentRow, currentColumn) */
t_board knightsTour(uint8_t currentRow, uint8_t currentColumn) {

    uint8_t moveNumber{1};
    uint8_t newRow;
    uint8_t newColumn;
    int8_t lowestAvailability;
    int8_t lowestIndex;
    t_board chess_board{0};
    t_board availability{0};

    initAvailability(availability);
    chess_board[currentRow][currentColumn] = moveNumber;
    updateAvailability(currentRow, currentColumn, availability);

    while (moveNumber < BOARD_SPACES) {

        lowestAvailability = MAX_AVAILABILITY;
        lowestIndex = -1;

        for (size_t move{0}; move < NUM_MOVES; ++move) {
            newRow = currentRow + vertical[move];
            newColumn = currentColumn + horizontal[move];
            if (checkSpace(newRow, newColumn, chess_board) && (availability[newRow][newColumn] < lowestAvailability)) {
                lowestAvailability = availability[newRow][newColumn];
                lowestIndex = move;
            }
        }

        currentRow += vertical[lowestIndex];
        currentColumn += horizontal[lowestIndex];
        chess_board[currentRow][currentColumn] = ++moveNumber;
        updateAvailability(currentRow, currentColumn, availability);
    }
    return chess_board;
}

/* updateAvailability: update availability array */
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

/* initAvailability: initialize availability array */
void initAvailability(t_board &avail) {

    for(size_t row{0}; row < NUM_ROWS; row++)
        for(size_t col{0}; col < NUM_COLUMNS; col++)
            for (size_t move{0}; move < NUM_MOVES; move++)
                if (onBoard(row + horizontal[move], col + vertical[move]))
                    ++avail[row + horizontal[move]][col + vertical[move]];
}

/* printAvailability: print availability board */
void printAvailability(t_board& avail) {
    for(size_t i{0}; i < NUM_ROWS; i++) {
        for(size_t j{0}; j < NUM_COLUMNS; j++)
            std::cout << static_cast<int>(avail[i][j]) << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/* printBoard: print the chess board */
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

/* onBoard: check if space is on the chess board */
bool onBoard(uint8_t row, uint8_t column) {
    return ( row >= 0 && row < NUM_COLUMNS && column >= 0 && column < NUM_ROWS );
}

/* checkSpace: check if chessBoard space at (row, column) is valid */
bool checkSpace(uint8_t row, uint8_t column, t_board &board) {
    return onBoard(row, column) && !board[row][column];
}