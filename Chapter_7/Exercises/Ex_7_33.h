#ifndef _EX_7_33_H
#define _EX_7_33_H

#include <Ex_7_34.h>
#include <array>

/* current location structure */
struct s_location {
    char row;
    char column;
};

/* current direction enum */
enum class Direction : const int {
    NORTH = 0,
    EAST,
    SOUTH,
    WEST,
    NUM_DIRECTIONS
};

/* Moves for NORTH, EAST, SOUTH, WEST */
typedef const std::array<int, (int)Direction::NUM_DIRECTIONS> t_aMoveTypes;

/* Function prototypes */
void mazeTraverse(t_maze&, s_location&);
void printLocationInMaze(const t_maze&, const s_location&);
bool exitedMaze(const s_location&);
bool moveNumberDegrees(const t_maze&, s_location&, Direction&);
bool move270Degrees(const t_maze&, s_location&, Direction&);
bool move90Degrees(const t_maze&, s_location&, Direction&);
bool moveCurrentDirection(const t_maze&, s_location&, Direction&);
Direction rotate90Degrees(const Direction);
s_location findStartingPosition(const t_maze&);

#endif /* _EX_7_33_H */