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
#include <Ex_7_24.h>

/**
 * Print the values of the chess board.
 *
 * Print the values of array of a chess board (availability or queen locations).
 *
 * @param board  2D (8 x 8) array representing a chess board
 * @return void
 */
void printBoard(const t_board &board) {
    std::cout << '\n';
    for (uint8_t row{0}; row < BOARD_SIZE; row++) {
        for (uint8_t column{0}; column < BOARD_SIZE; column++)
            std::cout << std::setw(2) << (int)board[row][column] << " ";
        std::cout << std::endl;
    }
}

/**
 * Check if (row, column) is a space on the board.
 *
 * @param row    Row array index of the chess board
 * @param column Column array index of the chess board
 * @return true if (row, column) is a queen can be placed on the chess board, otherwise false
 */
bool isOnBoard(const uint8_t r, const uint8_t c) {
    return (r < BOARD_SIZE && c < BOARD_SIZE);
}

/**
 * Find the square that has the smallest effect on the spaces on the board.
 *
 * @param row    Row of knight chess board
 * @param column Column of knight chess board
 * @param board  2D (8 x 8) array representing the availability of each square on the chess board
 * @return void
 */
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

/**
 * Place up to 8 queens on the chess board.
 *
 * Place eight queens on an empty chessboard so that no
 * queen is "attacking" any other, i.e., no two queens are in the same row,
 * the same column, or along the same diagonal.
 *
 * @param r_start Starting row on chess board [1,8]
 * @param c_start Starting column on chess board [1,8]
 * @return 8 x 8 array of knight's moves from 1 to 64 at each position on the chess boards
 */
t_board eightQueens(uint8_t r_start, uint8_t c_start) {

    uint8_t queens_placed{0};
    t_board queen_board{0};
    t_board square_values{0};
    uint8_t r_current{uint8_t(r_start-1)}; /* convert to index */
    uint8_t c_current{uint8_t(c_start-1)}; /* convert to index */

    if (!isOnBoard(r_start, c_start))
        return queen_board;

    updateBoard(square_values);

    do {

        queen_board[r_current][c_current] = ++queens_placed;
        placeQueen(r_current, c_current, square_values);
        updateBoard(square_values);

    } while (findSmallestSquare(&r_current, &c_current, square_values));

    return queen_board;
}

/**
 * Place a queen on the chess board.
 *
 * @param row    Row of queen position chess board
 * @param column Column of queen position chess board
 * @param board  2D (8 x 8) array representing the availability of each square on the chess board
 * @return void
 */
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

/**
 * Update the availability of the chess board.
 *
 * @param board  2D (8 x 8) array representing the availability of each square on the chess board
 * @return void
 */
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
