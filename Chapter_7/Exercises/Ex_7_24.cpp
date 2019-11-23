/**
 * Exercise 7-24 Eight Queens
 *
 * Is it possible to place eight queens on an empty chessboard so that no
 * queen is "attacking" any other, i.e., no two queens are in the same row,
 * the same column, or along the same diagonal?
 *
 */

#include <iostream>
#include <array>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include "Ex_7_24.h"

void printBoard(const t_board &board) {
    std::cout << '\n';
    for (uint8_t row{0}; row < BOARD_SIZE; row++) {
        for (uint8_t column{0}; column < BOARD_SIZE; column++)
            std::cout << std::setw(2) << (int)board[row][column] << " ";
        std::cout << std::endl;
    }
}

bool isOnBoard(const uint8_t r, const uint8_t c) {
    return (r >= 0 && r < BOARD_SIZE) &&
           (c >=0 && c < BOARD_SIZE);
}

bool findSmallestSquare(uint8_t *r_small, uint8_t *c_small, t_board& board) {

    uint8_t smallestValue = BOARD_SIZE * BOARD_SIZE;

    for (uint8_t row{0}; row < BOARD_SIZE; row++)
        for (uint8_t column{0}; column < BOARD_SIZE; column++)
            if (board[row][column] > 0 && board[row][column] < smallestValue) {
                *r_small = row;
                *c_small = column;
                smallestValue = board[row][column];
            }

    return smallestValue < BOARD_SIZE * BOARD_SIZE;
}

void flushBoard(t_board& board) {
    for (uint8_t row{0}; row < BOARD_SIZE; row++)
        for (uint8_t column{0}; column < BOARD_SIZE; column++)
            board[row][column] = 0;
}

t_board eightQueens(uint8_t r_start, uint8_t c_start) {

    uint8_t queens_placed{0};
    t_board queen_board{0};
    t_board square_values{0};
    uint8_t r_current{r_start};
    uint8_t c_current{c_start};

    updateBoard(square_values);

    do {

        queen_board[r_current][c_current] = ++queens_placed;
        placeQueen(r_current, c_current, square_values);
        updateBoard(square_values);

    } while (findSmallestSquare(&r_current, &c_current, square_values));

    return queen_board;
}

void placeQueen(const uint8_t row, const uint8_t column, t_board& board) {

    /* Get all spaces in same row */
    for (uint8_t r_vertical{0}; r_vertical < BOARD_SIZE; r_vertical++) {
        board[r_vertical][column] = -1;
    }

    /* Get all spaces in same column */
    for (uint8_t c_horizontal{0}; c_horizontal < BOARD_SIZE; c_horizontal++) {
        board[row][c_horizontal] = -1;
    }

    /* Upper right */
    for(uint8_t row_diag{uint8_t(row-1)}, col_diag{uint8_t(column+1)}; isOnBoard(row_diag, col_diag); row_diag--, col_diag++)
        board[row_diag][col_diag] = -1;

    /* Upper left */
    for(uint8_t row_diag{uint8_t(row-1)}, col_diag{uint8_t(column-1)}; isOnBoard(row_diag, col_diag); row_diag--, col_diag--)
        board[row_diag][col_diag] = -1;

    /* Lower right */
    for(uint8_t row_diag{uint8_t(row+1)}, col_diag{uint8_t(column+1)}; isOnBoard(row_diag, col_diag); row_diag++, col_diag++)
        board[row_diag][col_diag] = -1;

    /* Lower left */
    for(uint8_t row_diag{uint8_t(row+1)}, col_diag{uint8_t(column-1)}; isOnBoard(row_diag, col_diag); row_diag++, col_diag--)
        board[row_diag][col_diag] = -1;
}

void updateBoard(t_board& board) {

    uint8_t space_counter;

    /* Count spaces that are affected by each queen position */
    for (uint8_t row{0}; row < BOARD_SIZE; row++)

        for (uint8_t column{0}; column < BOARD_SIZE; column++) {

            if (board[row][column] < 0)
                continue;

            space_counter = 1;

            /* Get all spaces in same row */
            for (uint8_t r_vertical{0}; r_vertical < BOARD_SIZE; r_vertical++) {
                if (r_vertical == row)
                    continue;
                else if (board[r_vertical][column] >= 0)
                    ++space_counter;
            }

            /* Get all spaces in same column */
            for (uint8_t c_horizontal{0}; c_horizontal < BOARD_SIZE; c_horizontal++) {
                if (c_horizontal == column)
                    continue;
                else if (board[row][c_horizontal] >= 0)
                    ++space_counter;
            }

            /* Upper right */
            for(uint8_t row_diag{uint8_t(row-1)}, col_diag{uint8_t(column+1)}; isOnBoard(row_diag, col_diag); row_diag--, col_diag++)
                if (board[row_diag][col_diag] >= 0)
                    ++space_counter;
            /* Upper left */
            for(uint8_t row_diag{uint8_t(row-1)}, col_diag{uint8_t(column-1)}; isOnBoard(row_diag, col_diag); row_diag--, col_diag--)
                if (board[row_diag][col_diag] >= 0)
                    ++space_counter;
            /* Lower right */
            for(uint8_t row_diag{uint8_t(row+1)}, col_diag{uint8_t(column+1)}; isOnBoard(row_diag, col_diag); row_diag++, col_diag++)
                if (board[row_diag][col_diag] >= 0)
                    ++space_counter;
            /* Lower left */
            for(uint8_t row_diag{uint8_t(row+1)}, col_diag{uint8_t(column-1)}; isOnBoard(row_diag, col_diag); row_diag++, col_diag--)
                if (board[row_diag][col_diag] >= 0)
                    ++space_counter;

            board[row][column] = space_counter;
        }
}