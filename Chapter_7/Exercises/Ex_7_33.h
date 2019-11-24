#ifndef _EX_7_33_H
#define _EX_7_33_H

#include <array>

/* Maze structure */
#define MAZE_SIZE 12
typedef std::array<std::array<char, MAZE_SIZE>, MAZE_SIZE> t_maze;

/* current location structure */
struct s_location {
    char row;
    char column;
};

/* Function prototypes */
void mazeTraverse(t_maze&, s_location&);
void printMaze(const t_maze&, const s_location&);
bool hasExited(const s_location&);
bool inMaze(const s_location&);

#endif /* _EX_7_33_H */