#ifndef _EX_7_24_H
#define _EX_7_24_H

#define BOARD_SIZE 0x08

typedef std::array<std::array<int8_t, BOARD_SIZE>, BOARD_SIZE> t_board;
typedef std::array<uint8_t, BOARD_SIZE> t_boardDimension;

void initSquareValues(t_board &);
void printBoard(const t_board &);
bool isOnBoard(const uint8_t, const uint8_t);
t_board eightQueens(const uint8_t, const uint8_t);
void placeQueen(const uint8_t, const uint8_t, t_board&);
void updateBoard(t_board&);
bool findSmallestValue(uint8_t *, uint8_t *, t_board&);

#endif /* EX_7_24_H */