/**
 * Exercise 7-29 Eight Queens
 *
 * Modiy the Eight Queens program you created in Exercise 7.24 to solve the problem
 * recursively.
 *
 */

#include <iostream>
#include <array>
#include "Ex_7_24.h"
#include "Ex_7_29.h"

/**
 * Place up to 8 queens on the chess board (Recursive Edition)
 *
 * Place eight queens on an empty chessboard so that no
 * queen is "attacking" any other, i.e., no two queens are in the same row,
 * the same column, or along the same diagonal.
 *
 * @param r_start Starting row on chess board [1,8]
 * @param c_start Starting column on chess board [1,8]
 * @return 8 x 8 array of knight's moves from 1 to 64 at each position on the chess boards
 */
t_board eightQueensRecursive(uint8_t r_current, uint8_t c_current) {

    static uint8_t queens_placed{0};
    static t_board queen_board{0};
    static t_board square_values{0};

    if (queens_placed == 0){
        /* check initial values */
        if (!isOnBoard(r_current-1, c_current-1))
            return queen_board;

        updateBoard(square_values); /* Initialize board */
        --r_current; /* convert to array index */
        --c_current; /* convert to array index */
    }

    queen_board[r_current][c_current] = ++queens_placed;
    placeQueen(r_current, c_current, square_values);
    updateBoard(square_values);

    if (findSmallestSquare(&r_current, &c_current, square_values))
        return eightQueensRecursive(r_current, c_current);

    return queen_board;
}
