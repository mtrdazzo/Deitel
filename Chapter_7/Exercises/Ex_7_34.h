#ifndef EX_7_34_H
#define EX_7_34_H

#include <iostream>
#include <array>

#define ARRAY_SIZE 40

typedef std::array<std::array<uint8_t, ARRAY_SIZE>, ARRAY_SIZE> t_maze;

/* function prototypes */
void createMaze(t_maze&, size_t, size_t, size_t, size_t);
void createBorders(t_maze&, const size_t, const size_t);
void printMaze(const t_maze&);
size_t getRandomIndex(const size_t, const size_t);
void createHorizontalWall(t_maze &, const size_t, const size_t, const size_t);
void createVerticalWall(t_maze &, const size_t, const size_t, const size_t);
bool verticalWallSpaceAvail(const t_maze &maze, const size_t min_row, const size_t max_row, const size_t min_col, const size_t max_col);
bool horizontalWallSpaceAvail(const t_maze &maze, const size_t min_row, const size_t max_row, const size_t min_col, const size_t max_col);

#endif /* EX_7_34_H */