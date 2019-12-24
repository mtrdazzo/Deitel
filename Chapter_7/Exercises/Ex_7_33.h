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

#endif /* _EX_7_33_H */