#ifndef _EX_7_22_H
#define _EX_7_22_H

#include <iostream>
#include <array>

/* Function defines */
#define NUM_ROWS         0x08
#define NUM_COLUMNS      0x08
#define NUM_MOVES        0x08
#define MAX_AVAILABILITY 0x08
#define BOARD_SPACES     0x40

typedef std::array<uint8_t, NUM_COLUMNS> t_column;
typedef std::array<t_column, NUM_ROWS> t_board;
typedef std::array<uint8_t, BOARD_SPACES> t_boardSequence;
typedef const std::array<int8_t, NUM_MOVES> t_move;

/* Function Prototypes */
void printBoard(t_board &);
bool onBoard(uint8_t, uint8_t);
bool checkSpace(uint8_t, uint8_t, t_board&);
void initAvailability(t_board &avail);
void updateAvailability(uint8_t, uint8_t, t_board&);
void printAvailability(t_board&);
t_board knightsTour(uint8_t, uint8_t);

#endif /* _EX_7_22_H */